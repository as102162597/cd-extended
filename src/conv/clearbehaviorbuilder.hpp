#ifndef __CLEAR_BEHAVIOR_BUILDER__
#define __CLEAR_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "clearbehavior.hpp"

class ClearBehaviorBuilder : public BehaviorBuilder {
public:
    ClearBehaviorBuilder(OptionalInfo * o, StandardInfo * s) : BehaviorBuilder(o, s) {}

protected:
    bool isMatch() const override { return standardInfo->isOutput() && optionalInfo->isClear(); }

    Behavior * create() const override {
        return (new ClearBehavior(standardInfo->getHistory(), standardInfo->getSource()));
    }

};

#endif
