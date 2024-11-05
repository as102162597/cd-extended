#ifndef __FOOTPRINT_HPP__
#define __FOOTPRINT_HPP__

#include <climits>
#include <filesystem>

class Footprint final {
public:
    Footprint(const std::string & s);
    Footprint(const int i, const std::filesystem::path & d);
    Footprint(const int i, const int b, const int f, const std::filesystem::path & d);

    enum Info {
        INDEX,
        BACKSTEPS,
        FORWARDSTEPS,
        ALL
    };

    static std::string field(
        const bool showIndex = false,
        const bool showBackSteps = false,
        const bool showForwardSteps = false
    );
    static std::string field(const Info i);

    static const int invalid = INT_MIN;

    std::string str(
        const bool showIndex = false,
        const bool showBackSteps = false,
        const bool showForwardSteps = false
    ) const;
    std::string str(const Info i) const;

    bool operator<(const Footprint & f) const { return index < f.getIndex(); }
    bool operator>(const Footprint & f) const { return index > f.getIndex(); }
    bool operator==(const Footprint & f) const { return index == f.getIndex(); }
    bool operator<=(const Footprint & f) const { return operator<(f) || operator==(f); }
    bool operator>=(const Footprint & f) const { return operator>(f) || operator==(f); }
    bool operator!=(const Footprint & f) const { return !operator==(f); }

    Footprint & setIndex(const int i) { index = i; return *this; }
    Footprint & setBackSteps(const int b) { backSteps = b; return *this; }
    Footprint & setForwardSteps(const int f) { forwardSteps = f; return *this; }
    Footprint & setDirectory(const std::filesystem::path & d) { directory = d; return *this; }

    int getIndex() const { return index; }
    int getBackSteps() const { return backSteps; }
    int getForwardSteps() const { return forwardSteps; }
    std::filesystem::path getDirectory() const { return directory; }

private:
    int index;
    int backSteps;
    int forwardSteps;
    std::filesystem::path directory;

};

using fp = Footprint;

#endif
