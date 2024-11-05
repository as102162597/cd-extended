#ifndef __OUTPUT_BEHAVIOR_BUILDER__
#define __OUTPUT_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "outputbehavior.hpp"

class OutputBehaviorBuilder : public BehaviorBuilder {
public:
    OutputBehaviorBuilder(OptionalInfo * o, StandardInfo * s) : BehaviorBuilder(o, s) {}

protected:
    bool isMatch() const override { return standardInfo->isOutput() && optionalInfo->isNumber(); }

    Behavior * create() const override {
        return new OutputBehavior(
            standardInfo->getHistory(),
            standardInfo->getSource(),
            optionalInfo->getNumberVal()
        );
    }

};

#endif
