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

#pragma once

#include "R3BDetector.h"
#include <TLorentzVector.h>

class TClonesArray;
class R3BTofdPoint;
class FairVolume;

class R3BDummyDetector : public R3BDetector
{
  public:
    /** Default constructor */
    R3BDummyDetector();

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param trans   position
     *@param rot     rotation
     */
    R3BDummyDetector(const TString& geoFile, const TGeoTranslation& trans, const TGeoRotation& rot = TGeoRotation());

    /** Standard constructor.
     *@param geoFile name of the ROOT geometry file
     *@param combi   position + rotation
     */
    R3BDummyDetector(const TString& geoFile, const TGeoCombiTrans& combi = TGeoCombiTrans());

    /** Destructor **/
    ~R3BDummyDetector() override;

    /** Virtual method ProcessHits
     **
     ** Defines the action to be taken when a step is inside the
     ** active volume. Creates a R3BDummyDetectorPoint and adds it to the
     ** collection.
     *@param vol  Pointer to the active volume
     **/
    Bool_t ProcessHits(FairVolume* vol = 0) override;

    /** Virtual method EndOfEvent
     **
     ** If verbosity level is set, print hit collection at the
     ** end of the event and resets it afterwards.
     **/

    void EndOfEvent() override;

    /** Virtual method Register
     **
     ** Registers the hit collection in the ROOT manager.
     **/
    void Register() override;

    /** Accessor to the hit collection **/
    TClonesArray* GetCollection(Int_t iColl) const override;

    /** Virtual method Print
     **
     ** Screen output of hit collection.
     **/
    void Print(Option_t* option = "") const override;

    /** Virtual method Reset
     **
     ** Clears the hit collection
     **/
    void Reset() override;

    Bool_t CheckIfSensitive(std::string name) override;
    void Initialize() override;

  private:
    /** Track information to be stored until the track leaves the
    active volume. **/
    Int_t fTrackID;                 //!  track index
    Int_t fPlaneID;                 //!  Plane id
    Int_t fPaddleID;                //!  Paddle id
    TLorentzVector fPosIn, fPosOut; //!  position
    TLorentzVector fMomIn, fMomOut; //!  momentum
    Double32_t fTime_in;            //!  time when entering active volume
    Double32_t fTime_out;           //!  time when exiting active volume
    Double32_t fTime;               //!  time
    Double32_t fLength_in;          //!  length when entering active volume
    Double32_t fLength_out;         //!  length when exiting active volume
    Double32_t fLength;             //!  length
    Double32_t fELoss;              //!  energy loss
    TClonesArray* fCollection; //!  The hit collection
    TGeoCombiTrans fCombi;

    /** Private method AddHit
     **
     ** Adds a Point to the HitCollection
     **/
    R3BTofdPoint* AddHit(Int_t trackID,
                         Int_t detID,
                         Int_t planeID,
                         Int_t paddleID,
                         TVector3 posIn,
                         TVector3 pos_out,
                         TVector3 momIn,
                         TVector3 momOut,
                         Double_t time,
                         Double_t length,
                         Double_t eLoss,
                         Double_t Z,
                         Double_t A);

    /** Private method ResetParameters
     **
     ** Resets the private members for the track parameters
     **/
    void ResetParameters();
    
    //void ConstructGeometry() override;

  public:
    ClassDefOverride(R3BDummyDetector, 1);
};

inline void R3BDummyDetector::ResetParameters()
{
    fTrackID = fPlaneID = fPaddleID = 0;
    fPosIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fPosOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fMomIn.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fMomOut.SetXYZM(0.0, 0.0, 0.0, 0.0);
    fTime = fLength = fELoss = 0;
};
