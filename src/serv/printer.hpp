#ifndef __PRINTER_HPP__
#define __PRINTER_HPP__

#include <memory>
#include <string>

#include "loglevel.hpp"

class Printer {
public:
    Printer(const lvl::type t) : thresholdLogLevel(t) {};
    virtual ~Printer() {}

    Printer * setNext(Printer * p);

    void print(const std::string & s, const lvl::type t) const;

protected:
    virtual void output(const std::string & s) const = 0;

private:
    lvl::type thresholdLogLevel;
    std::shared_ptr<Printer> next;

};

#endif
