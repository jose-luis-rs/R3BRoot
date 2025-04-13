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

#include <vector>

#include <FairTask.h>

class TClonesArray;
class R3BTofDMappingPar;
class R3BTCalPar;
class R3BTofdMappedData;
class R3BTofdCalData;
class R3BEventHeader;

class R3BTofDMapped2Cal : public FairTask
{
  public:
    /**
     * Default constructor.
     * Creates an instance of the task with default parameters.
     */
    R3BTofDMapped2Cal();

    /**
     * Standard constructor.
     * Creates an instance of the task.
     * @param name a name of the task.
     * @param iVerbose a verbosity level.
     */
    R3BTofDMapped2Cal(const TString& name, Int_t = 1);

    /**
     * Destructor.
     * Frees the memory used by the object.
     */
    virtual ~R3BTofDMapped2Cal();

    /**
     * Method for task initialization.
     * This function is called by the framework before
     * the event loop.
     * @return Initialization status. kSUCCESS, kERROR or kFATAL.
     */
    InitStatus Init() override;

    /**
     * Method for initialization of the parameter containers.
     * Called by the framework prior to Init() method.
     */
    void SetParContainers() override;

    /**
     * Method for re-initialization of parameter containers
     * in case the Run ID has changed.
     */
    InitStatus ReInit() override;

    /**
     * Method for event loop implementation.
     * Is called by the framework every time a new event is read.
     * @param option an execution option.
     */
    void Exec(Option_t*) override;

    /**
     * A method for finish of processing of an event.
     * Is called by the framework for each event after executing
     * the tasks.
     */
    void FinishEvent() override;

    /**
     * Method for setting the trigger value.
     * @param trigger 1 - onspill, 2 - offspill, -1 - all events.
     */
    inline void SetTrigger(Int_t trigger) { fTrigger = trigger; }

    /**
     * Method for setting the number of TofD modules.
     */
    void SetNofModules(Int_t, Int_t);

    // Method to setup online mode
    inline void SetOnline(bool option = true) { fOnline = option; }

  private:
    void SetParameter();
    size_t GetCalLookupIndex(R3BTofdMappedData const&) const;

    R3BTofDMappingPar* fMapPar = nullptr;

    TClonesArray* fMappedItems = nullptr;        /**< Array with mapped items - input data. */
    TClonesArray* fMappedWCItems = nullptr;      /**< Array with mapped items - walk correction */
    TClonesArray* fMappedTriggerItems = nullptr; /**< Array with mapped items - trigger times */
    TClonesArray* fCalItems = nullptr;           /**< Array with cal items - output data. */
    TClonesArray* fCalWCItems = nullptr;         /**< Array with cal items - walk correction */
    TClonesArray* fCalTriggerItems = nullptr;    /**< Array with cal trigger items - output data. */

    R3BTCalPar* fTcalPar = nullptr; /**< TCAL parameter container. */
    UInt_t fNofTcalPars = 0;        /**< Number of modules in parameter file. */

    UInt_t fNofPlanes = 4;
    UInt_t fPaddlesPerPlane = 44; /**< Number of paddles per plane. */
    Double_t fClockFreq;          /**< Clock cycle in [ns]. */
    R3BEventHeader* header;       /**< Event header. */
    Int_t fTrigger = -1;          /**< Trigger value. */
    bool fOnline = false;         // Don't store data for online

    // Fast lookup for matching mapped data.
    std::vector<std::vector<R3BTofdCalData*>> fCalLookup;

    R3BTofdCalData* AddTCalData(UInt_t detid, UInt_t barid, UInt_t sideid, Double_t lead_time, Double_t trail_time);

    R3BTofdCalData* AddWCTCalData(UInt_t detid, UInt_t barid, Double_t lead_time);

    R3BTofdCalData* AddTriggerTCalData(UInt_t detid, UInt_t barid, Double_t lead_time);

  public:
    ClassDefOverride(R3BTofDMapped2Cal, 1)
};
