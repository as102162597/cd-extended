#ifndef __DOC_PRINTER_HPP__
#define __DOC_PRINTER_HPP__

#include "printer.hpp"

class DocPrinter : public Printer {
public:
    DocPrinter(const lvl::type t = lvl::DOC) : Printer(t) {}

protected:
    virtual void output(const std::string & s) const override;

};

#endif
