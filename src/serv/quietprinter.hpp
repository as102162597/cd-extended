#ifndef __QUIET_PRINTER_HPP__
#define __QUIET_PRINTER_HPP__

#include "printer.hpp"

class QuietPrinter : public Printer {
public:
    QuietPrinter(const lvl::type t = lvl::off()) : Printer(t) {}

protected:
    virtual void output(const std::string & s) const override {};

};

#endif
