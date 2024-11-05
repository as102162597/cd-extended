#ifndef __CF_EXECUTOR_HPP__
#define __CF_EXECUTOR_HPP__

#include <memory>

#include "commandexecutor.hpp"

class CfExecutor : public CommandExecutor {
public:
    CfExecutor(Behavior * b = nullptr) : CommandExecutor(b) {}

protected:
    void accept() override { getBehavior()->execute(this); }

};

#endif
