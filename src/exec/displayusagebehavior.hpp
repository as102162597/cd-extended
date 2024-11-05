#ifndef __DISPLAY_USAGE_BEHAVIOR_HPP__
#define __DISPLAY_USAGE_BEHAVIOR_HPP__

#include <string>

#include "behavior.hpp"

class DisplayUsageBehavior : public Behavior {
public:
    DisplayUsageBehavior(const std::string & s) : currentCommand(s) {}

    void execute(CdExecutor * e) override {}
    void execute(CbExecutor * e) override;
    void execute(CfExecutor * e) override;
    void execute(CvExecutor * e) override;

private:
    void displayUsage(const std::string & u) const;
    std::string replaceAll(
        const std::string & source,
        const std::string & target,
        const std::string & replacement
    ) const;

    std::string currentCommand;

};

#endif
