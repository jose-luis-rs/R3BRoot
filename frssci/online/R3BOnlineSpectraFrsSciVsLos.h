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

#pragma once

#include "FairTask.h"
#include "TCanvas.h"
#include "TH2.h"

class TClonesArray;
class R3BEventHeader;
class R3BIncomingIDPar;
class R3BFrsSciCalPar;

/**
 * This taks reads SCI data and plots online histograms
 */
class R3BOnlineSpectraFrsSciVsLos : public FairTask
{
  public:
    /**
     * Default constructor.
     * Creates an instance of the task with default parameters.
     */
    R3BOnlineSpectraFrsSciVsLos();

    /**
     * Standard constructor.
     * Creates an instance of the task.
     * @param name a name of the task.
     * @param iVerbose a verbosity level.
     */
    R3BOnlineSpectraFrsSciVsLos(const char* name, Int_t iVerbose = 1);

    /**
     * Destructor.
     * Frees the memory used by the object.
     */
    virtual ~R3BOnlineSpectraFrsSciVsLos();

    /**
     * Method for task initialization.
     * This function is called by the framework before
     * the event loop.
     * @return Initialization status. kSUCCESS, kERROR or kFATAL.
     */
    virtual InitStatus Init();

    /**
     * Method for event loop implementation.
     * Is called by the framework every time a new event is read.
     * @param option an execution option.
     */
    virtual void Exec(Option_t* option);

    /**
     * A method for finish of processing of an event.
     * Is called by the framework for each event after executing
     * the tasks.
     */
    virtual void FinishEvent();

    /**
     * Method for finish of the task execution.
     * Is called by the framework after processing the event loop.
     */
    virtual void FinishTask();

    /**
     * Methods to clean histograms.
     */
    virtual void Reset_Histo();

    /** Virtual method Reset **/
    virtual void Reset() {}

    virtual void SetParContainers();

    void SetFrsSciNbDets(UShort_t ndets) { fFrsSciNbDets = ndets; }
    void SetFrsSciNbPmts(UShort_t npmts) { fFrsSciNbPmts = npmts; }
    void SetLosNbDets(UShort_t ndets) { fLosNbDets = ndets; }
    void SetPosRawRange_FrsSci1(float min, float max)
    {
        fpos_range_min_FrsSci1 = min;
        fpos_range_max_FrsSci1 = max;
    }
    void SetPosRawRange_FrsSci2(float min, float max)
    {
        ftof_range_min_FrsSci2 = min;
        ftof_range_max_FrsSci2 = max;
    }
    void SetTofRawRange_FrsSci1(float min, float max)
    {
        ftof_range_min_FrsSci1 = min;
        ftof_range_max_FrsSci1 = max;
    }
    void SetTofRawRange_FrsSci2(float min, float max)
    {
        ftof_range_min_FrsSci2 = min;
        ftof_range_max_FrsSci2 = max;
    }
    void SetPosCal_FrsSci1(float gain, float offset)
    {
        fpos_gain_FrsSci1 = gain;
        fpos_offset_FrsSci1 = offset;
    }
    void SetPosCal_FrsSci2(float gain, float offset)
    {
        fpos_gain_FrsSci2 = gain;
        fpos_offset_FrsSci2 = offset;
    }

  private:
    R3BEventHeader* fHeader;      /**< Event header  */
    TClonesArray* fFrsSci_Tcal;   /**< Array with R3BFrsSciTcalData */
    TClonesArray* fFrsSci_PosCal; /**< Array with R3BFrsSciPosCalData */
    TClonesArray* fLos_Tcal;      /**< Array with R3BLosTcalData */
    TClonesArray* fLos_Hit;       /**< Array with R3BLosHitData */

    void SetParameters();
    R3BIncomingIDPar* fIncomingID_Par; // Parameter container
    TArrayF* fTof2InvV_p0;
    TArrayF* fTof2InvV_p1;
    TArrayF* fBrho0_S2toCC;
    TArrayF* fDispersionS2;
    R3BFrsSciCalPar* fCalPar; // cal parameters container - FrsSci
    TArrayF* fPosCal_Gain;
    TArrayF* fPosCal_Offset;
    TArrayF* fpos_range_min;
    TArrayF* fpos_range_max;
    TArrayF* ftof_range_min;
    TArrayF* ftof_range_max;

    Int_t fNEvents; /**< Event counter.     */
    UShort_t fFrsSciNbDets;
    UShort_t fFrsSciNbPmts;
    UShort_t fLosNbDets;
    // FIXME
    Double_t fpos_range_min_FrsSci1;
    Double_t fpos_range_max_FrsSci1;
    Double_t fpos_range_min_FrsSci2;
    Double_t fpos_range_max_FrsSci2;
    Double_t ftof_range_min_FrsSci1;
    Double_t ftof_range_max_FrsSci1;
    Double_t ftof_range_min_FrsSci2;
    Double_t ftof_range_max_FrsSci2;
    Double_t fpos_gain_FrsSci1;
    Double_t fpos_offset_FrsSci1;
    Double_t fpos_gain_FrsSci2;
    Double_t fpos_offset_FrsSci2;

    // Canvas Tof and Pos@S2
    TCanvas** cTcal_TofRaw;
    TCanvas** cTcal_Tstop_vs_Tstart;
    TCanvas* cTcal_multTofRaw;
    TCanvas* cAoQ;
    TCanvas* cAoQ_vs_PosS2;
    TCanvas* cZ_vs_AoQ;
    // TCanvas Los
    TCanvas* cLos_Mult;
    TCanvas* cLos_ToT;

    // Histograms Tof
    TH1D** fh1_Tcal1Hit_TofRaw;               // [fNumFrsSci] START=FrsSci, STOP=LOS
    TH1D** fh1_Tcal1Hit_PosRaw;               // [fNumFrsSci] at START=FrsSci
    TH2D** fh2_Tcal1Hit_Tstop_vs_Tstart_Zgt5; // [fNumFrsSci] at START=FrsSci
    TH1I** fh1_multTofRaw;                    // [fNumFrsSci]
    TH1I** fh1_multTofRaw_Zgt5;               // [fNumFrsSci]
    TH1D** fh1_TofRaw;                        // [fNumFrsSci]
    TH1D** fh1_PosRaw;                        // [fNumFrsSci]
    TH2D** fh2_Tstop_vs_Tstart_Zgt5;          // [fNumFrsSci] at START=FrsSci
    TH1D** fh1_Tcal1Hit_AoQraw;               // [fNumFrsSci] with Brho from FrsSci to Los
    TH1D** fh1_AoQcal;                        // [fNumFrsSci] with Brho from FrsSci to Los
    TH2D** fh2_AoQcal_vs_PosS2;               // [fNumFrsSci] with Brho from FrsSci to Los
    TH2D** fh2_Z_vs_AoQcal;                   // [fNumFrsSci] with Brho from FrsSci to Los

    // Histograms Los
    TH2I** fh2_MultLos_LE;
    TH2I** fh2_MultLos_TE;
    TH1D** fh1_MeanToT;

  public:
    ClassDef(R3BOnlineSpectraFrsSciVsLos, 1)
};
