/******************************************************************************
 *   Copyright (C) 2026 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2026 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairVolume.h"

#include "NTOFPpacs.h"
#include "NTOFPpacsPoint.h"
#include "R3BLogger.h"
#include "R3BMCStack.h"

#include "TClonesArray.h"
#include "TGeoManager.h"
#include "TVirtualMC.h"

NTOFPpacs::NTOFPpacs()
    : NTOFPpacs("")
{
}

NTOFPpacs::NTOFPpacs(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot)
    : NTOFPpacs(geoFile, { trans, rot })
{
}

NTOFPpacs::NTOFPpacs(const TString& geoFile, const TGeoCombiTrans& combi)
    : R3BDetector("NTOFPpacs", kTRA, geoFile, combi)
    , fPpacPoint(new TClonesArray("NTOFPpacsPoint"))
{
    ResetParameters();
}

NTOFPpacs::~NTOFPpacs()
{
    R3BLOG(debug1, "");
    if (fPpacPoint)
    {
        fPpacPoint->Delete();
        delete fPpacPoint;
    }
}

void NTOFPpacs::Initialize()
{
    FairDetector::Initialize();

    R3BLOG(info, " ");
    R3BLOG(debug, "Sens. Vol. (McId) " << TVirtualMC::GetMC()->VolId("Ppac_gas_"));
}

// -----   Public method ProcessHits  --------------------------------------
Bool_t NTOFPpacs::ProcessHits(FairVolume*)
{
    if (TVirtualMC::GetMC()->IsTrackEntering())
    {
        fELoss = 0.;
        fTime = TVirtualMC::GetMC()->TrackTime() * 1.0e09;
        fLength = TVirtualMC::GetMC()->TrackLength();
        TVirtualMC::GetMC()->TrackPosition(fPosIn);
        TVirtualMC::GetMC()->TrackMomentum(fMomIn);
    }

    // Sum energy loss for all steps in the active volume
    fELoss += TVirtualMC::GetMC()->Edep();

    // Set additional parameters at exit of active volume. Create NTOFPpacsPoint.
    if (TVirtualMC::GetMC()->IsTrackExiting() || TVirtualMC::GetMC()->IsTrackStop() ||
        TVirtualMC::GetMC()->IsTrackDisappeared())
    {
        fTrackID = TVirtualMC::GetMC()->GetStack()->GetCurrentTrackNumber();
        R3BLOG(debug, TVirtualMC::GetMC()->CurrentVolPath());

        TVirtualMC::GetMC()->TrackPosition(fPosOut);
        TVirtualMC::GetMC()->TrackMomentum(fMomOut);
        if (fELoss == 0.)
        {
            return kFALSE;
        }

        // TODO: fPpacID and fVolGasID need implementation!

        AddHit(fTrackID,
               fPpacID,
               fVolGasID,
               TVector3(fPosIn.X(), fPosIn.Y(), fPosIn.Z()),
               TVector3(fPosOut.X(), fPosOut.Y(), fPosOut.Z()),
               TVector3(fMomIn.Px(), fMomIn.Py(), fMomIn.Pz()),
               TVector3(fMomOut.Px(), fMomOut.Py(), fMomOut.Pz()),
               fTime,
               fLength,
               fELoss,
               TVirtualMC::GetMC()->TrackPid());

        // Increment number of AlpidePoints for this track
        auto* stack = static_cast<R3BStack*>(TVirtualMC::GetMC()->GetStack());
        stack->AddPoint(kTRA);
        ResetParameters();
    }

    return kTRUE;
}

// -----   Public method EndOfEvent   -----------------------------------------
void NTOFPpacs::EndOfEvent()
{
    if (fVerboseLevel)
    {
        Print();
    }
    Reset();
}
// ----------------------------------------------------------------------------

// -----   Public method Register   -------------------------------------------
void NTOFPpacs::Register() { FairRootManager::Instance()->Register("PpacPoint", GetName(), fPpacPoint, kTRUE); }
// ----------------------------------------------------------------------------

// -----   Public method GetCollection   --------------------------------------
TClonesArray* NTOFPpacs::GetCollection(Int_t iColl) const
{
    if (iColl == 0)
    {
        return fPpacPoint;
    }
    else
    {
        return nullptr;
    }
}
// ----------------------------------------------------------------------------

// -----   Public method Print   ----------------------------------------------
void NTOFPpacs::Print(Option_t*) const
{
    auto nHits = fPpacPoint->GetEntriesFast();
    R3BLOG(info, nHits << " points registered in this event");
}

// -----   Public method Reset   ----------------------------------------------
void NTOFPpacs::Reset()
{
    fPpacPoint->Clear();
    ResetParameters();
}

// -----   Private method AddHit   --------------------------------------------
NTOFPpacsPoint* NTOFPpacs::AddHit(int trackID,
                                  int ppacID,
                                  int gasPpacID,
                                  TVector3 posIn,
                                  TVector3 posOut,
                                  TVector3 momIn,
                                  TVector3 momOut,
                                  double time,
                                  double length,
                                  double eLoss,
                                  int pdgcode)
{
    TClonesArray& clref = *fPpacPoint;
    auto size = clref.GetEntriesFast();
    return new (clref[size])
        NTOFPpacsPoint(trackID, ppacID, gasPpacID, posIn, posOut, momIn, momOut, time, length, eLoss, pdgcode);
}

// -----   Public method CheckIfSensitive   -----------------------------------
Bool_t NTOFPpacs::CheckIfSensitive(std::string name)
{
    if (TString(name).Contains("Ppac_gas_"))
    {
        LOG(debug) << "Found geometry from ROOT file: " << name;
        return kTRUE;
    }
    return kFALSE;
}

ClassImp(NTOFPpacs)
