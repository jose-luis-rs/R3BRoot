/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ------------------------------------------------------------
// -----               R3BTofDMapped2CalPar               -----
// -----    Created 31/03/22 by J.L. Rodriguez-Sanchez    -----
// ------------------------------------------------------------

#include <FairRootManager.h>
#include <FairRuntimeDb.h>
#include <TClonesArray.h>

#include "R3BLogger.h"
#include "R3BTCalEngine.h"
#include "R3BTCalPar.h"
#include "R3BTofDMapped2CalPar.h"
#include "R3BTofdMappedData.h"

R3BTofDMapped2CalPar::R3BTofDMapped2CalPar()
    : R3BTofDMapped2CalPar("R3BTofDMapped2CalPar", 1)
{
}

R3BTofDMapped2CalPar::R3BTofDMapped2CalPar(const char* name, Int_t iVerbose)
    : FairTask(name, iVerbose)
{
}

R3BTofDMapped2CalPar::~R3BTofDMapped2CalPar()
{
    if (fCalPar)
        delete fCalPar;
    if (fEngine)
        delete fEngine;
}

InitStatus R3BTofDMapped2CalPar::Init()
{
    R3BLOG(info, "");
    FairRootManager* rm = FairRootManager::Instance();
    if (!rm)
    {
        R3BLOG(fatal, "FairRootManager not found");
        return kFATAL;
    }

    fMapped = dynamic_cast<TClonesArray*>(rm->GetObject("TofdMapped"));
    if (!fMapped)
    {
        R3BLOG(fatal, "TofdMapped not found");
        return kFATAL;
    }
    fMappedWC = dynamic_cast<TClonesArray*>(rm->GetObject("TofdWalkCorMapped"));
    if (!fMappedWC)
    {
        R3BLOG(warn, "TofdWalkCorMapped not found");
        fMappedWC = NULL;
    }
    fMappedTrigger = dynamic_cast<TClonesArray*>(rm->GetObject("TofdTriggerMapped"));
    if (!fMappedTrigger)
    {
        R3BLOG(warn, "TofdTriggerMapped not found");
        fMappedTrigger = NULL;
    }

    fCalPar = dynamic_cast<R3BTCalPar*>(FairRuntimeDb::instance()->getContainer("TofdTCalPar"));
    if (!fCalPar)
    {
        R3BLOG(error, "Couldn't get handle on TofdTCalPar");
        return kFATAL;
    }

    fEngine = new R3BTCalEngine(fCalPar, fMinStats);

    for (UInt_t d = 0; d < (fNofPlanes + 1); d++)
        for (UInt_t i = 0; i < fPaddlesPerPlane + 4; i++)
            for (UInt_t k = 0; k < fNofPlanes; k++)
            {
                Icount[d][i][k] = 0;
            }

    return kSUCCESS;
}

void R3BTofDMapped2CalPar::Exec(Option_t* option)
{
    Int_t nHits = fMapped->GetEntriesFast();
    // Loop over mapped hits
    for (Int_t i = 0; i < nHits; i++)
    {
        auto mapped = dynamic_cast<R3BTofdMappedData const*>(fMapped->At(i));

        if (mapped->GetDetectorId() > fNofPlanes)
        {
            R3BLOG(error,
                   "More planes than expected! Plane: " << mapped->GetDetectorId() << " allowed are 1.." << fNofPlanes);
            continue;
        }
        if (mapped->GetBarId() > fPaddlesPerPlane)
        {
            R3BLOG(error,
                   "More bars then expected! Det: " << mapped->GetBarId() << " allowed are 1.." << fPaddlesPerPlane);
            continue;
        }

        Int_t edge = mapped->GetSideId() * 2 + mapped->GetEdgeId() - 2; // 1..4
        // std::cout << mapped->GetDetectorId() <<" "<< mapped->GetBarId() << " "<< mapped->GetTimeFine() <<std::endl;
        fEngine->Fill(mapped->GetDetectorId(), mapped->GetBarId(), edge, mapped->GetTimeFine());

        Icount[mapped->GetDetectorId() - 1][mapped->GetBarId() - 1][edge - 1]++;
    }

    if (fMappedWC)
    {
        nHits = fMappedWC->GetEntriesFast();
        // Loop over mapped hits for walk correction
        for (Int_t i = 0; i < nHits; i++)
        {
            auto mapped = dynamic_cast<R3BTofdMappedData const*>(fMappedWC->At(i));

            if (mapped->GetDetectorId() > 2)
            {
                R3BLOG(
                    error,
                    "Walk correction channel found for plane " << mapped->GetDetectorId() << ", allowed are 1 and 2");
                continue;
            }
            if (mapped->GetBarId() != 48)
            {
                R3BLOG(error,
                       "Walk correction channel found for paddle: " << mapped->GetBarId() << " allowed is only bar 48");
                continue;
            }

            Int_t edge = mapped->GetSideId() * 2 + mapped->GetEdgeId() - 2; // 1..4
            fEngine->Fill(mapped->GetDetectorId(), mapped->GetBarId(), edge, mapped->GetTimeFine());

            Icount[mapped->GetDetectorId() - 1][mapped->GetBarId() - 1][edge - 1]++;
        }
    }

    if (fMappedTrigger)
    {
        nHits = fMappedTrigger->GetEntriesFast();
        // Loop over mapped triggers
        for (Int_t i = 0; i < nHits; i++)
        {
            auto mapped = dynamic_cast<R3BTofdMappedData const*>(fMappedTrigger->At(i));

            if (mapped->GetDetectorId() != fNofPlanes + 1)
            {
                R3BLOG(error,
                       "Trigger plane incorrect! Plane: " << mapped->GetDetectorId() << " not " << fNofPlanes + 1);
                continue;
            }
            fEngine->Fill(mapped->GetDetectorId(), mapped->GetBarId(), 1, mapped->GetTimeFine());
            Icount[mapped->GetDetectorId() - 1][mapped->GetBarId() - 1][0]++;
        }
    }
}

void R3BTofDMapped2CalPar::FinishTask()
{
    fEngine->CalculateParamVFTX();
    fCalPar->setChanged();
    fCalPar->printParams();

    R3BLOG(info, "Calibration of TofD detector");
    for (Int_t p = 0; p < (fNofPlanes + 1); p++)
        for (Int_t i = 0; i < fPaddlesPerPlane + 4; i++)
            for (Int_t k = 0; k < fNofPlanes; k++)
                if (Icount[p][i][k] > fMinStats)
                {
                    if (p < fNofPlanes && i < fPaddlesPerPlane)
                    {
                        R3BLOG(info,
                               "Plane: " << p + 1 << ", paddle: " << i + 1 << ", side: " << k + 1
                                         << ", Count: " << Icount[p][i][k]);
                    }
                    else if (p < fNofPlanes && i > fPaddlesPerPlane)
                    {
                        R3BLOG(info,
                               "Walk correction, plane: " << p + 1 << ", paddle: " << i + 1 << ", side: " << k + 1
                                                          << ", Count: " << Icount[p][i][k]);
                    }
                    else
                    {
                        R3BLOG(info,
                               "Trigger plane: " << p + 1 << ", paddle: " << i + 1 << ", side: " << k + 1
                                                 << ", Count: " << Icount[p][i][k]);
                    }
                }
}

void R3BTofDMapped2CalPar::SetUpdateRate(Int_t rate) { fUpdateRate = rate; }

void R3BTofDMapped2CalPar::SetMinStats(Int_t minStats) { fMinStats = minStats; }

void R3BTofDMapped2CalPar::SetNofModules(Int_t nDets, Int_t nCh)
{
    fNofPlanes = nDets;
    fPaddlesPerPlane = nCh;
}

ClassImp(R3BTofDMapped2CalPar)
