#include "printer.hpp"

Printer * Printer::setNext(Printer * p) {
    if (next) {
        next->setNext(p);
    } else {
        next.reset(p);
    }
    return this;
}

void Printer::print(const std::string & s, const lvl::type t) const {
    if (t <= thresholdLogLevel) {
        output(s);
    } else if (next) {
        next->print(s, t);
    }
}
