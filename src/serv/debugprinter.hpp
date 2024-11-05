#ifndef __DEBUG_PRINTER_HPP__
#define __DEBUG_PRINTER_HPP__

#include "printer.hpp"

class DebugPrinter : public Printer {
public:
    DebugPrinter(const lvl::type t = lvl::DEBUG) : Printer(t) {}

protected:
    virtual void output(const std::string & s) const override;

};

#endif
