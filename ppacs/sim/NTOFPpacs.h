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

// ---------------------------------------------------------------
// -----                        NTOFPpacs                    -----
// -----          Created 12/04/2026 by J.L. Rodriguez       -----
// ---------------------------------------------------------------

#pragma once

#include "R3BDetector.h"
#include <Rtypes.h>
#include <TLorentzVector.h>

class TClonesArray;
class NTOFPpacsPoint;
class FairVolume;

class NTOFPpacs : public R3BDetector
{
  public:
    /** Default constructor **/
    NTOFPpacs();

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param trans   position
     *@param rot     rotation
     */
    NTOFPpacs(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot = TGeoRotation());

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param combi   position + rotation
     */
    NTOFPpacs(const TString& geoFile, const TGeoCombiTrans& combi = TGeoCombiTrans());

    /** Destructor **/
    ~NTOFPpacs() override;

    /** method ProcessHits
     **
     ** Defines the action to be taken when a step is inside the
     ** active volume. Creates a NTOFPpacsPoint and adds it to the
     ** collection.
     *@param vol  Pointer to the active volume
     **/
    Bool_t ProcessHits(FairVolume*) override;

    Bool_t CheckIfSensitive(std::string name) override;

    /** method EndOfEvent
     **
     ** If verbosity level is set, print hit collection at the
     ** end of the event and resets it afterwards.
     **/

    void EndOfEvent() override;

    /** method Register
     **
     ** Registers the hit collection in the ROOT manager.
     **/
    void Register() override;

    /** Accessor to the hit collection **/
    TClonesArray* GetCollection(Int_t iColl) const override;

    /** method Print
     **
     ** Screen output of hit collection.
     **/
    void Print(Option_t* option = "") const override;

    /** method Reset
     **
     ** Clears the hit collection
     **/
    void Reset() override;

    void Initialize() override;

  private:
    /** Track information to be stored until the track leaves the
    active volume. **/
    int fTrackID = 0;               //  track index
    int fPpacID = 0;                //  PPAC id
    int fVolGasID = 0;              // Gas Volumn id
    TLorentzVector fPosIn, fPosOut; //  position
    TLorentzVector fMomIn, fMomOut; //  momentum
    double fTime_in;                //  time when entering active volume
    double fTime_out;               //  time when exiting active volume
    double fTime;                   //  time
    double fLength_in;              //  length when entering active volume
    double fLength_out;             //  length when exiting active volume
    double fLength;                 //  length
    double fELoss;                  //  energy loss
    TClonesArray* fPpacPoint = nullptr;

    /** Private method AddHit
     **
     ** Adds a NTOFPpacsPoint to the HitCollection
     **/
    NTOFPpacsPoint* AddHit(int trackID,
                           int ppacID,
                           int gasPpacID,
                           TVector3 posIn,
                           TVector3 pos_out,
                           TVector3 momIn,
                           TVector3 momOut,
                           double time,
                           double length,
                           double eLoss,
                           int pdgcode);

    /** Private method ResetParameters
     **
     ** Resets the private members for the track parameters
     **/
    void ResetParameters();

  public:
    ClassDefOverride(NTOFPpacs, 1);
};

inline void NTOFPpacs::ResetParameters()
{
    fTrackID = 0;
    fPpacID = 0;
    fPosIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fPosOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fMomIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fMomOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fTime = fLength = fELoss = 0;
};
