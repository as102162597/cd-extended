#ifndef __INFO_PRINTER_HPP__
#define __INFO_PRINTER_HPP__

#include "printer.hpp"

class InfoPrinter : public Printer {
public:
    InfoPrinter(const lvl::type t = lvl::INFO) : Printer(t) {}

protected:
    virtual void output(const std::string & s) const override;

};

#endif
