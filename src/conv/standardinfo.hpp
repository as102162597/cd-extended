#ifndef __STANDARD_INFO_HPP__
#define __STANDARD_INFO_HPP__

#include <string>

#include "service.hpp"

class StandardInfo final {
public:
    StandardInfo * setDirCtl(const std::string & d) { dirCtl = d; return this; }
    StandardInfo * setCtlMode(const std::string & c) { ctlMode = c; return this; }
    StandardInfo * setIoMode(const std::string & i) { IoMode = i; return this; }
    StandardInfo * setHistory(const std::string & h) { history = h; return this; }
    StandardInfo * setSource(const std::string & s) { source = s; return this; }
    StandardInfo * setDest(const std::string & d) { dest = d; return this; }

    std::string getDirCtl() const { return dirCtl; }
    std::string getCtlMode() const { return ctlMode; }
    std::string getIoMode() const { return IoMode; }
    std::string getHistory() const { return history; }
    std::string getSource() const { return source; }
    std::string getDest() const { return dest; }

    bool isCd() const { return ctlMode == serv::get("cd"); }
    bool isCb() const { return ctlMode == serv::get("cb"); }
    bool isCf() const { return ctlMode == serv::get("cf"); }
    bool isCv() const { return ctlMode == serv::get("cv"); }

    bool isInput() const { return IoMode == serv::get("inputMode"); }
    bool isOutput() const { return IoMode == serv::get("outputMode"); }

private:
    std::string dirCtl = "";
    std::string ctlMode = "";
    std::string IoMode = "";
    std::string history = "";
    std::string source = "";
    std::string dest = "";

};

#endif
