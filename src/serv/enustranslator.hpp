#ifndef __EN_US_TRANSLATOR_HPP__
#define __EN_US_TRANSLATOR_HPP__

#include "translator.hpp"

class EnUsTranslator : public Translator {
public:
    virtual std::string translate(const phrz p) const override {
        using enum phrz;

        switch (p) {
            case CB_AT_1ST_DIRECTORY:       return "Already at the first directory";
            case CF_AT_LAST_DIRECTORY:      return "Already at the last directory";
            case CHANGE_TO:                 return "Change to directory: ";
            case CHANGE_DIRECTORY_FAIL:     return "Failed to switch to the target directory.";
            case CLEARED_NOTIFICATION:      return "Visited history directory records have been cleared...";
            case CURRENT_DIRECTORY:         return "Current Directory";
            case INVALID_CTLMODE_ARG:       return "Invalid CTLMODE argument.";
            case INVALID_FILE_FORMAT:       return "invalid file format";
            case INVALID_NUMBER:            return "Invalid number.";
            case INVALID_SOURCE:            return "invalid source directory";
            case MISSING_OPERAND:           return "missing operand";
            case OPEN_FILE_FAIL:            return "unable to open the file";
            case OUT_OF_RANGE:              return "The number is out of range.";
            case HELLO_WORLD:               return "hello, world.";
            case USE_NULL_PTR:              return "null pointer dereference";
            default:                        return "<unknown message>";
        }
    }
};

#endif
