#include <iostream>

#include "debugprinter.hpp"

#define TAG "[DEBUG]"
#define GAP " "

void DebugPrinter::output(const std::string & s) const {
    std::cout << TAG << GAP << s << std::endl;
}
