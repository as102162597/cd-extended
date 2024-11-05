#ifndef __CLEAR_BEHAVIOR_HPP__
#define __CLEAR_BEHAVIOR_HPP__

#include "editfilebehavior.hpp"

class ClearBehavior : public EditFileBehavior {
public:
    ClearBehavior(const std::filesystem::path & p, const std::string s) : EditFileBehavior(p, s) {}

    void execute(CdExecutor * e) override {}
    void execute(CbExecutor * e) override { clearPrev(); cleardNotification(); }
    void execute(CfExecutor * e) override { clearNext(); cleardNotification(); }
    void execute(CvExecutor * e) override { clearPrev(); clearNext(); cleardNotification(); }

private:
    void clearPrev();
    void clearNext();
    void cleardNotification();

};

#endif
