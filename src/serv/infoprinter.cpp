#include <iostream>

#include "infoprinter.hpp"

#define TAG "[INFO]"
#define GAP " "

void InfoPrinter::output(const std::string & s) const {
    std::cout << TAG << GAP << s << std::endl;
}
