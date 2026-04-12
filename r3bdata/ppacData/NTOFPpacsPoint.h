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

// -----------------------------------------------------------------
// -----              NTOFPpacsPoint header file               -----
// -----          Created 12/04/2026 by J.L. Rodriguez         -----
// -----------------------------------------------------------------

#pragma once

#include <FairMCPoint.h>

#include <TObject.h>
#include <TVector3.h>
#include <stdint.h>

class NTOFPpacsPoint : public FairMCPoint
{
  public:
    /** Default constructor **/
    NTOFPpacsPoint();

    /** Constructor with arguments
     *@param trackID  Index of MCTrack
     *@param gasID    Gas ID
     *@param posIn    Coordinates at entrance to active volume [cm]
     *@param posOut   Coordinates at exit of active volume [cm]
     *@param momIn    Momentum of track at entrance [GeV]
     *@param momOut   Momentum of track at exit [GeV]
     *@param tof      Time since event start [ns]
     *@param length   Track length since creation [cm]
     *@param eLoss    Energy deposit [GeV]
     *@param pid      Particle ID
     **/
    NTOFPpacsPoint(int trackID,
                   int ppacID,
                   int gasID,
                   TVector3 posIn,
                   TVector3 posOut,
                   TVector3 momIn,
                   TVector3 momOut,
                   double tof,
                   double length,
                   double eLoss,
                   int pid);

    /** Destructor **/
    virtual ~NTOFPpacsPoint() = default;

    /** Accessors **/
    int GetPpacID() const { return fDetectorID; }
    int GetGasID() const { return fGasID; }
    double GetXIn() const { return fX; }
    double GetYIn() const { return fY; }
    int GetPid() const { return fPid; }
    double GetZIn() const { return fZ; }
    double GetXOut() const { return fX_out; }
    double GetYOut() const { return fY_out; }
    double GetZOut() const { return fZ_out; }
    double GetPxOut() const { return fPx_out; }
    double GetPyOut() const { return fPy_out; }
    double GetPzOut() const { return fPz_out; }
    inline double GetTheta() const
    {
        TVector3 v;
        v.SetXYZ(fX, fY, fZ);
        return v.Theta();
    }
    inline double GetPhi() const
    {
        TVector3 v;
        v.SetXYZ(fX, fY, fZ);
        return v.Phi();
    }

    void PositionIn(TVector3& pos) { pos.SetXYZ(fX, fY, fZ); }
    void PositionOut(TVector3& pos) { pos.SetXYZ(fX_out, fY_out, fZ_out); }
    void MomentumOut(TVector3& mom) { mom.SetXYZ(fPx_out, fPy_out, fPz_out); }

    /** Point coordinates at given z from linear extrapolation **/
    double GetX(double z) const;
    double GetY(double z) const;

    /** Modifiers **/
    void SetPositionOut(TVector3 pos);
    void SetMomentumOut(TVector3 mom);
    void SetPpacID(int id) { fDetectorID = id; };
    void SetGasID(int id) { fGasID = id; };

  private:
    int fGasID, fPid;
    Double32_t fX_out, fY_out, fZ_out, fEloss;
    Double32_t fPx_out, fPy_out, fPz_out;

    ClassDefOverride(NTOFPpacsPoint, 1);
};

inline void NTOFPpacsPoint::SetPositionOut(TVector3 pos)
{
    fX_out = pos.X();
    fY_out = pos.Y();
    fZ_out = pos.Z();
}

inline void NTOFPpacsPoint::SetMomentumOut(TVector3 mom)
{
    fPx_out = mom.Px();
    fPy_out = mom.Py();
    fPz_out = mom.Pz();
}
