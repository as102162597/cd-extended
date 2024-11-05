#ifndef __COMMAND_EXECUTOR_HPP__
#define __COMMAND_EXECUTOR_HPP__

#include <memory>

#include "behavior.hpp"
#include "executor.hpp"

class CommandExecutor : public Executor {
public:
    CommandExecutor(Behavior * b) { setBehavior(b); }

    void execute() override { if (behavior) accept(); };
    void setBehavior(Behavior * b) { behavior.reset(b); }

protected:
    virtual void accept() = 0;
    Behavior * getBehavior() { return behavior.get(); }

private:
    std::shared_ptr<Behavior> behavior;

};

#endif
