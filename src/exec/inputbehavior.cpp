#include "inputbehavior.hpp"
#include "service.hpp"

void InputBehavior::execute(CdExecutor * e) {
    if (targetDirectory == sourceDirectory)
        return;

    assertSource();

    const int index { getFootprintIndexInVectorByIndex(currentIndex) };

    if (footprints.size() == static_cast<size_t>(index + 1)) {
        footprints.push_back(fp(++currentIndex, targetDirectory));
    } else {
        footprints[index + 1].setIndex(++currentIndex).setDirectory(targetDirectory);
        footprints.erase(footprints.begin() + index + 2, footprints.end());
    }
}

void InputBehavior::execute(CbExecutor * e) {
    assertSource();
    if (!getFootprintIndexInVectorByIndex(currentIndex))
        serv::doc(phrz::CB_AT_1ST_DIRECTORY);
    gotoTargetDirectory(footprints[getCbTargetIndexInVector()]);
}

void InputBehavior::execute(CfExecutor * e) {
    assertSource();
    if (getFootprintIndexInVectorByIndex(currentIndex) == static_cast<int>(footprints.size()) - 1)
        serv::doc(phrz::CF_AT_LAST_DIRECTORY);
    gotoTargetDirectory(footprints[getCfTargetIndexInVector()]);
}

void InputBehavior::execute(CvExecutor * e) {
    assertSource();
    gotoTargetDirectory(footprints[getCvTargetIndexInVector()]);
}

void InputBehavior::gotoTargetDirectory(const fp & f) {
    if (targetDirectory == f.str()) {
        currentIndex = f.getIndex();
        serv::inf(serv::tr(phrz::CHANGE_TO) + f.str());
    } else {
        serv::inf(phrz::CHANGE_DIRECTORY_FAIL);
    }
}

void InputBehavior::assertSource() const {
    if (!isSourceValid())
        serv::terminate(phrz::INVALID_SOURCE);
}

bool InputBehavior::isSourceValid() const {
    return sourceDirectory == footprints[getFootprintIndexInVectorByIndex(currentIndex)].str();
}
