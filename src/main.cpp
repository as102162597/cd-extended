#include <memory>
#include "executor.hpp"
#include "parser.hpp"

int main(int argc, char * argv[]) {

    std::shared_ptr<Executor> executor { Parser::getInstance().parse(argc, argv).getExecutor() };

    executor->execute();

    return 0;

}
