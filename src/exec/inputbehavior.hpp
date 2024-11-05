#ifndef __INPUT_BEHAVIOR_HPP__
#define __INPUT_BEHAVIOR_HPP__

#include "outputbehavior.hpp"

class InputBehavior : public OutputBehavior {
public:
    InputBehavior(
        const std::filesystem::path & p,
        const std::string & sD,
        const std::string & tD,
        const int t = 0
    ) : OutputBehavior(p, sD, t), sourceDirectory(sD), targetDirectory(tD) {}

    InputBehavior(
        const std::filesystem::path & p,
        const int t = 0,
        const std::string & sD = "/",
        const std::string & tD = "/"
    ) : InputBehavior(p, sD, tD, t) {}

    void execute(CdExecutor * e) override;
    void execute(CbExecutor * e) override;
    void execute(CfExecutor * e) override;
    void execute(CvExecutor * e) override;

    InputBehavior * setSourceDirectory(const std::string & s) { sourceDirectory = s; return this; };
    InputBehavior * setTargetDirectory(const std::string & t) { targetDirectory = t; return this; };
    InputBehavior * setTarget(const int t) { OutputBehavior::setTarget(t); return this; };

private:
    void gotoTargetDirectory(const fp & f);
    void assertSource() const;
    bool isSourceValid() const;

    std::string sourceDirectory;
    std::string targetDirectory;

};

#endif
