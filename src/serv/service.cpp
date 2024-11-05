#include "service.hpp"
#include "setting.hpp"

void Service::set(const std::string & k, const std::string & v) {
    Setting::getInstance().setArg(k, v);
}

void Service::setVal(const std::string & k, const int v) {
    Setting::getInstance().setVal(k, v);
}

std::string Service::get(const std::string & k) {
    return Setting::getInstance().getArg(k);
}

int Service::getVal(const std::string & k) {
    return Setting::getInstance().getVal(k);
}

std::string Service::where(const char * f, const int l, const std::string s) {
    return std::string(f) + ":" + std::to_string(l) + (s.length() ? ": " + s : s);
}

std::string Service::translate(const phrz p) {
    return Setting::getInstance().getTranslator()->translate(p);
}

void Service::out(const std::string & s, const lvl::type t) {
    Setting::getInstance().getPrinter()->print(s, t);
}

void Service::err(const std::string & s) {
    out(s, lvl::ERROR);
}

void Service::doc(const std::string & s) {
    out(s, lvl::DOC);
}

void Service::inf(const std::string & s) {
    out(s, lvl::INFO);
}

void Service::dbg(const std::string & s) {
    out(s, lvl::DEBUG);
}

void Service::terminate(const int r) {
    exit(r);
}

void Service::terminate(const std::string & s, const int r) {
    err(s);
    terminate(r);
}

void Service::setPrinter(const lvl::type t) {
    Setting::getInstance().setPrinter(t);
}
