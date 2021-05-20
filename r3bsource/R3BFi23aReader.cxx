/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019 Members of R3B Collaboration                          *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

#include "R3BFi23aReader.h"
#include "FairLogger.h"

extern "C"
{
#include "ext_data_client.h"
#include "ext_h101_fib23a.h"
}

R3BFi23aReader::R3BFi23aReader(EXT_STR_h101_FIBZEA* a_data, UInt_t a_offset)
    : R3BFiberMAPMTReader("Fi23a", a_offset, 256)
    , fData((EXT_STR_h101_FIBZEA_onion*)a_data)
{
}


Bool_t R3BFi23aReader::Init(ext_data_struct_info* a_struct_info) { R3B_FIBER_MAPMT_INIT_TRIG(FIBZEA, fData); }

ClassImp(R3BFi23aReader)
