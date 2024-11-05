#ifndef __SETTING_HPP__
#define __SETTING_HPP__

#include <memory>
#include <unordered_map>

#include "printer.hpp"
#include "translator.hpp"

class Setting final {
public:
    ~Setting() { delete printerPointer; }

    static Setting & getInstance();

    void setArg(const std::string & k, const std::string & v) { configurationArguments[k] = v; }
    void setVal(const std::string & k, const int v) { configurationValues[k] = v; }

    std::string getArg(const std::string & k) { return configurationArguments[k]; }
    int getVal(const std::string & k) { return configurationValues[k]; }

    Printer * getPrinter();
    Translator * getTranslator();

    void setPrinter(const lvl::type t);

private:
    Setting();

    void setArgs();
    void setVals();
    void setPrinter();
    void setTranslator();

    std::string translate(const phrz p) const;

    Setting(const Setting &) = delete;
    void operator=(const Setting &) = delete;

    Printer * printerPointer = nullptr;
    std::shared_ptr<Translator> translatorPointer;
    std::unordered_map<std::string, std::string> configurationArguments;
    std::unordered_map<std::string, int> configurationValues;

};

#endif
