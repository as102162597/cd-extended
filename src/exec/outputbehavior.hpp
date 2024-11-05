#ifndef __OUTPUT_BEHAVIOR_HPP__
#define __OUTPUT_BEHAVIOR_HPP__

#include "editfilebehavior.hpp"

class OutputBehavior : public EditFileBehavior {
public:
    OutputBehavior(const std::filesystem::path & p, const std::string s, const int t = 0)
        : EditFileBehavior(p, s) { setTarget(t); }

    virtual void execute(CdExecutor * e) override {}
    virtual void execute(CbExecutor * e) override;
    virtual void execute(CfExecutor * e) override;
    virtual void execute(CvExecutor * e) override;

    virtual OutputBehavior * setTarget(const int t) { target = std::max(t, 0); return this; };

protected:
    int getCbTargetIndexInVector() const;
    int getCfTargetIndexInVector() const;
    int getCvTargetIndexInVector() const;

    int target;

};

#endif
