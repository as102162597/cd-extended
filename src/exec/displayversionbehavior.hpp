#ifndef __DISPLAY_VERSION_BEHAVIOR_HPP__
#define __DISPLAY_VERSION_BEHAVIOR_HPP__

#include <string>

#include "behavior.hpp"
#include "service.hpp"

#define CB_CMD      "cb"
#define CF_CMD      "cf"
#define CV_CMD      "cv"
#define VERSION     "version"
#define GAP         " "

class DisplayVersionBehavior : public Behavior {
public:
    void execute(CdExecutor * e) override {}
    void execute(CbExecutor * e) override { serv::doc(serv::get(CV_CMD) + GAP + serv::get(VERSION)); }
    void execute(CfExecutor * e) override { serv::doc(serv::get(CV_CMD) + GAP + serv::get(VERSION)); }
    void execute(CvExecutor * e) override { serv::doc(serv::get(CV_CMD) + GAP + serv::get(VERSION)); }
};

#endif
