/******************************************************************************
 *   Copyright (C) 2025 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2025 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// ----------------------------------------------------------------
// -----                R3BEventFilter                        -----
// -----     Created 05/10/25 by J.L. Rodriguez-Sanchez       -----
// ----------------------------------------------------------------

/*
 * This class selects which events should be stored in the ROOT file.
 * It acts as a filter, deciding whether an event is kept or discarded.
 */

#include "FairRunOnline.h"
#include <FairLogger.h>
#include <FairRootManager.h>
#include <FairRunAna.h>
#include <FairRuntimeDb.h>

#include "R3BEventFilter.h"
#include "R3BEventHeader.h"
#include "R3BFrsData.h"
#include "R3BLogger.h"
#include "R3BTofdHitData.h"

#include <TClonesArray.h>
#include <TMath.h>

R3BEventFilter::R3BEventFilter()
    : R3BEventFilter("R3BEventFilter", 1)
{
}

R3BEventFilter::R3BEventFilter(const TString& name, Int_t iVerbose)
    : FairTask(name, iVerbose)
{
}

void R3BEventFilter::SetParContainers()
{
    R3BLOG(info, "");
    // Reading IncomingIDPar from FairRuntimeDb
    auto rtdb = FairRuntimeDb::instance();
    R3BLOG_IF(fatal, !rtdb, "FairRuntimeDb not found");

    return;
}

void R3BEventFilter::SetParameter()
{
    //--- Parameter Containers ---
    return;
}

InitStatus R3BEventFilter::Init()
{
    R3BLOG(info, "");

    auto mgr = FairRootManager::Instance();
    R3BLOG_IF(fatal, nullptr == mgr, "FairRootManager not found");

    fHeader = dynamic_cast<R3BEventHeader*>(mgr->GetObject("EventHeader."));

    fTofdHit = dynamic_cast<TClonesArray*>(mgr->GetObject("TofdHit"));

    fFrsData = dynamic_cast<TClonesArray*>(mgr->GetObject("FrsData"));

    if (fCutFrsId == nullptr)
    {
        fCutFrsId = new TCutG("fCutFrsId", 5);
        fCutFrsId->SetPoint(0, 0.5, 0.5);
        fCutFrsId->SetPoint(1, 4., 0.5);
        fCutFrsId->SetPoint(2, 4., 4.);
        fCutFrsId->SetPoint(3, 0.5, 4.);
        fCutFrsId->SetPoint(4, 0.5, 0.5);
    }

    SetParameter();
    return kSUCCESS;
}

InitStatus R3BEventFilter::ReInit()
{
    SetParContainers();
    SetParameter();
    return kSUCCESS;
}

void R3BEventFilter::Exec(Option_t*)
{
    bool fValidEvent = false;

    if (fHeader->GetExpId() == 249)
    {
        if (fFrsData != nullptr && fFrsData->GetEntriesFast() > 0 && fCutFrsId != nullptr)
        {
            auto nHits = fFrsData->GetEntriesFast();
            for (size_t ihit = 0; ihit < nHits; ihit++)
            {
                auto frsdata = dynamic_cast<R3BFrsData*>(fFrsData->At(ihit));
                auto charge = frsdata->GetZ();
                auto aoq = frsdata->GetAq();
                if (fCutFrsId->IsInside(charge, aoq))
                {
                    fValidEvent = true;
                }
            }
        }

        if (fTofdHit != nullptr && fTofdHit->GetEntriesFast() > 0 && fValidEvent)
        {
            auto nHits = fTofdHit->GetEntriesFast();
            for (size_t ihit = 0; ihit < nHits; ihit++)
            {
                auto tofdhit = dynamic_cast<R3BTofdHitData*>(fTofdHit->At(ihit));
                auto plane = tofdhit->GetDetId();
                auto bar = tofdhit->GetBarId();
                auto charge = tofdhit->GetChargeZ();
                if (charge > 1) // FIXME
                {
                    fValidEvent = true;
                }
            }
        }
    }
    else
    {
        R3BLOG(fatal, "Unknown experiment ID: event filter not yet implemented");
    }
    StoreEvent(fValidEvent);
}

void R3BEventFilter::FinishEvent()
{
    if (fFrsData)
    {
        fFrsData->Clear();
    }
}

void StoreEvent(bool valid)
{
    if (valid)
    {
        FairRunOnline::Instance()->MarkFill(kTRUE);
    }
    else
    {
        FairRunOnline::Instance()->MarkFill(kFALSE);
    }
}

ClassImp(R3BEventFilter)
