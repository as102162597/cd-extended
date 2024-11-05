#ifndef __LIST_BEHAVIOR_HPP__
#define __LIST_BEHAVIOR_HPP__

#include "editfilebehavior.hpp"

class ListBehavior : public EditFileBehavior {
public:
    ListBehavior(const std::filesystem::path & p, const std::string s, const int c = 9)
        : EditFileBehavior(p, s) { setCount(c); }

    void execute(CdExecutor * e) override {}
    void execute(CbExecutor * e) override { executeCbExecutor(); }
    void execute(CfExecutor * e) override { executeCfExecutor(); }
    void execute(CvExecutor * e) override;

    ListBehavior * setAllInfo() { isAllInfo = true; return this; }
    ListBehavior * setCount(const int c) { count = std::max(c, 0); return this; }
    ListBehavior * setPrev() { mode = Mode::PREV; return this; }
    ListBehavior * setNext() { mode = Mode::NEXT; return this; }

private:
    void executeCbExecutor() const;
    void executeCfExecutor() const;
    void executeCvExecutor() const;

    std::string getCurrentDirectoryNote() const;

    enum class Mode {
        ORIGINAL,
        PREV,
        NEXT
    };

    int count;
    bool isAllInfo = false;
    Mode mode = Mode::ORIGINAL;

};

#endif
