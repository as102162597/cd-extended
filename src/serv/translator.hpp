#ifndef __TRANSLATOR_HPP__
#define __TRANSLATOR_HPP__

#include <string>

#include "phrase.hpp"

class Translator {
public:
    virtual ~Translator() {}
    virtual std::string translate(const phrz p) const = 0;
};

#endif
