#ifndef __DISPLAY_VERSION_BEHAVIOR_BUILDER__
#define __DISPLAY_VERSION_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "displayversionbehavior.hpp"

class DisplayVersionBehaviorBuilder : public BehaviorBuilder {
public:
    DisplayVersionBehaviorBuilder(OptionalInfo * o, StandardInfo * s) : BehaviorBuilder(o, s) {}

protected:
    bool isMatch() const override { return standardInfo->isOutput() && optionalInfo->isVersion(); }
    Behavior * create() const override { return new DisplayVersionBehavior(); }

};

#endif
