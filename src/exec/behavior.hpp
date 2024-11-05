#ifndef __BEHAVIOR_HPP__
#define __BEHAVIOR_HPP__

class CdExecutor;
class CbExecutor;
class CfExecutor;
class CvExecutor;

class Behavior {
public:
    virtual ~Behavior() {}
    virtual void execute(CdExecutor * e) = 0;
    virtual void execute(CbExecutor * e) = 0;
    virtual void execute(CfExecutor * e) = 0;
    virtual void execute(CvExecutor * e) = 0;
};

#endif
