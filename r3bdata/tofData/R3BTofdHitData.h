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

#include "R3BHit.h"

#include <cmath>
#include <cstdint>

// for the data analysis of the Tofd detectors.
// Introduced by M.Heil, May 2016

class R3BTofdHitData : public R3BHit
{
  public:
    // Default Constructor
    R3BTofdHitData() = default;

    // Standard Constructor
    R3BTofdHitData(Double_t t,
                   Double_t x,
                   Double_t y,
                   Double_t Z,
                   Double_t tdiff,
                   Double_t ELoss = 0,
                   Double_t ID = 0,
                   UInt_t iBar = 0,
                   Double_t traw = -1000,
                   Double_t tof = 0.);

    // Destructor
    ~R3BTofdHitData() = default;

    UInt_t GetBarId() const;
    Double_t GetTimeRaw() const; // Get paddle time without trigger
    Double_t GetTof() const;     // Time-of-flight with respect to LOS detector
    [[nodiscard]] inline Double_t GetChargeZ() const { return fCharge; }

  private:
    UInt_t fBarId = 0;
    Double_t fTimeRaw = std::nan("");
    Double_t fTof = std::nan("");
    Double_t fCharge = std::nan("");

  public:
    ClassDef(R3BTofdHitData, 4);
};
