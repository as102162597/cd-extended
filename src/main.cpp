#include "executor.hpp"
#include "parser.hpp"

int main(int argc, char * argv[]) {

    Executor * executor { Parser::getInstance().parse(argc, argv).getExecutor() };

    executor->execute();

    delete executor;

    return 0;

}
