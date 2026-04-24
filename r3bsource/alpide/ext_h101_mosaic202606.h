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

/********************************************************
 *
 * Structure for ext_data_fetch_event() filling.
 *
 * Do not edit - automatically generated.
 */

#pragma once

#ifndef __CINT__
#include <stdint.h>
#else
/* For CINT (old version trouble with stdint.h): */
#ifndef uint32_t
typedef unsigned int uint32_t;
typedef int int32_t;
#endif
#endif
#ifndef EXT_STRUCT_CTRL
#define EXT_STRUCT_CTRL(x)
#endif

/********************************************************
 *
 * Plain structure (layout as ntuple/root file):
 */

typedef struct EXT_STR_h101_MOSAIC202606_t
{
    /* RAW */
    uint32_t MOSAIC1T_HI /* [-1,-1] */;
    uint32_t MOSAIC1T_LO /* [-1,-1] */;
    uint32_t MOSAIC1T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC1TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC1TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC1STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC1CHIPS /* [0,27] */;
    uint32_t MOSAIC1CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC1CHIPS)] /* [0,255] */;
    uint32_t MOSAIC1CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC1CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC1CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC1CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC1CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC1CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC1CHIP /* [0,32767] */;
    uint32_t MOSAIC1CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC1CHIP)] /* [0,255] */;
    uint32_t MOSAIC1COL /* [0,32767] */;
    uint32_t MOSAIC1COLv[32767 EXT_STRUCT_CTRL(MOSAIC1COL)] /* [0,65535] */;
    uint32_t MOSAIC1ROW /* [0,32767] */;
    uint32_t MOSAIC1ROWv[32767 EXT_STRUCT_CTRL(MOSAIC1ROW)] /* [0,65535] */;
    uint32_t MOSAIC1SNUM /* [0,32767] */;
    uint32_t MOSAIC1SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC1SNUM)] /* [0,65535] */;
    uint32_t MOSAIC2T_HI /* [-1,-1] */;
    uint32_t MOSAIC2T_LO /* [-1,-1] */;
    uint32_t MOSAIC2T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC2TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC2TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC2STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC2CHIPS /* [0,27] */;
    uint32_t MOSAIC2CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC2CHIPS)] /* [0,255] */;
    uint32_t MOSAIC2CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC2CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC2CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC2CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC2CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC2CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC2CHIP /* [0,32767] */;
    uint32_t MOSAIC2CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC2CHIP)] /* [0,255] */;
    uint32_t MOSAIC2COL /* [0,32767] */;
    uint32_t MOSAIC2COLv[32767 EXT_STRUCT_CTRL(MOSAIC2COL)] /* [0,65535] */;
    uint32_t MOSAIC2ROW /* [0,32767] */;
    uint32_t MOSAIC2ROWv[32767 EXT_STRUCT_CTRL(MOSAIC2ROW)] /* [0,65535] */;
    uint32_t MOSAIC2SNUM /* [0,32767] */;
    uint32_t MOSAIC2SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC2SNUM)] /* [0,65535] */;
    uint32_t MOSAIC3T_HI /* [-1,-1] */;
    uint32_t MOSAIC3T_LO /* [-1,-1] */;
    uint32_t MOSAIC3T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC3TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC3TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC3STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC3CHIPS /* [0,27] */;
    uint32_t MOSAIC3CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC3CHIPS)] /* [0,255] */;
    uint32_t MOSAIC3CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC3CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC3CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC3CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC3CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC3CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC3CHIP /* [0,32767] */;
    uint32_t MOSAIC3CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC3CHIP)] /* [0,255] */;
    uint32_t MOSAIC3COL /* [0,32767] */;
    uint32_t MOSAIC3COLv[32767 EXT_STRUCT_CTRL(MOSAIC3COL)] /* [0,65535] */;
    uint32_t MOSAIC3ROW /* [0,32767] */;
    uint32_t MOSAIC3ROWv[32767 EXT_STRUCT_CTRL(MOSAIC3ROW)] /* [0,65535] */;
    uint32_t MOSAIC3SNUM /* [0,32767] */;
    uint32_t MOSAIC3SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC3SNUM)] /* [0,65535] */;
    uint32_t MOSAIC4T_HI /* [-1,-1] */;
    uint32_t MOSAIC4T_LO /* [-1,-1] */;
    uint32_t MOSAIC4T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC4TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC4TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC4STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC4CHIPS /* [0,27] */;
    uint32_t MOSAIC4CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC4CHIPS)] /* [0,255] */;
    uint32_t MOSAIC4CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC4CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC4CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC4CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC4CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC4CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC4CHIP /* [0,32767] */;
    uint32_t MOSAIC4CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC4CHIP)] /* [0,255] */;
    uint32_t MOSAIC4COL /* [0,32767] */;
    uint32_t MOSAIC4COLv[32767 EXT_STRUCT_CTRL(MOSAIC4COL)] /* [0,65535] */;
    uint32_t MOSAIC4ROW /* [0,32767] */;
    uint32_t MOSAIC4ROWv[32767 EXT_STRUCT_CTRL(MOSAIC4ROW)] /* [0,65535] */;
    uint32_t MOSAIC4SNUM /* [0,32767] */;
    uint32_t MOSAIC4SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC4SNUM)] /* [0,65535] */;
    uint32_t MOSAIC5T_HI /* [-1,-1] */;
    uint32_t MOSAIC5T_LO /* [-1,-1] */;
    uint32_t MOSAIC5T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC5TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC5TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC5STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC5CHIPS /* [0,27] */;
    uint32_t MOSAIC5CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC5CHIPS)] /* [0,255] */;
    uint32_t MOSAIC5CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC5CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC5CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC5CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC5CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC5CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC5CHIP /* [0,32767] */;
    uint32_t MOSAIC5CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC5CHIP)] /* [0,255] */;
    uint32_t MOSAIC5COL /* [0,32767] */;
    uint32_t MOSAIC5COLv[32767 EXT_STRUCT_CTRL(MOSAIC5COL)] /* [0,65535] */;
    uint32_t MOSAIC5ROW /* [0,32767] */;
    uint32_t MOSAIC5ROWv[32767 EXT_STRUCT_CTRL(MOSAIC5ROW)] /* [0,65535] */;
    uint32_t MOSAIC5SNUM /* [0,32767] */;
    uint32_t MOSAIC5SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC5SNUM)] /* [0,65535] */;
    uint32_t MOSAIC6T_HI /* [-1,-1] */;
    uint32_t MOSAIC6T_LO /* [-1,-1] */;
    uint32_t MOSAIC6T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC6TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC6TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC6STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC6CHIPS /* [0,27] */;
    uint32_t MOSAIC6CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC6CHIPS)] /* [0,255] */;
    uint32_t MOSAIC6CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC6CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC6CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC6CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC6CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC6CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC6CHIP /* [0,32767] */;
    uint32_t MOSAIC6CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC6CHIP)] /* [0,255] */;
    uint32_t MOSAIC6COL /* [0,32767] */;
    uint32_t MOSAIC6COLv[32767 EXT_STRUCT_CTRL(MOSAIC6COL)] /* [0,65535] */;
    uint32_t MOSAIC6ROW /* [0,32767] */;
    uint32_t MOSAIC6ROWv[32767 EXT_STRUCT_CTRL(MOSAIC6ROW)] /* [0,65535] */;
    uint32_t MOSAIC6SNUM /* [0,32767] */;
    uint32_t MOSAIC6SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC6SNUM)] /* [0,65535] */;
    uint32_t MOSAIC7T_HI /* [-1,-1] */;
    uint32_t MOSAIC7T_LO /* [-1,-1] */;
    uint32_t MOSAIC7T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC7TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC7TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC7STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC7CHIPS /* [0,27] */;
    uint32_t MOSAIC7CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC7CHIPS)] /* [0,255] */;
    uint32_t MOSAIC7CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC7CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC7CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC7CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC7CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC7CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC7CHIP /* [0,32767] */;
    uint32_t MOSAIC7CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC7CHIP)] /* [0,255] */;
    uint32_t MOSAIC7COL /* [0,32767] */;
    uint32_t MOSAIC7COLv[32767 EXT_STRUCT_CTRL(MOSAIC7COL)] /* [0,65535] */;
    uint32_t MOSAIC7ROW /* [0,32767] */;
    uint32_t MOSAIC7ROWv[32767 EXT_STRUCT_CTRL(MOSAIC7ROW)] /* [0,65535] */;
    uint32_t MOSAIC7SNUM /* [0,32767] */;
    uint32_t MOSAIC7SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC7SNUM)] /* [0,65535] */;
    uint32_t MOSAIC8T_HI /* [-1,-1] */;
    uint32_t MOSAIC8T_LO /* [-1,-1] */;
    uint32_t MOSAIC8T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC8TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC8TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC8STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC8CHIPS /* [0,27] */;
    uint32_t MOSAIC8CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC8CHIPS)] /* [0,255] */;
    uint32_t MOSAIC8CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC8CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC8CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC8CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC8CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC8CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC8CHIP /* [0,32767] */;
    uint32_t MOSAIC8CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC8CHIP)] /* [0,255] */;
    uint32_t MOSAIC8COL /* [0,32767] */;
    uint32_t MOSAIC8COLv[32767 EXT_STRUCT_CTRL(MOSAIC8COL)] /* [0,65535] */;
    uint32_t MOSAIC8ROW /* [0,32767] */;
    uint32_t MOSAIC8ROWv[32767 EXT_STRUCT_CTRL(MOSAIC8ROW)] /* [0,65535] */;
    uint32_t MOSAIC8SNUM /* [0,32767] */;
    uint32_t MOSAIC8SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC8SNUM)] /* [0,65535] */;
    uint32_t MOSAIC9T_HI /* [-1,-1] */;
    uint32_t MOSAIC9T_LO /* [-1,-1] */;
    uint32_t MOSAIC9T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC9TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC9TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC9STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC9CHIPS /* [0,27] */;
    uint32_t MOSAIC9CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC9CHIPS)] /* [0,255] */;
    uint32_t MOSAIC9CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC9CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC9CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC9CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC9CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC9CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC9CHIP /* [0,32767] */;
    uint32_t MOSAIC9CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC9CHIP)] /* [0,255] */;
    uint32_t MOSAIC9COL /* [0,32767] */;
    uint32_t MOSAIC9COLv[32767 EXT_STRUCT_CTRL(MOSAIC9COL)] /* [0,65535] */;
    uint32_t MOSAIC9ROW /* [0,32767] */;
    uint32_t MOSAIC9ROWv[32767 EXT_STRUCT_CTRL(MOSAIC9ROW)] /* [0,65535] */;
    uint32_t MOSAIC9SNUM /* [0,32767] */;
    uint32_t MOSAIC9SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC9SNUM)] /* [0,65535] */;
    uint32_t MOSAIC10T_HI /* [-1,-1] */;
    uint32_t MOSAIC10T_LO /* [-1,-1] */;
    uint32_t MOSAIC10T_SYNC /* [-1,-1] */;
    uint32_t MOSAIC10TRIG_LO /* [-1,-1] */;
    uint32_t MOSAIC10TRIG_HI /* [-1,-1] */;
    uint32_t MOSAIC10STROBE_TPAT /* [-1,-1] */;
    uint32_t MOSAIC10CHIPS /* [0,27] */;
    uint32_t MOSAIC10CHIPSv[27 EXT_STRUCT_CTRL(MOSAIC10CHIPS)] /* [0,255] */;
    uint32_t MOSAIC10CHIPSVALUE /* [0,27] */;
    uint32_t MOSAIC10CHIPSVALUEv[27 EXT_STRUCT_CTRL(MOSAIC10CHIPSVALUE)] /* [-1,-1] */;
    uint32_t MOSAIC10CHIPSSTROBE /* [0,27] */;
    uint32_t MOSAIC10CHIPSSTROBEv[27 EXT_STRUCT_CTRL(MOSAIC10CHIPSSTROBE)] /* [-1,-1] */;
    uint32_t MOSAIC10CHIP /* [0,32767] */;
    uint32_t MOSAIC10CHIPv[32767 EXT_STRUCT_CTRL(MOSAIC10CHIP)] /* [0,255] */;
    uint32_t MOSAIC10COL /* [0,32767] */;
    uint32_t MOSAIC10COLv[32767 EXT_STRUCT_CTRL(MOSAIC10COL)] /* [0,65535] */;
    uint32_t MOSAIC10ROW /* [0,32767] */;
    uint32_t MOSAIC10ROWv[32767 EXT_STRUCT_CTRL(MOSAIC10ROW)] /* [0,65535] */;
    uint32_t MOSAIC10SNUM /* [0,32767] */;
    uint32_t MOSAIC10SNUMv[32767 EXT_STRUCT_CTRL(MOSAIC10SNUM)] /* [0,65535] */;

} EXT_STR_h101_MOSAIC202606;

/********************************************************
 *
 * Structure with multiple levels of arrays (partially)
 * recovered (recommended):
 */

typedef struct EXT_STR_h101_MOSAIC202606_onion_t
{
    /* RAW */
    struct
    {
        uint32_t T_HI;
        uint32_t T_LO;
        uint32_t T_SYNC;
        uint32_t TRIG_LO;
        uint32_t TRIG_HI;
        uint32_t STROBE_TPAT;
        uint32_t CHIPS;
        uint32_t CHIPSv[27 /* CHIPS */];
        uint32_t CHIPSVALUE;
        uint32_t CHIPSVALUEv[27 /* CHIPSVALUE */];
        uint32_t CHIPSSTROBE;
        uint32_t CHIPSSTROBEv[27 /* CHIPSSTROBE */];
        uint32_t CHIP;
        uint32_t CHIPv[32767 /* CHIP */];
        uint32_t COL;
        uint32_t COLv[32767 /* COL */];
        uint32_t ROW;
        uint32_t ROWv[32767 /* ROW */];
        uint32_t SNUM;
        uint32_t SNUMv[32767 /* SNUM */];
    } MOSAIC[10];

} EXT_STR_h101_MOSAIC202606_onion;

/*******************************************************/

#define EXT_STR_h101_MOSAIC202606_ITEMS_INFO(ok, si, offset, struct_t, printerr)                                       \
    do                                                                                                                 \
    {                                                                                                                  \
        ok = 1;                                                                                                        \
        /* RAW */                                                                                                      \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC1T_HI, UINT32, "MOSAIC1T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC1T_LO, UINT32, "MOSAIC1T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC1T_SYNC, UINT32, "MOSAIC1T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC1TRIG_LO, UINT32, "MOSAIC1TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC1TRIG_HI, UINT32, "MOSAIC1TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC1STROBE_TPAT, UINT32, "MOSAIC1STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIPS, UINT32, "MOSAIC1CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIPSv, UINT32, "MOSAIC1CHIPSv", "MOSAIC1CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIPSVALUE, UINT32, "MOSAIC1CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC1CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC1CHIPSVALUEv",                                                                   \
                               "MOSAIC1CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIPSSTROBE, UINT32, "MOSAIC1CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC1CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC1CHIPSSTROBEv",                                                                  \
                               "MOSAIC1CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIP, UINT32, "MOSAIC1CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1CHIPv, UINT32, "MOSAIC1CHIPv", "MOSAIC1CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1COL, UINT32, "MOSAIC1COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1COLv, UINT32, "MOSAIC1COLv", "MOSAIC1COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1ROW, UINT32, "MOSAIC1ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1ROWv, UINT32, "MOSAIC1ROWv", "MOSAIC1ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1SNUM, UINT32, "MOSAIC1SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC1SNUMv, UINT32, "MOSAIC1SNUMv", "MOSAIC1SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC2T_HI, UINT32, "MOSAIC2T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC2T_LO, UINT32, "MOSAIC2T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC2T_SYNC, UINT32, "MOSAIC2T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC2TRIG_LO, UINT32, "MOSAIC2TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC2TRIG_HI, UINT32, "MOSAIC2TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC2STROBE_TPAT, UINT32, "MOSAIC2STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIPS, UINT32, "MOSAIC2CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIPSv, UINT32, "MOSAIC2CHIPSv", "MOSAIC2CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIPSVALUE, UINT32, "MOSAIC2CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC2CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC2CHIPSVALUEv",                                                                   \
                               "MOSAIC2CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIPSSTROBE, UINT32, "MOSAIC2CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC2CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC2CHIPSSTROBEv",                                                                  \
                               "MOSAIC2CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIP, UINT32, "MOSAIC2CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2CHIPv, UINT32, "MOSAIC2CHIPv", "MOSAIC2CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2COL, UINT32, "MOSAIC2COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2COLv, UINT32, "MOSAIC2COLv", "MOSAIC2COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2ROW, UINT32, "MOSAIC2ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2ROWv, UINT32, "MOSAIC2ROWv", "MOSAIC2ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2SNUM, UINT32, "MOSAIC2SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC2SNUMv, UINT32, "MOSAIC2SNUMv", "MOSAIC2SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC3T_HI, UINT32, "MOSAIC3T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC3T_LO, UINT32, "MOSAIC3T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC3T_SYNC, UINT32, "MOSAIC3T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC3TRIG_LO, UINT32, "MOSAIC3TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC3TRIG_HI, UINT32, "MOSAIC3TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC3STROBE_TPAT, UINT32, "MOSAIC3STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIPS, UINT32, "MOSAIC3CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIPSv, UINT32, "MOSAIC3CHIPSv", "MOSAIC3CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIPSVALUE, UINT32, "MOSAIC3CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC3CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC3CHIPSVALUEv",                                                                   \
                               "MOSAIC3CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIPSSTROBE, UINT32, "MOSAIC3CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC3CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC3CHIPSSTROBEv",                                                                  \
                               "MOSAIC3CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIP, UINT32, "MOSAIC3CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3CHIPv, UINT32, "MOSAIC3CHIPv", "MOSAIC3CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3COL, UINT32, "MOSAIC3COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3COLv, UINT32, "MOSAIC3COLv", "MOSAIC3COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3ROW, UINT32, "MOSAIC3ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3ROWv, UINT32, "MOSAIC3ROWv", "MOSAIC3ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3SNUM, UINT32, "MOSAIC3SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC3SNUMv, UINT32, "MOSAIC3SNUMv", "MOSAIC3SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC4T_HI, UINT32, "MOSAIC4T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC4T_LO, UINT32, "MOSAIC4T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC4T_SYNC, UINT32, "MOSAIC4T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC4TRIG_LO, UINT32, "MOSAIC4TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC4TRIG_HI, UINT32, "MOSAIC4TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC4STROBE_TPAT, UINT32, "MOSAIC4STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIPS, UINT32, "MOSAIC4CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIPSv, UINT32, "MOSAIC4CHIPSv", "MOSAIC4CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIPSVALUE, UINT32, "MOSAIC4CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC4CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC4CHIPSVALUEv",                                                                   \
                               "MOSAIC4CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIPSSTROBE, UINT32, "MOSAIC4CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC4CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC4CHIPSSTROBEv",                                                                  \
                               "MOSAIC4CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIP, UINT32, "MOSAIC4CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4CHIPv, UINT32, "MOSAIC4CHIPv", "MOSAIC4CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4COL, UINT32, "MOSAIC4COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4COLv, UINT32, "MOSAIC4COLv", "MOSAIC4COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4ROW, UINT32, "MOSAIC4ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4ROWv, UINT32, "MOSAIC4ROWv", "MOSAIC4ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4SNUM, UINT32, "MOSAIC4SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC4SNUMv, UINT32, "MOSAIC4SNUMv", "MOSAIC4SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC5T_HI, UINT32, "MOSAIC5T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC5T_LO, UINT32, "MOSAIC5T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC5T_SYNC, UINT32, "MOSAIC5T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC5TRIG_LO, UINT32, "MOSAIC5TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC5TRIG_HI, UINT32, "MOSAIC5TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC5STROBE_TPAT, UINT32, "MOSAIC5STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIPS, UINT32, "MOSAIC5CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIPSv, UINT32, "MOSAIC5CHIPSv", "MOSAIC5CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIPSVALUE, UINT32, "MOSAIC5CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC5CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC5CHIPSVALUEv",                                                                   \
                               "MOSAIC5CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIPSSTROBE, UINT32, "MOSAIC5CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC5CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC5CHIPSSTROBEv",                                                                  \
                               "MOSAIC5CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIP, UINT32, "MOSAIC5CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5CHIPv, UINT32, "MOSAIC5CHIPv", "MOSAIC5CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5COL, UINT32, "MOSAIC5COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5COLv, UINT32, "MOSAIC5COLv", "MOSAIC5COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5ROW, UINT32, "MOSAIC5ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5ROWv, UINT32, "MOSAIC5ROWv", "MOSAIC5ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5SNUM, UINT32, "MOSAIC5SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC5SNUMv, UINT32, "MOSAIC5SNUMv", "MOSAIC5SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC6T_HI, UINT32, "MOSAIC6T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC6T_LO, UINT32, "MOSAIC6T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC6T_SYNC, UINT32, "MOSAIC6T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC6TRIG_LO, UINT32, "MOSAIC6TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC6TRIG_HI, UINT32, "MOSAIC6TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC6STROBE_TPAT, UINT32, "MOSAIC6STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIPS, UINT32, "MOSAIC6CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIPSv, UINT32, "MOSAIC6CHIPSv", "MOSAIC6CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIPSVALUE, UINT32, "MOSAIC6CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC6CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC6CHIPSVALUEv",                                                                   \
                               "MOSAIC6CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIPSSTROBE, UINT32, "MOSAIC6CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC6CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC6CHIPSSTROBEv",                                                                  \
                               "MOSAIC6CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIP, UINT32, "MOSAIC6CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6CHIPv, UINT32, "MOSAIC6CHIPv", "MOSAIC6CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6COL, UINT32, "MOSAIC6COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6COLv, UINT32, "MOSAIC6COLv", "MOSAIC6COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6ROW, UINT32, "MOSAIC6ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6ROWv, UINT32, "MOSAIC6ROWv", "MOSAIC6ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6SNUM, UINT32, "MOSAIC6SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC6SNUMv, UINT32, "MOSAIC6SNUMv", "MOSAIC6SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC7T_HI, UINT32, "MOSAIC7T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC7T_LO, UINT32, "MOSAIC7T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC7T_SYNC, UINT32, "MOSAIC7T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC7TRIG_LO, UINT32, "MOSAIC7TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC7TRIG_HI, UINT32, "MOSAIC7TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC7STROBE_TPAT, UINT32, "MOSAIC7STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIPS, UINT32, "MOSAIC7CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIPSv, UINT32, "MOSAIC7CHIPSv", "MOSAIC7CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIPSVALUE, UINT32, "MOSAIC7CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC7CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC7CHIPSVALUEv",                                                                   \
                               "MOSAIC7CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIPSSTROBE, UINT32, "MOSAIC7CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC7CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC7CHIPSSTROBEv",                                                                  \
                               "MOSAIC7CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIP, UINT32, "MOSAIC7CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7CHIPv, UINT32, "MOSAIC7CHIPv", "MOSAIC7CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7COL, UINT32, "MOSAIC7COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7COLv, UINT32, "MOSAIC7COLv", "MOSAIC7COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7ROW, UINT32, "MOSAIC7ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7ROWv, UINT32, "MOSAIC7ROWv", "MOSAIC7ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7SNUM, UINT32, "MOSAIC7SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC7SNUMv, UINT32, "MOSAIC7SNUMv", "MOSAIC7SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC8T_HI, UINT32, "MOSAIC8T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC8T_LO, UINT32, "MOSAIC8T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC8T_SYNC, UINT32, "MOSAIC8T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC8TRIG_LO, UINT32, "MOSAIC8TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC8TRIG_HI, UINT32, "MOSAIC8TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC8STROBE_TPAT, UINT32, "MOSAIC8STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIPS, UINT32, "MOSAIC8CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIPSv, UINT32, "MOSAIC8CHIPSv", "MOSAIC8CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIPSVALUE, UINT32, "MOSAIC8CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC8CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC8CHIPSVALUEv",                                                                   \
                               "MOSAIC8CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIPSSTROBE, UINT32, "MOSAIC8CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC8CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC8CHIPSSTROBEv",                                                                  \
                               "MOSAIC8CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIP, UINT32, "MOSAIC8CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8CHIPv, UINT32, "MOSAIC8CHIPv", "MOSAIC8CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8COL, UINT32, "MOSAIC8COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8COLv, UINT32, "MOSAIC8COLv", "MOSAIC8COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8ROW, UINT32, "MOSAIC8ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8ROWv, UINT32, "MOSAIC8ROWv", "MOSAIC8ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8SNUM, UINT32, "MOSAIC8SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC8SNUMv, UINT32, "MOSAIC8SNUMv", "MOSAIC8SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC9T_HI, UINT32, "MOSAIC9T_HI", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC9T_LO, UINT32, "MOSAIC9T_LO", 0 /*flags*/);       \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC9T_SYNC, UINT32, "MOSAIC9T_SYNC", 0 /*flags*/);   \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC9TRIG_LO, UINT32, "MOSAIC9TRIG_LO", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC9TRIG_HI, UINT32, "MOSAIC9TRIG_HI", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC9STROBE_TPAT, UINT32, "MOSAIC9STROBE_TPAT", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIPS, UINT32, "MOSAIC9CHIPS", 27, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIPSv, UINT32, "MOSAIC9CHIPSv", "MOSAIC9CHIPS", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIPSVALUE, UINT32, "MOSAIC9CHIPSVALUE", 27, 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC9CHIPSVALUEv,                                                                     \
                               UINT32,                                                                                 \
                               "MOSAIC9CHIPSVALUEv",                                                                   \
                               "MOSAIC9CHIPSVALUE",                                                                    \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIPSSTROBE, UINT32, "MOSAIC9CHIPSSTROBE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC9CHIPSSTROBEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC9CHIPSSTROBEv",                                                                  \
                               "MOSAIC9CHIPSSTROBE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIP, UINT32, "MOSAIC9CHIP", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9CHIPv, UINT32, "MOSAIC9CHIPv", "MOSAIC9CHIP", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9COL, UINT32, "MOSAIC9COL", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9COLv, UINT32, "MOSAIC9COLv", "MOSAIC9COL", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9ROW, UINT32, "MOSAIC9ROW", 32767, 0 /*flags*/);                \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9ROWv, UINT32, "MOSAIC9ROWv", "MOSAIC9ROW", 0 /*flags*/);        \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9SNUM, UINT32, "MOSAIC9SNUM", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC9SNUMv, UINT32, "MOSAIC9SNUMv", "MOSAIC9SNUM", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC10T_HI, UINT32, "MOSAIC10T_HI", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC10T_LO, UINT32, "MOSAIC10T_LO", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2(ok, si, offset, struct_t, printerr, MOSAIC10T_SYNC, UINT32, "MOSAIC10T_SYNC", 0 /*flags*/); \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC10TRIG_LO, UINT32, "MOSAIC10TRIG_LO", 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC10TRIG_HI, UINT32, "MOSAIC10TRIG_HI", 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2(                                                                                            \
            ok, si, offset, struct_t, printerr, MOSAIC10STROBE_TPAT, UINT32, "MOSAIC10STROBE_TPAT", 0 /*flags*/);      \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10CHIPS, UINT32, "MOSAIC10CHIPS", 27, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC10CHIPSv,                                                                         \
                               UINT32,                                                                                 \
                               "MOSAIC10CHIPSv",                                                                       \
                               "MOSAIC10CHIPS",                                                                        \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10CHIPSVALUE, UINT32, "MOSAIC10CHIPSVALUE", 27, 0 /*flags*/);    \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC10CHIPSVALUEv,                                                                    \
                               UINT32,                                                                                 \
                               "MOSAIC10CHIPSVALUEv",                                                                  \
                               "MOSAIC10CHIPSVALUE",                                                                   \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10CHIPSSTROBE, UINT32, "MOSAIC10CHIPSSTROBE", 27, 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_ZZP(ok,                                                                                     \
                               si,                                                                                     \
                               offset,                                                                                 \
                               struct_t,                                                                               \
                               printerr,                                                                               \
                               MOSAIC10CHIPSSTROBEv,                                                                   \
                               UINT32,                                                                                 \
                               "MOSAIC10CHIPSSTROBEv",                                                                 \
                               "MOSAIC10CHIPSSTROBE",                                                                  \
                               0 /*flags*/);                                                                           \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10CHIP, UINT32, "MOSAIC10CHIP", 32767, 0 /*flags*/);            \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10CHIPv, UINT32, "MOSAIC10CHIPv", "MOSAIC10CHIP", 0 /*flags*/);  \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10COL, UINT32, "MOSAIC10COL", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10COLv, UINT32, "MOSAIC10COLv", "MOSAIC10COL", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10ROW, UINT32, "MOSAIC10ROW", 32767, 0 /*flags*/);              \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10ROWv, UINT32, "MOSAIC10ROWv", "MOSAIC10ROW", 0 /*flags*/);     \
        EXT_STR_ITEM_INFO2_LIM(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10SNUM, UINT32, "MOSAIC10SNUM", 32767, 0 /*flags*/);            \
        EXT_STR_ITEM_INFO2_ZZP(                                                                                        \
            ok, si, offset, struct_t, printerr, MOSAIC10SNUMv, UINT32, "MOSAIC10SNUMv", "MOSAIC10SNUM", 0 /*flags*/);  \
                                                                                                                       \
    } while (0);
/*******************************************************/
