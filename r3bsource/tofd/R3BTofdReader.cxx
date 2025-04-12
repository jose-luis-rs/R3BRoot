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

#include "R3BTofdReader.h"
#include "R3BLogger.h"
#include "R3BTofdMappedData.h"

#include <FairLogger.h>
#include <FairRootManager.h>

#include <TClonesArray.h>
#include <ext_data_struct_info.hh>

extern "C"
{
#include "ext_data_client.h"
#include "ext_h101_tofd.h"
}

// #define MAX_TOFD_CARDS (sizeof data->TOFD_TRIGCLI / sizeof data->TOFD_TRIGCLI[0])
#define MAX_TOFD_PLANES (sizeof data->TOFD_P / sizeof data->TOFD_P[0])

R3BTofdReader::R3BTofdReader(EXT_STR_h101_TOFD_onion* data, size_t offset)
    : R3BReader("R3BTofdReader")
    , fData(data)
    , fOffset(offset)
    , fArray(new TClonesArray("R3BTofdMappedData"))
    , fArrayWalkC(new TClonesArray("R3BTofdMappedData"))
    , fArrayTrigger(new TClonesArray("R3BTofdMappedData"))
{
}

R3BTofdReader::~R3BTofdReader()
{
    if (fArray)
    {
        delete fArray;
    }
    if (fArrayWalkC)
    {
        delete fArrayWalkC;
    }
    if (fArrayTrigger)
    {
        delete fArrayTrigger;
    }
}

Bool_t R3BTofdReader::Init(ext_data_struct_info* a_struct_info)
{
    Int_t ok;
    R3BLOG(info, "");
    EXT_STR_h101_TOFD_ITEMS_INFO(ok, *a_struct_info, fOffset, EXT_STR_h101_TOFD, 0);
    if (!ok)
    {
        R3BLOG(error, "Failed to setup structure information");
        return kFALSE;
    }

    // Register output array in tree
    FairRootManager::Instance()->Register("TofdMapped", "Tofd mapped data", fArray, !fOnline);

    if (fWalkCorrection)
    {
        FairRootManager::Instance()->Register(
            "TofdWalkCorMapped", "Tofd mapped data for walk correction", fArrayWalkC, !fOnline);
    }
    else
    {
        fArrayWalkC = nullptr;
    }

    if (!fSkiptriggertimes)
    {
        FairRootManager::Instance()->Register("TofdTriggerMapped", "Tofd trigger mapped data", fArrayTrigger, !fOnline);
    }
    else
    {
        fArrayTrigger = nullptr;
    }
    Reset();

    // initial clear (set number of hits to 0)
    auto* data = reinterpret_cast<EXT_STR_h101_TOFD_onion*>(fData);
    for (int d = 0; d < MAX_TOFD_PLANES; d++)
    {
        for (int t = 0; t < 2; t++)
        {
            data->TOFD_P[d].T[t].TFLM = 0;
            data->TOFD_P[d].T[t].TFTM = 0;
        }
    }

    return kTRUE;
}

Bool_t R3BTofdReader::R3BRead()
{
    R3BLOG(debug1, "Event data.");
    // Convert plain raw data to multi-dimensional array
    auto* data = reinterpret_cast<EXT_STR_h101_TOFD_onion*>(fData);

    for (uint32_t plane = 0; plane < MAX_TOFD_PLANES; plane++)
    {
        for (uint32_t pmt = 0; pmt < 2; pmt++)
        {
            auto const& side = data->TOFD_P[plane].T[pmt];

            // TAMEX3

            // Leading
            auto numChannels = side.TCLM;
            uint32_t curChannelStart = 0;
            for (uint32_t i = 0; i < numChannels; i++)
            {
                uint32_t channel = side.TCLMI[i];
                uint32_t nextChannelStart = side.TCLME[i];
                for (uint32_t j = curChannelStart; j < nextChannelStart; j++)
                {
                    if (plane < 2 && pmt == 0 && channel == 48) // Walk correction
                    {
                        new ((*fArrayWalkC)[fArrayWalkC->GetEntriesFast()])
                            R3BTofdMappedData(plane + 1, pmt + 1, channel, 1, side.TCLv[j], side.TFLv[j]);
                    }
                    else
                    {
                        new ((*fArray)[fArray->GetEntriesFast()])
                            R3BTofdMappedData(plane + 1, pmt + 1, channel, 1, side.TCLv[j], side.TFLv[j]);
                    }
                }
                curChannelStart = nextChannelStart;
            }

            // Trailing
            numChannels = side.TCTM;
            curChannelStart = 0;
            for (uint32_t i = 0; i < numChannels; i++)
            {
                uint32_t channel = side.TCTMI[i];
                uint32_t nextChannelStart = side.TCTME[i];
                for (uint32_t j = curChannelStart; j < nextChannelStart; j++)
                {
                    if (plane < 2 && pmt == 0 && channel == 48) // Walk correction
                    {
                        new ((*fArrayWalkC)[fArrayWalkC->GetEntriesFast()])
                            R3BTofdMappedData(plane + 1, pmt + 1, channel, 2, side.TCTv[j], side.TFTv[j]);
                    }
                    else
                    {
                        new ((*fArray)[fArray->GetEntriesFast()])
                            R3BTofdMappedData(plane + 1, pmt + 1, channel, 2, side.TCTv[j], side.TFTv[j]);
                    }
                }
                curChannelStart = nextChannelStart;
            }

        } // for side
    }     // for planes

    // TAMEX trigger times
    if (fArrayTrigger)
    {
        // Leading
        auto numChannelsL = data->TOFD_TRIGFL;
        for (uint32_t i = 0; i < numChannelsL; i++)
        {
            uint32_t channel = data->TOFD_TRIGFLI[i];
            new ((*fArrayTrigger)[fArrayTrigger->GetEntriesFast()])
                R3BTofdMappedData(MAX_TOFD_PLANES + 1, 1, channel, 1, data->TOFD_TRIGCLv[i], data->TOFD_TRIGFLv[i]);
        }

        // Trailing
        auto numChannelsT = data->TOFD_TRIGFT;
        for (uint32_t i = 0; i < numChannelsT; i++)
        {
            uint32_t channel = data->TOFD_TRIGFTI[i];
            new ((*fArrayTrigger)[fArrayTrigger->GetEntriesFast()])
                R3BTofdMappedData(MAX_TOFD_PLANES + 1, 1, channel, 2, data->TOFD_TRIGCTv[i], data->TOFD_TRIGFTv[i]);
        }
    }
    return kTRUE;
}

void R3BTofdReader::Reset()
{
    // Reset the output array
    fArray->Clear();
    if (fArrayWalkC)
        fArrayWalkC->Clear();
    if (fArrayTrigger)
        fArrayTrigger->Clear();
}

ClassImp(R3BTofdReader)
