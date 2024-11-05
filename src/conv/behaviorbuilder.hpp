#ifndef __BEHAVIOR_BUILDER_HPP__
#define __BEHAVIOR_BUILDER_HPP__

#include "optionalinfo.hpp"
#include "standardinfo.hpp"

class Behavior;

class BehaviorBuilder {
public:
    BehaviorBuilder(OptionalInfo * o, StandardInfo * s) : optionalInfo(o), standardInfo(s) {}
    virtual ~BehaviorBuilder() { delete next; }

    Behavior * build() const
        { return isMatch() ? create() : (next == nullptr ? nullptr : next->build()); }

    BehaviorBuilder * setNext(BehaviorBuilder * b)
        { if (next == nullptr) next = b; else next->setNext(b); return this; }

protected:
    virtual bool isMatch() const = 0;
    virtual Behavior * create() const = 0;

    OptionalInfo * optionalInfo;
    StandardInfo * standardInfo;

private:
    BehaviorBuilder * next = nullptr;

};

#endif
