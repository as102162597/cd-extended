#ifndef __ERROR_PRINTER_HPP__
#define __ERROR_PRINTER_HPP__

#include "printer.hpp"

class ErrorPrinter : public Printer {
public:
    ErrorPrinter(const lvl::type t = lvl::ERROR) : Printer(t) {}

protected:
    virtual void output(const std::string & s) const override;

};

#endif
