#ifndef __EXECUTOR_HPP__
#define __EXECUTOR_HPP__

class Executor {
public:
    virtual ~Executor() {}
    virtual void execute() = 0;
};

#endif
