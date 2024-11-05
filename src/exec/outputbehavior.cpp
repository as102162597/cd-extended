#include <iostream>

#include "outputbehavior.hpp"

void OutputBehavior::execute(CbExecutor * e) {
    std::cout << footprints[getCbTargetIndexInVector()].str() << std::endl;
}

void OutputBehavior::execute(CfExecutor * e) {
    std::cout << footprints[getCfTargetIndexInVector()].str() << std::endl;
}

void OutputBehavior::execute(CvExecutor * e) {
    std::cout << footprints[getCvTargetIndexInVector()].str() << std::endl;
}

int OutputBehavior::getCbTargetIndexInVector() const {
    return getFootprintIndexInVectorByBackSteps(target);
}

int OutputBehavior::getCfTargetIndexInVector() const {
    return getFootprintIndexInVectorByForwardSteps(target);
}

int OutputBehavior::getCvTargetIndexInVector() const {
    return getFootprintIndexInVectorByIndex(target);
}
