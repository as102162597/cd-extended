#include "config.hpp"
#include "setting.hpp"

#include "quietprinter.hpp"
#include "errorprinter.hpp"
#include "docprinter.hpp"
#include "infoprinter.hpp"
#include "debugprinter.hpp"

#include "enustranslator.hpp"
#include "zhtwtranslator.hpp"

Setting::Setting() {
    setArgs();
    setVals();
    setPrinter();
    setTranslator();
}

Setting & Setting::getInstance() {
    static Setting instance;
    return instance;
}

Printer * Setting::getPrinter() {
    return printerPointer;
}

Translator * Setting::getTranslator() {
    return translatorPointer.get();
}

void Setting::setPrinter(const lvl::type t) {
    using enum lvl::type;

    delete printerPointer;

    Printer * p { nullptr };
    switch (t) {
        case DEBUG:
            p = new DebugPrinter();
        case INFO:
            p = (new InfoPrinter())->setNext(p);
        case DOC:
            p = (new DocPrinter())->setNext(p);
        case ERROR:
            p = (new ErrorPrinter())->setNext(p);
        default:
            printerPointer = (new QuietPrinter())->setNext(p);
    }
}

void Setting::setArgs() {
    setArg("version", cfg::version);
    setArg("cd", cfg::chgDir);
    setArg("cb", cfg::chgBk2PrevDirCmd);
    setArg("cf", cfg::chgFw2NxtDirCmd);
    setArg("cv", cfg::chg2VstDirCmd);
    setArg("inputMode", cfg::inputMode);
    setArg("outputMode", cfg::outputMode);
    setArg("email", cfg::email);
}

void Setting::setVals() {
    setVal("maxStorageCap", cfg::maxStorageCap);
    setVal("deletionVol", cfg::deletionVol);
}

void Setting::setPrinter() {
    printerPointer = new QuietPrinter();
}

void Setting::setTranslator() {
    using enum cfgopt::lang;

    switch (cfg::lang) {
        case ZH_TW:
            translatorPointer = std::make_shared<ZhTwTranslator>();
            break;
        default:
            translatorPointer = std::make_shared<EnUsTranslator>();
    };
}
