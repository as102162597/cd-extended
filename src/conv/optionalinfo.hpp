#ifndef __OPTIONAL_INFO_HPP__
#define __OPTIONAL_INFO_HPP__

class OptionalInfo final {
public:
    OptionalInfo * setAll(const bool a = true) { all = a; return this; }
    OptionalInfo * setClear(const bool c = true) { clear = c; return this; }
    OptionalInfo * setDefaultList(const bool d = true) { defaultList = d; return this; }
    OptionalInfo * setHelp(const bool h = true) { help = h; return this; }
    OptionalInfo * setList(const bool l = true) { list = l; return this; }
    OptionalInfo * setListAll(const bool l = true) { listAll = l; return this; }
    OptionalInfo * setListNext(const bool l = true) { listNext = l; return this; }
    OptionalInfo * setListPrev(const bool l = true) { listPrev = l; return this; }
    OptionalInfo * setNumber(const bool n = true) { number = n; return this; }
    OptionalInfo * setQuiet(const bool q = true) { quiet = q; return this; }
    OptionalInfo * setVerbose(const bool v = true) { verbose = v; return this; }
    OptionalInfo * setVersion(const bool v = true) { version = v; return this; }

    OptionalInfo * setListVal(const int l) { listVal = l; return this; }
    OptionalInfo * setNumberVal(const int n) { numberVal = n; return this; }

    bool isAll() const { return all; }
    bool isClear() const { return clear; }
    bool isDefaultList() const { return defaultList; }
    bool isHelp() const { return help; }
    bool isList() const { return list; }
    bool isListAll() const { return listAll; }
    bool isListNext() const { return listNext; }
    bool isListPrev() const { return listPrev; }
    bool isNumber() const { return number; }
    bool isQuiet() const { return quiet; }
    bool isVerbose() const { return verbose; }
    bool isVersion() const { return version; }

    int getListVal() const { return listVal; }
    int getNumberVal() const { return numberVal; }

private:
    bool all            = false;
    bool clear          = false;
    bool defaultList    = false;
    bool help           = false;
    bool list           = false;
    bool listAll        = false;
    bool listNext       = false;
    bool listPrev       = false;
    bool number         = false;
    bool quiet          = false;
    bool verbose        = false;
    bool version        = false;

    int listVal;
    int numberVal;

};

#endif
