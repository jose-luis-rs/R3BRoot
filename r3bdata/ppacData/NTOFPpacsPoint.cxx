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

// -------------------------------------------------------------------------
// -----                      NTOFPpacsPoint source file               -----
// -------------------------------------------------------------------------

#include "NTOFPpacsPoint.h"

// -----   Default constructor   -------------------------------------------
NTOFPpacsPoint::NTOFPpacsPoint()
    : FairMCPoint()
{
    fGasID = 0;
    fPid = 0;
    fX_out = fY_out = fZ_out = fEloss = 0.;
    fPx_out = fPy_out = fPz_out = 0.;
}
// -------------------------------------------------------------------------

// -----   Standard constructor   ------------------------------------------
NTOFPpacsPoint::NTOFPpacsPoint(int trackID,
                               int ppacID,
                               int gasID,
                               TVector3 posIn,
                               TVector3 posOut,
                               TVector3 momIn,
                               TVector3 momOut,
                               double tof,
                               double length,
                               double eLoss,
                               int PId)
    : FairMCPoint(trackID, ppacID, posIn, momIn, tof, length, eLoss)
{
    fGasID = gasID;
    fPid = PId;
    fX_out = posOut.X();
    fY_out = posOut.Y();
    fZ_out = posOut.Z();
    fEloss = eLoss;
    fPx_out = momOut.Px();
    fPy_out = momOut.Py();
    fPz_out = momOut.Pz();
}

// -----   Point x coordinate from linear extrapolation   ------------------
double NTOFPpacsPoint::GetX(double z) const
{
    if ((fZ_out - z) * (fZ - z) >= 0.)
        return (fX_out + fX) / 2.;
    Double_t dz = fZ_out - fZ;
    return (fX + (z - fZ) / dz * (fX_out - fX));
}
// -------------------------------------------------------------------------

// -----   Point y coordinate from linear extrapolation   ------------------
double NTOFPpacsPoint::GetY(double z) const
{
    if ((fZ_out - z) * (fZ - z) >= 0.)
        return (fY_out + fY) / 2.;
    Double_t dz = fZ_out - fZ;
    return (fY + (z - fZ) / dz * (fY_out - fY));
}
// -------------------------------------------------------------------------

ClassImp(NTOFPpacsPoint)
