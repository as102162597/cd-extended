#ifndef __CB_EXECUTOR_HPP__
#define __CB_EXECUTOR_HPP__

#include <memory>

#include "commandexecutor.hpp"

class CbExecutor : public CommandExecutor {
public:
    CbExecutor(Behavior * b = nullptr) : CommandExecutor(b) {}

protected:
    void accept() override { getBehavior()->execute(this); }

};

#endif
