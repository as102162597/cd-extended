#ifndef __LIST_BEHAVIOR_BUILDER__
#define __LIST_BEHAVIOR_BUILDER__

#include "behaviorbuilder.hpp"
#include "listbehavior.hpp"

class ListBehaviorBuilder : public BehaviorBuilder {
public:
    ListBehaviorBuilder(OptionalInfo * o, StandardInfo * s, const bool a = false)
        : BehaviorBuilder(o, s), allowDefaultList(a) {}

protected:
    bool isMatch() const override {
        return standardInfo->isOutput()
            && (allowDefaultList ? optionalInfo->isDefaultList() : optionalInfo->isList());
    }

    Behavior * create() const override {
        ListBehavior * b = new ListBehavior(
            standardInfo->getHistory(),
            standardInfo->getSource(),
            optionalInfo->getListVal()
        );

        if (optionalInfo->isAll())
            b->setAllInfo();

        if (optionalInfo->isListNext())
            b->setNext();

        if (optionalInfo->isListPrev())
            b->setPrev();

        return b;
    }

private:
    bool allowDefaultList;

};

#endif
