#include "R3BNeulandTacquilaMapped2CalPar.h"
#include "FairLogger.h"
#include "FairRootManager.h"
#include "FairRtdbRun.h"
#include "FairRunIdGenerator.h"
#include "FairRuntimeDb.h"
#include "R3BEventHeader.h"
#include "R3BNeulandTacquilaMappedData.h"
#include "R3BTCalEngine.h"
#include "R3BTCalPar.h"
#include "TClonesArray.h"
#include "TF1.h"
#include "TH1F.h"
#include <stdlib.h>

R3BNeulandTacquilaMapped2CalPar::R3BNeulandTacquilaMapped2CalPar()
    : fUpdateRate(1000000)
    , fMinStats(100000)
    , fTrigger(-1)
    , fNofPMTs(0)
    , fNEvents(0)
    , fCal_Par(NULL)
{
}

R3BNeulandTacquilaMapped2CalPar::R3BNeulandTacquilaMapped2CalPar(const char* name, Int_t iVerbose)
    : FairTask(name, iVerbose)
    , fUpdateRate(1000000)
    , fMinStats(100000)
    , fTrigger(-1)
    , fNofPMTs(0)
    , fNEvents(0)
    , fCal_Par(NULL)
{
}

R3BNeulandTacquilaMapped2CalPar::~R3BNeulandTacquilaMapped2CalPar()
{
    if (fCal_Par)
    {
        delete fCal_Par;
    }
    if (fEngine)
    {
        delete fEngine;
    }
}

InitStatus R3BNeulandTacquilaMapped2CalPar::Init()
{
    FairRootManager* rm = FairRootManager::Instance();
    if (!rm)
    {
        return kFATAL;
    }
    header = (R3BEventHeader*)rm->GetObject("R3BEventHeader");
    if (!header)
    {
        return kFATAL;
    }
    fHits = (TClonesArray*)rm->GetObject("NeulandTacquilaMappedData");
    if (!fHits)
    {
        return kFATAL;
    }

    fCal_Par = (R3BTCalPar*)FairRuntimeDb::instance()->getContainer("LandTCalPar");
    fCal_Par->setChanged();

    fEngine = new R3BTCalEngine(fCal_Par, fMinStats);

    return kSUCCESS;
}

void R3BNeulandTacquilaMapped2CalPar::Exec(Option_t* option)
{
    if (fTrigger >= 0)
    {
        if (header->GetTrigger() != fTrigger)
        {
            return;
        }
    }

    Int_t nHits = fHits->GetEntries();
    if (nHits > (fNofPMTs / 2))
    {
        return;
    }

    R3BNeulandTacquilaMappedData* hit;
    Int_t iPlane;
    Int_t iPaddle;
    Int_t iSide;

    // Loop over mapped hits
    for (Int_t i = 0; i < nHits; i++)
    {
        hit = (R3BNeulandTacquilaMappedData*)fHits->At(i);
        if (!hit)
        {
            continue;
        }

        // Check bar ID
        iPlane = hit->GetPlane();
        iPaddle = hit->GetPaddle();
        iSide = hit->GetSide();

        // Fill TAC histogram
        fEngine->Fill(iPlane, iPaddle, iSide, hit->GetTacData());
        fEngine->Fill(iPlane, iPaddle, iSide + 2, hit->GetStopT());
    }

    // Increment events
    fNEvents += 1;
}

void R3BNeulandTacquilaMapped2CalPar::FinishEvent() {}

void R3BNeulandTacquilaMapped2CalPar::FinishTask() { fEngine->CalculateParamTacquila(); }

ClassImp(R3BNeulandTacquilaMapped2CalPar)
