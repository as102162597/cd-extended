#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>

#include "configoption.hpp"

class Config final {
public:
    // version
    static constexpr const char * version           = "v1.0.0";

    // change directory command
    static constexpr const char * chgDir            = "cd";

    // change back to previous directory command
    static constexpr const char * chgBk2PrevDirCmd  = "cb";

    // change forward to next directory command
    static constexpr const char * chgFw2NxtDirCmd   = "cf";

    // change to a visited directory command
    static constexpr const char * chg2VstDirCmd     = "cv";

    // input mode
    static constexpr const char * inputMode         = "i";

    // output mode
    static constexpr const char * outputMode        = "o";

    // contact information
    static constexpr const char * email             = "as102162597@outlook.com";

    // refer Language in configoption.hpp
    static const cfgopt::lang lang                  = cfgopt::lang::EN_US;

    // maximum storage capacity
    static const int maxStorageCap                  = 999;

    // deleted entries volumn when limit exceeded
    static const int deletionVol                    = 100;

};

using cfg = Config;

#endif
