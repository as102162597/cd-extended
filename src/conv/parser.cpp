#include <getopt.h>
#include <string>

#include "cbexecutor.hpp"
#include "cdexecutor.hpp"
#include "cfexecutor.hpp"
#include "cvexecutor.hpp"

#include "clearbehaviorbuilder.hpp"
#include "displayusagebehaviorbuilder.hpp"
#include "displayversionbehaviorbuilder.hpp"
#include "inputbehaviorbuilder.hpp"
#include "listbehaviorbuilder.hpp"
#include "outputbehaviorbuilder.hpp"

#include "parser.hpp"
#include "service.hpp"
#include "optionalinfo.hpp"
#include "standardinfo.hpp"

#define CD_CMD                  "cd"
#define CB_CMD                  "cb"
#define CF_CMD                  "cf"
#define CV_CMD                  "cv"

#define OPT_VERSION_VAL         1
#define OPT_LIST_NEXT           2
#define OPT_LIST_PREV           3
#define OPT_LIST_ALL            4

#define DEFAULT_LIST_VAL_CB_CF  9
#define DEFAULT_LIST_VAL_CV     4

static struct option longOpts[] {
    { "all",        no_argument,        nullptr,    'a'             },
    { "clear",      no_argument,        nullptr,    'c'             },
    { "list",       optional_argument,  nullptr,    'l'             },
    { "list-next",  optional_argument,  nullptr,    OPT_LIST_NEXT   },
    { "list-prev",  optional_argument,  nullptr,    OPT_LIST_PREV   },
    { "list-all",   no_argument,        nullptr,    OPT_LIST_ALL    },
    { "number",     required_argument,  nullptr,    'n'             },
    { "quiet",      no_argument,        nullptr,    'q'             },
    { "verbose",    no_argument,        nullptr,    'v'             },
    { "help",       no_argument,        nullptr,    'h'             },
    { "version",    no_argument,        nullptr,    OPT_VERSION_VAL },
    { 0,            0,                  0,          0               }
};

static const char * optstring { "acl::n:qvh" };

Parser::Parser() { standardInfo = new StandardInfo(); optionalInfo = new OptionalInfo(); }

Parser::~Parser() { delete standardInfo; delete optionalInfo; }

Parser & Parser::parse(const int argc, char * const argv[]) {
    const int fixArgCnt { static_cast<int>(argidx::COUNT) - 1 };

    if (argc >= fixArgCnt) {
        serv::setPrinter(lvl::DOC);
        initStandardInfo(argv);
        initOptionalInfo(argc - fixArgCnt, argv + fixArgCnt);
        createBehavior();
        createExecutor();
    }

    return *this;
}

void Parser::initStandardInfo(const char * const argv[]) {
    standardInfo->setDirCtl(argv[static_cast<int>(argidx::DIRCTL)])
        ->setCtlMode(argv[static_cast<int>(argidx::CTLMODE)])
        ->setIoMode(argv[static_cast<int>(argidx::IOMODE)])
        ->setHistory(argv[static_cast<int>(argidx::HISTORY)])
        ->setSource(argv[static_cast<int>(argidx::SOURCE)])
        ->setDest(argv[static_cast<int>(argidx::DEST)]);
}

void Parser::initOptionalInfo(const int argc, char * const argv[]) {
    setOptionalInfoDefaultListVal(argc, argv);
    setOptionalInfoDefaultNumberVal(argc, argv);

    int opt;
    while ((opt = getopt_long(argc, argv, optstring, longOpts, nullptr)) != -1) {
        switch (opt) {
            case 'a':
                optionalInfo->setAll();
                break;
            case 'c':
                optionalInfo->setClear();
                break;
            case 'l':
                optionalInfo->setListVal(getListOptArgVal(argv))->setList();
                break;
            case OPT_LIST_NEXT:
                optionalInfo->setListVal(getListOptArgVal(argv))->setList()->setListNext();
                break;
            case OPT_LIST_PREV:
                optionalInfo->setListVal(getListOptArgVal(argv))->setList()->setListPrev();
                break;
            case OPT_LIST_ALL:
                optionalInfo->setListVal(INT_MAX >> 2)->setList()->setListAll();
                break;
            case 'n':
                optionalInfo->setNumberVal(toInt(optarg))->setNumber();
                break;
            case 'q':
                serv::setPrinter(lvl::OFF);
                optionalInfo->setQuiet();
                break;
            case 'v':
                serv::setPrinter(lvl::INFO);
                optionalInfo->setVerbose();
                break;
            case 'h':
                optionalInfo->setHelp();
                break;
            case OPT_VERSION_VAL:
                optionalInfo->setVersion();
                break;
            case '?':
            default:
                printTryHelpInfo();
                serv::terminate();
                break;
        }
    }
}

void Parser::createBehavior() {
    BehaviorBuilder * builders = createBehaviorBuilders();
    behavior = build(builders);
    delete builders;
}

void Parser::createExecutor() {
    std::string && c { standardInfo->getCtlMode() };

    if (c == serv::get(CD_CMD)) {
        executor = new CdExecutor(behavior);
    } else if (c == serv::get(CB_CMD)) {
        executor = new CbExecutor(behavior);
    } else if (c == serv::get(CF_CMD)) {
        executor = new CfExecutor(behavior);
    } else if (c == serv::get(CV_CMD)) {
        executor = new CvExecutor(behavior);
    } else {
        serv::terminate(phrz::INVALID_CTLMODE_ARG);
    }
}

void Parser::setOptionalInfoDefaultListVal(const int argc, const char * const argv[]) {
    optionalInfo->setListVal(getDefaultListVal());
    if (standardInfo->isCv()) {
        optionalInfo->setDefaultList();
        if (argc > 1 && argv[1] != nullptr && argv[1][0] != '-')
            optionalInfo->setListVal(toInt(argv[1]));
    }
}

void Parser::setOptionalInfoDefaultNumberVal(const int argc, const char * const argv[]) {
    if (!standardInfo->isCv()) {
        if (argc == 1)
            optionalInfo->setNumberVal(1)->setNumber();
        else if (argv[1] != nullptr && argv[1][0] != '-')
            optionalInfo->setNumberVal(toInt(argv[1]))->setNumber();
    }
}

void Parser::printTryHelpInfo() const {
    serv::doc(std::string("Try '") + standardInfo->getCtlMode() + " --help' for more information.");
}

int Parser::getDefaultListVal() const {
    return standardInfo->isCv() ? DEFAULT_LIST_VAL_CV : DEFAULT_LIST_VAL_CB_CF;
}

int Parser::toInt(const std::string & s) const {
    int ret { 0 };

    try {
        ret = std::stoi(s);
    } catch (const std::out_of_range & e) {
        serv::terminate(standardInfo->getCtlMode() + ": " + serv::tr(phrz::OUT_OF_RANGE));
    } catch (const std::exception & e) {
        serv::terminate(standardInfo->getCtlMode() + ": " + serv::tr(phrz::INVALID_NUMBER));
    }

    return ret;
}

int Parser::getListOptArgVal(const char * const argv[]) const {
    const char * optionalArgument;
    return (optionalArgument = getSepOptArgVal(argv)) == nullptr
        ? getDefaultListVal()
        : toInt(optionalArgument);
}

const char * Parser::getSepOptArgVal(const char * const argv[]) const {
    return optarg == nullptr && argv[optind] != nullptr && argv[optind][0] != '-'
        ? argv[optind++]
        : optarg;
}

BehaviorBuilder * Parser::createBehaviorBuilders() const {
    return (new DisplayUsageBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new DisplayVersionBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new DisplayVersionBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new ListBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new ClearBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new OutputBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new InputBehaviorBuilder(optionalInfo, standardInfo))
        ->setNext(new ListBehaviorBuilder(optionalInfo, standardInfo, true));
}

Behavior * Parser::build(const BehaviorBuilder * builders) const {
    Behavior * b { builders->build() };

    if (b == nullptr) {
        serv::doc(standardInfo->getCtlMode() + ": " + serv::tr(phrz::MISSING_OPERAND));
        printTryHelpInfo();
        serv::terminate();
    }

    return b;
}
