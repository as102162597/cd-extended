#ifndef __DISPLAY_USAGE_BEHAVIOR_BUILDER__
#define __DISPLAY_USAGE_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "displayusagebehavior.hpp"

class DisplayUsageBehaviorBuilder : public BehaviorBuilder {
public:
    DisplayUsageBehaviorBuilder(OptionalInfo * o, StandardInfo * s) : BehaviorBuilder(o, s) {}

protected:
    bool isMatch() const override { return standardInfo->isOutput() && optionalInfo->isHelp(); }
    Behavior * create() const override { return new DisplayUsageBehavior(standardInfo->getCtlMode()); }

};

#endif
