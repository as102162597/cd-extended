#ifndef __CV_EXECUTOR_HPP__
#define __CV_EXECUTOR_HPP__

#include <memory>

#include "commandexecutor.hpp"

class CvExecutor : public CommandExecutor {
public:
    CvExecutor(Behavior * b = nullptr) : CommandExecutor(b) {}

protected:
    void accept() override { getBehavior()->execute(this); }

};

#endif
