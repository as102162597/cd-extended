#include <iomanip>
#include <sstream>

#include "footprint.hpp"
#include "service.hpp"

#define SETW        4
#define GAP         " "
#define DIRECTORY   "<directory>"

Footprint::Footprint(const std::string & s) : backSteps(invalid), forwardSteps(invalid) {
    const size_t pos { s.find(' ') };
    if (pos != std::string::npos) {
        setIndex(std::stoi(s.substr(0, pos)));
        setDirectory(s.substr(pos + 1));
    }
}

Footprint::Footprint(const int i, const std::filesystem::path & d)
    : Footprint(i, invalid, invalid, d) {}

Footprint::Footprint(const int i, const int b, const int f, const std::filesystem::path & d)
    : index(i), backSteps(b), forwardSteps(f), directory(d) {}

std::string Footprint::field(
    const bool showIndex,
    const bool showBackSteps,
    const bool showForwardSteps
) {
    std::ostringstream oss;

    if (showIndex)
        oss << std::setw(SETW) << std::left << std::string("<") + serv::get("cv") + ">" << GAP;
    if (showBackSteps)
        oss << std::setw(SETW) << std::left << std::string("<") + serv::get("cb") + ">" << GAP;
    if (showForwardSteps)
        oss << std::setw(SETW) << std::left << std::string("<") + serv::get("cf") + ">" << GAP;

    return oss.str() + DIRECTORY;
}

std::string Footprint::field(const Info i) {
    switch (i) {
        case INDEX:         return field(true);
        case BACKSTEPS:     return field(false, true);
        case FORWARDSTEPS:  return field(false, false, true);
        default:            break;
    }
    return field(true, true, true);
}

std::string Footprint::str(
    const bool showIndex,
    const bool showBackSteps,
    const bool showForwardSteps
) const {
    std::ostringstream oss;

    if (showIndex)
        oss << std::setw(SETW) << std::left << index << GAP;
    if (showBackSteps)
        oss << std::setw(SETW) << std::left << (backSteps <= 0 ? "-" : std::to_string(backSteps)) << GAP;
    if (showForwardSteps)
        oss << std::setw(SETW) << std::left
            << (forwardSteps <= 0 ? "-" : std::to_string(forwardSteps)) << GAP;

    return oss.str() + directory.c_str();
}

std::string Footprint::str(const Info i) const {
    switch (i) {
        case INDEX:         return str(true);
        case BACKSTEPS:     return str(false, true);
        case FORWARDSTEPS:  return str(false, false, true);
        default:            break;
    }
    return str(true, true, true);
}
