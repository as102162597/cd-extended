#ifndef __INPUT_BEHAVIOR_BUILDER__
#define __INPUT_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "inputbehavior.hpp"

class InputBehaviorBuilder : public BehaviorBuilder {
public:
    InputBehaviorBuilder(OptionalInfo * o, StandardInfo * s) : BehaviorBuilder(o, s) {}

protected:
    bool isMatch() const override { return standardInfo->isInput() && optionalInfo->isNumber(); }

    Behavior * create() const override {
        return new InputBehavior(
            standardInfo->getHistory(),
            standardInfo->getSource(),
            standardInfo->getDest(),
            optionalInfo->getNumberVal()
        );
    }

};

#endif
