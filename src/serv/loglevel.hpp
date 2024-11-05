#ifndef __LOG_LEVEL_HPP__
#define __LOG_LEVEL_HPP__

#include <climits>

class LogLevel final {
public:
    enum type {
        OFF,
        ERROR,
        DOC,
        INFO,
        DEBUG
    };

private:
    friend class QuietPrinter;
    static type off() { return static_cast<type>(INT_MIN); }

};

using lvl = LogLevel;

#endif
