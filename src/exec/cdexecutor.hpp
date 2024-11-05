#ifndef __CD_EXECUTOR_HPP__
#define __CD_EXECUTOR_HPP__

#include <memory>

#include "commandexecutor.hpp"

class CdExecutor : public CommandExecutor {
public:
    CdExecutor(Behavior * b = nullptr) : CommandExecutor(b) {}

protected:
    void accept() override { getBehavior()->execute(this); }

};

#endif
