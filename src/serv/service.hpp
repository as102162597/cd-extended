#ifndef __SERVICE_HPP__
#define __SERVICE_HPP__

#include <string>

#include "loglevel.hpp"
#include "phrase.hpp"

class Service final {
public:
    static void set(const std::string & k, const std::string & v);
    static void setVal(const std::string & k, const int v);

    static std::string get(const std::string & k);
    static int getVal(const std::string & k);

    static std::string where(const char * f, const int l, const std::string s = "");
    static std::string where(const char * f, const int l, const phrz p) { return where(f, l, tr(p)); }

    static std::string translate(const phrz p);
    static std::string tr(const phrz p) { return translate(p); }

    static void out(const std::string & s, const lvl::type t = lvl::INFO);
    static void out(const phrz p, const lvl::type t = lvl::INFO) { out(tr(p), t); }

    static void err(const std::string & s);
    static void err(const phrz p) { err(tr(p)); }

    static void doc(const std::string & s);
    static void doc(const phrz p) { doc(tr(p)); }

    static void inf(const std::string & s);
    static void inf(const phrz p) { inf(tr(p)); }

    static void dbg(const std::string & s);
    static void dbg(const phrz p) { dbg(tr(p)); }
    static void dbg(const char * f, const int l, const std::string s = "") { dbg(where(f, l, s)); }
    static void dbg(const char * f, const int l, const phrz p) { dbg(where(f, l, p)); }

    static void terminate(const int r = EXIT_FAILURE);
    static void terminate(const std::string & s, const int r = EXIT_FAILURE);
    static void terminate(const phrz p, const int r = EXIT_FAILURE) { terminate(tr(p), r); }

    static void setPrinter(const lvl::type t);
    static lvl::type getPrinterInfo(const lvl::type t);

private:
    Service() = delete;

};

using serv = Service;

#endif
