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

#include <FairRootManager.h>
#include <FairVolume.h>
#include <FairGeoBuilder.h>
#include <FairGeoInterface.h>
#include <FairGeoLoader.h>
#include <FairGeoMedia.h>

#include <TClonesArray.h>
#include <TGeoManager.h>
#include <TVirtualMC.h>
#include <stdlib.h>
#include <TString.h>
#include <boost/regex.hpp>
#include <TGeoBBox.h>
#include <TGeoManager.h>
#include <TGeoVolume.h>
#include "TROOT.h"

#include "R3BDummyDetector.h"
#include "R3BTofdPoint.h"
#include "R3BLogger.h"
#include "R3BMCStack.h"

R3BDummyDetector::R3BDummyDetector()
    : R3BDummyDetector("")
{
}

R3BDummyDetector::R3BDummyDetector(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot)
    : R3BDummyDetector(geoFile, { trans, rot })
{
}

R3BDummyDetector::R3BDummyDetector(const TString& geoFile, const TGeoCombiTrans& combi)
    : R3BDetector("R3BDummyDetector", kTOFD, geoFile, combi)
    , fCollection(new TClonesArray("R3BTofdPoint"))
    , fCombi(combi)
{
    ResetParameters();
}

R3BDummyDetector::~R3BDummyDetector()
{
    if (fCollection)
    {
        fCollection->Delete();
        delete fCollection;
    }
}

void R3BDummyDetector::Initialize()
{
    FairDetector::Initialize();

    R3BLOG(info, "");
    R3BLOG(debug, "Vol (McId) def " << gMC->VolId("Paddle"));

    return;
}

// -----   Public method ProcessHits  --------------------------------------
Bool_t R3BDummyDetector::ProcessHits(FairVolume* vol)
{
    if (TVirtualMC::GetMC()->IsTrackEntering())
    {
        fELoss = 0.;
        fTime_in = TVirtualMC::GetMC()->TrackTime() * 1.0e09;
        fLength_in = TVirtualMC::GetMC()->TrackLength();
        TVirtualMC::GetMC()->TrackPosition(fPosIn);
        TVirtualMC::GetMC()->TrackMomentum(fMomIn);
    }

    // Sum energy loss for all steps in the active volume
    fELoss += TVirtualMC::GetMC()->Edep();
    
    // Charge and mass are now obtained from PDG Code
    Double_t fZ_in = int(gMC->TrackPid() / 10000) - 100000.;
    Double_t fA_in = 0.1 * (gMC->TrackPid() - (100000 + fZ_in) * 10000.);

    // Set additional parameters at exit of active volume. Create R3BDummyDetectorPoint.
    if (TVirtualMC::GetMC()->IsTrackExiting() || TVirtualMC::GetMC()->IsTrackStop() ||
        TVirtualMC::GetMC()->IsTrackDisappeared())
    {
        fTrackID = gMC->GetStack()->GetCurrentTrackNumber();
        static auto restr = "Plane_([0-9]+).*Paddle_([0-9]+)";
        static auto re = boost::regex(restr, boost::regex::extended);
        boost::cmatch m;
        if (!boost::regex_search(gMC->CurrentVolPath(), m, re))
        {
            R3BLOG(error, gMC->CurrentVolPath() << " does not match RE " << restr);
        }
        fPlaneID = std::stoi(m[1].str());
        fPaddleID = vol->getCopyNo();
        
        gMC->TrackPosition(fPosOut);
        gMC->TrackMomentum(fMomOut);
        if (fELoss == 0.)
        {
            return kFALSE;
        }

        fTime_out =
            TVirtualMC::GetMC()->TrackTime() * 1.0e09; // also in case particle is stopped in detector, or decays...
        fLength_out = TVirtualMC::GetMC()->TrackLength();
        fTime = (fTime_out + fTime_in) / 2.;
        fLength = (fLength_out + fLength_in) / 2.;

        AddHit(fTrackID,
               1,
               fPlaneID,
               fPaddleID,
               TVector3(fPosIn.X(), fPosIn.Y(), fPosIn.Z()),
               TVector3(fPosOut.X(), fPosOut.Y(), fPosOut.Z()),
               TVector3(fMomIn.Px(), fMomIn.Py(), fMomIn.Pz()),
               TVector3(fMomOut.Px(), fMomOut.Py(), fMomOut.Pz()),
               fTime,
               fLength,
               fELoss,
               fZ_in,
               fA_in);
        // Increment number of PspPoints for this track
        auto* stack = static_cast<R3BStack*>(TVirtualMC::GetMC()->GetStack());
        stack->AddPoint(kTOFD);
        ResetParameters();
    }

    return kTRUE;
}

// -----   Public method EndOfEvent   -----------------------------------------
void R3BDummyDetector::EndOfEvent()
{
    if (fVerboseLevel)
    {
        Print();
    }
    Reset();
}

// -----   Public method Register   -------------------------------------------
void R3BDummyDetector::Register() { FairRootManager::Instance()->Register("ActafPoint", GetName(), fCollection, kTRUE); }

// -----   Public method GetCollection   --------------------------------------
TClonesArray* R3BDummyDetector::GetCollection(Int_t iColl) const
{
    if (iColl == 0)
    {
        return fCollection;
    }
    else
    {
        return nullptr;
    }
}

// -----   Public method Print   ----------------------------------------------
void R3BDummyDetector::Print(Option_t* option) const
{
    Int_t nHits = fCollection->GetEntriesFast();
    R3BLOG(info, nHits << " points registered in this event");
}

// -----   Public method Reset   ----------------------------------------------
void R3BDummyDetector::Reset()
{
    fCollection->Clear();
    ResetParameters();
}

// -----   Private method AddHit   --------------------------------------------
R3BTofdPoint* R3BDummyDetector::AddHit(Int_t trackID,
                              Int_t detID,
                              Int_t planeID,
                              Int_t paddleID,
                              TVector3 posIn,
                              TVector3 posOut,
                              TVector3 momIn,
                              TVector3 momOut,
                              Double_t time,
                              Double_t length,
                              Double_t eLoss,
                              Double_t Z,
                              Double_t A)
{
    TClonesArray& clref = *fCollection;
    auto size = clref.GetEntriesFast();
    if (fVerboseLevel > 1)
    {
        R3BLOG(info,
               "at (" << posIn.X() << ", " << posIn.Y() << ", " << posIn.Z() << ") cm,  detector " << detID
                      << ", track " << trackID << ", energy loss " << eLoss * 1e06 << " keV");
    }
    return new (clref[size])
        R3BTofdPoint(trackID, detID, planeID, paddleID, posIn, posOut, momIn, momOut, time, length, eLoss, Z, A);
}

Bool_t R3BDummyDetector::CheckIfSensitive(std::string name)
{
    if (TString(name).Contains("Paddle"))
    {
        LOG(debug) << "Found Dummy geometry from ROOT file: " << name;
        return kTRUE;
    }
    return kFALSE;
}

void R3BDummyDetector::ConstructGeometry()
{
    R3BLOG(info, "");

    auto* geoLoad = FairGeoLoader::Instance();
    auto* geoFace = geoLoad->getGeoInterface();
    auto* geoMedia = geoFace->getMedia();
    auto* geoBuild = geoLoad->getGeoBuilder();

    auto fairMedium = geoMedia->getMedium("vacuum");
    R3BLOG_IF(fatal, !fairMedium, "FairGeoMedium vacuum not found");
    geoBuild->createMedium(fairMedium);

    auto med = gGeoManager->GetMedium("vacuum");
    R3BLOG_IF(fatal, !med, "TGeoMedium vacuum not found");

 /*   double dx = 500.; // 5 m
    double dy = 100.;   // 1 m
    double dz = 1.; // 1 cm

    auto* floor = gGeoManager->MakeBox("DummyWorld", med, dx / 2., dy / 2., dz / 2.);
    floor->SetLineColor(4);

    double yPos = -200. - dy / 2.;
    double zPos = 600.;

    auto* top = gGeoManager->GetTopVolume();
    top->AddNode(floor, 1, new TGeoTranslation(0., yPos, zPos));*/
    
    auto fRefRot = new TGeoRotation();
    
        // --------------   Create geometry and top volume  -------------------------

    // Top Volume
    auto pWorld = gGeoManager->GetTopVolume();
    pWorld->SetVisLeaves(kTRUE);

    // Detector specifications
    const size_t n_planes = 4;
    const size_t n_paddles = 44;

    // Paddle dimensions in cm
    const float dx = 2.7;
    const float dy = 100.0;
    const float dz = 0.5;

    // Positions (for each paddle)
    float x = 0.0, y = 0.0, z = 0.0;
    float shift = 0.0;
    const float air_gap_paddles = 0.04;
    const float air_gap_planes = 3.0;

    // Plane definition
    auto Plane = gGeoManager->MakeBox(
        "Plane", med, dx / 2. * n_paddles + dx / 4. + (n_paddles - 1) * air_gap_paddles / 2., dy / 2., dz / 2.);
    Plane->SetLineColor(1);

    auto detector_width = n_paddles * dx + (n_paddles - 1) * air_gap_paddles;
    auto tofd = new TGeoVolumeAssembly("TOFD");

    auto Paddle = gGeoManager->MakeBox("Paddle", med, dx / 2., dy / 2., dz / 2.);
    Paddle->SetVisLeaves(kTRUE);
    Paddle->SetLineColor(kBlue);

    for (size_t n = 0; n < n_paddles; n++)
    {
        x = -detector_width / 2 + dx / 2 + n * (dx + air_gap_paddles);

        auto pMatrix = new TGeoCombiTrans("", x, y, z, fRefRot);
        pMatrix->RegisterYourself();
        Plane->AddNode(Paddle, n + 1, pMatrix);
    }

    for (size_t m = 0; m < n_planes; m++)
    {
        shift = (m % 2 == 0) ? -dx / 4. : dx / 4.;

        auto z_plane = -dz * n_planes / 2 - (n_planes - 1) * air_gap_planes / 2 + dz / 2 + m * (dz + air_gap_planes) +
                       (m > 1 ? 1.5 : -1.5);
        auto pMatrix_planes = new TGeoCombiTrans("", shift, y, z_plane, fRefRot);
        pMatrix_planes->RegisterYourself();
        tofd->AddNode(Plane, m + 1, pMatrix_planes);
    }

    pWorld->AddNode(tofd, 1, &fCombi);
}

ClassImp(R3BDummyDetector)
