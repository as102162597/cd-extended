#include <iostream>

#include "errorprinter.hpp"

#define TAG "[ERROR]"
#define GAP " "

void ErrorPrinter::output(const std::string & s) const {
    std::cerr << TAG << GAP << s << std::endl;
}
