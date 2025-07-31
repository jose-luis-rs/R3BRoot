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

// ----------------------------------------------------------------------
// -----                          R3BLogger                         -----
// -----             Created 15/12/21 by J.L. Rodriguez-Sanchez     -----
// ----------------------------------------------------------------------

#pragma once

#include <FairLogger.h>
#include <sstream>
#include <string>
#include <Rtypes.h>

#define R3BLOG(severity, message)                                                                             \
    do                                                                                                        \
    {                                                                                                         \
        std::string r3b_file(__FILE__);                                                                       \
        std::stringstream r3b_ss;                                                                             \
        r3b_ss << r3b_file.substr(r3b_file.find_last_of("/\\") + 1) << ":" << __LINE__ << ":" << __FUNCTION__ \
               << "(): " << message;                                                                          \
        LOG(severity) << r3b_ss.str();                                                                        \
    } while (0)

#define R3BLOG_IF(severity, condition, message)                                                                   \
    do                                                                                                            \
    {                                                                                                             \
        if (condition)                                                                                            \
        {                                                                                                         \
            std::string r3b_file(__FILE__);                                                                       \
            std::stringstream r3b_ss;                                                                             \
            r3b_ss << r3b_file.substr(r3b_file.find_last_of("/\\") + 1) << ":" << __LINE__ << ":" << __FUNCTION__ \
                   << "(): " << message;                                                                          \
            LOG(severity) << r3b_ss.str();                                                                        \
        }                                                                                                         \
    } while (0)

class R3BLogger : public FairLogger
{
  private:
    R3BLogger();
    ~R3BLogger() = default;

  public:
    ClassDefOverride(R3BLogger, 0);
};
