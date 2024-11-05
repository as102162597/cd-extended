#include <sstream>

#include "displayusagebehavior.hpp"
#include "service.hpp"

#define EMAIL           "email"
#define REPLACE_TARGET  "{}"

const std::string CB_USAGE = R"(Usage: {} [[-n]NUMBER] [-q|-v]
  or:  {} [-a]|[-l [COUNT]]
  or:  {} OPTION...
Change back to the previously visited directory or the NUMBERth previous
directory.

Omitting options is the same as '{} 1' or '{} -n1'.

It also allows you to navigate to even earlier working directories through
options and parameters.

Note that this command only affects and displays the directories visited before
the current directory, and all options of this command apply to this
restriction. This command is very similar to the cf command; the only
difference is that the cb command only processes directories that were visited
earlier than the current directory, while the cf command processes later
directories.

Mandatory arguments to long options are mandatory for short options too.
  -a, --all                    show detailed information about the records
  -l, --list[=COUNT]           list the COUNT most recently visited directories
                                 before the current directory, COUNT is 9 if
                                 not specified
      --list-all               show all records before the current directory
  -c, --clear                  clear all records before the current directory
  -n, --number=NUMBER          go back to the NUMBERth previous directory
  -q, --quiet                  suppress all output
  -v, --verbose                explain what is being done
  -h, --help                   display this help and exit
      --version                output version information and exit
)";

const std::string CF_USAGE = R"(Usage: {} [[-n]NUMBER] [-q|-v]
  or:  {} [-a]|[-l [COUNT]]
  or:  {} OPTION...
Change forward to the next visited directory or the NUMBERth directory ahead.

Omitting options is the same as '{} 1' or '{} -n1'.

It also allows you to navigate to even further ahead in working directories
through options and parameters.

Note that this command only affects and displays the directories visited after
the current directory, and all options of this command apply to this
restriction. This command is very similar to the cb command; the only
difference is that the cf command only processes directories that were visited
later than the current directory, while the cb command processes earlier
directories.

Mandatory arguments to long options are mandatory for short options too.
  -a, --all                    show detailed information about the records
  -l, --list[=COUNT]           list the COUNT most recently visited directories
                                 after the current directory, COUNT is 9 if
                                 not specified
      --list-all               show all records after the current directory
  -c, --clear                  clear all records after the current directory
  -n, --number=NUMBER          go forward to the NUMBERth next directory
  -q, --quiet                  suppress all output
  -v, --verbose                explain what is being done
  -h, --help                   display this help and exit
      --version                output version information and exit
)";

const std::string CV_USAGE = R"(Usage: {} [-l|--list-next|--list-prev] [COUNT] [-a]
  or:  {} [-n NUMBER] [-q|-v]
  or:  {} OPTION...
Change to the visited directory whose index is NUMBER.

Omitting options is the same as '{} -l' or '{} --list'.

Use this command with options like --list to find the indices of visited
directories, then change to the specified directory with the index.

Note that this command can affect and display all visited directories records.
The NUMBER parameter for this command refers to the index of the directory,
which differs from the NUMBER in the cb and cf commands, where it indicates the
distance to a specific directory from the current one.

Mandatory arguments to long options are mandatory for short options too.
  -a, --all                    show detailed information about the records
  -l, --list[=COUNT]           list the COUNT most recently visited directories
                                 after and before the current directory, COUNT
                                 is 9 if not specified
      --list-next[=COUNT]      similar to the as above, but only list the
                                 directories after the current directory
      --list-prev[=COUNT]      as above, but only list the directories before
                                 the current directory
      --list-all               show all of the directory records
  -c, --clear                  clear all directory records
  -n, --number=NUMBER          go to the NUMBER index directory
  -q, --quiet                  suppress all output
  -v, --verbose                explain what is being done
  -h, --help                   display this help and exit
      --version                output version information and exit
)";

const std::string REPORT_INFO = "Report any bugs to <{}>.";

void DisplayUsageBehavior::execute(CbExecutor * e) {
    displayUsage(replaceAll(CB_USAGE, REPLACE_TARGET, currentCommand));
}

void DisplayUsageBehavior::execute(CfExecutor * e) {
    displayUsage(replaceAll(CF_USAGE, REPLACE_TARGET, currentCommand));
}

void DisplayUsageBehavior::execute(CvExecutor * e) {
    displayUsage(replaceAll(CV_USAGE, REPLACE_TARGET, currentCommand));
}

void DisplayUsageBehavior::displayUsage(const std::string & u) const {
    serv::doc(u);
    serv::doc(replaceAll(REPORT_INFO, REPLACE_TARGET, serv::get(EMAIL)));
}

std::string DisplayUsageBehavior::replaceAll(
    const std::string & source,
    const std::string & target,
    const std::string & replacement
) const {
    std::string result { source };

    size_t pos { result.find(target) };
    while (pos != std::string::npos) {
        result.replace(pos, target.length(), replacement);
        pos = result.find(target, pos + replacement.length());
    }

    return result;
}
