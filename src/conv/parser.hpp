#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>

class Behavior;
class BehaviorBuilder;
class Executor;
class OptionalInfo;
class StandardInfo;

class Parser final {
public:
    static Parser & getInstance() { static Parser instance; return instance; };

    Parser & parse(const int argc, char * const argv[]);
    Executor * getExecutor() const { return executor; }

private:
    Parser();
    ~Parser();

    enum class ArgumentsIndex : int {
        DIRCTL      = 0,
        CTLMODE     = 1,
        IOMODE      = 2,
        HISTORY     = 3,
        SOURCE      = 4,
        DEST        = 5,
        COUNT       = 6
    };

    using argidx = ArgumentsIndex;

    void initStandardInfo(const char * const argv[]);
    void initOptionalInfo(const int argc, char * const argv[]);
    void createBehavior();
    void createExecutor();
    void setOptionalInfoDefaultListVal(const int argc, const char * const argv[]);
    void setOptionalInfoDefaultNumberVal(const int argc, const char * const argv[]);
    void printTryHelpInfo() const;

    int getDefaultListVal() const;
    int toInt(const std::string & s) const;
    int getListOptArgVal(const char * const argv[]) const;

    const char * getSepOptArgVal(const char * const argv[]) const;
    BehaviorBuilder * createBehaviorBuilders() const;
    Behavior * build(const BehaviorBuilder * builders) const;

    Parser(const Parser &) = delete;
    Parser & operator=(const Parser &) = delete;

    Behavior * behavior;
    Executor * executor;

    StandardInfo * standardInfo;
    OptionalInfo * optionalInfo;

};

#endif
