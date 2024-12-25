#include <algorithm>
#include <fstream>

#include "editfilebehavior.hpp"
#include "service.hpp"

EditFileBehavior::EditFileBehavior(
    const std::filesystem::path & p,
    const std::string sourceDirectory
) : filepath(p) {
    loadFile();
    calibrate(sourceDirectory);
    updateBackSteps();
    updateForwardSteps();
}

EditFileBehavior::~EditFileBehavior() {
    removeExcess();
    saveFile();
}

int EditFileBehavior::getStrictFootprintIndexInVectorByIndex(const int index) const {
    const int indexInVector { getFootprintIndexInVectorByIndex(index) };
    if (footprints[indexInVector].getIndex() != index)
        serv::terminate(phrz::INVALID_FILE_FORMAT);
    return indexInVector;
}

int EditFileBehavior::getFootprintIndexInVectorByIndex(const int index) const {
    return it2Idx(footprints, std::lower_bound(footprints.begin(), footprints.end(), fp(index, "/")));
}

int EditFileBehavior::getFootprintIndexInVectorByBackSteps(const int backSteps) const {
    return it2Idx(
        footprints,
        std::lower_bound(
            footprints.begin(),
            footprints.end(),
            fp(0, backSteps, 0, "/"),
            [](const fp & a, const fp & b) { return a.getBackSteps() > b.getBackSteps(); }
        )
    );
}

int EditFileBehavior::getFootprintIndexInVectorByForwardSteps(const int forwardSteps) const {
    return it2Idx(
        footprints,
        std::lower_bound(
            footprints.begin(),
            footprints.end(),
            fp(0, 0, forwardSteps, "/"),
            [](const fp & a, const fp & b) { return a.getForwardSteps() < b.getForwardSteps(); }
        )
    );
}

void EditFileBehavior::loadFile() {
    std::ifstream file(filepath);
    if (!file) {
        serv::terminate(phrz::OPEN_FILE_FAIL);
    }

    std::string line;

    std::getline(file, line);
    currentIndex = std::stoi(line);

    while (std::getline(file, line)) {
        if (line.length()) {
            footprints.push_back(fp(line));
        }
    }

    file.close();
}

void EditFileBehavior::calibrate(const std::string & sourceDirectory) {
    const int index { getFootprintIndexInVectorByIndex(currentIndex) };

    if (footprints[index].str() == sourceDirectory)
        return;

    const int idx { findClosestFpIndexInVector(index, sourceDirectory) };

    if (idx < 0) {
        footprints[index].setDirectory(sourceDirectory);
    } else {
        currentIndex = footprints[idx].getIndex();
    }
}

void EditFileBehavior::updateBackSteps() {
    const int index { getStrictFootprintIndexInVectorByIndex(currentIndex) };
    const int size { static_cast<int>(footprints.size()) };

    int b { 0 };
    for (int i { index }; i >= 0; --i)
        footprints[i].setBackSteps(b++);

    b = 0;
    for (int i { index + 1 }; i < size; ++i)
        footprints[i].setBackSteps(--b);
}

void EditFileBehavior::updateForwardSteps() {
    const int index { getStrictFootprintIndexInVectorByIndex(currentIndex) };
    const int size { static_cast<int>(footprints.size()) };

    int f { 0 };
    for (int i { index }; i < size; ++i)
        footprints[i].setForwardSteps(f++);

    f = 0;
    for (int i { index - 1 }; i >= 0; --i)
        footprints[i].setForwardSteps(--f);
}

void EditFileBehavior::removeExcess() {
    if (footprints.size() <= static_cast<size_t>(serv::getVal("maxStorageCap")))
        return;
    if (footprints.size() > static_cast<size_t>(serv::getVal("deletionVol")))
        footprints.erase(footprints.begin(), footprints.begin() + serv::getVal("deletionVol"));
}

void EditFileBehavior::saveFile() const {
    std::ofstream file(filepath);
    if (!file) {
        serv::terminate(phrz::OPEN_FILE_FAIL);
    }

    file << currentIndex << std::endl;
    for (const auto & footprint : footprints)
        file << footprint.getIndex() << " " << footprint.str() << std::endl;

    file.close();
}

int EditFileBehavior::findClosestFpIndexInVector(const int idxFrom, const std::string & target) const {
    int size { static_cast<int>(footprints.size()) };
    int largeIdx, smallIdx;

    for (int i { 0 }; (largeIdx = idxFrom + i) < size && (smallIdx = idxFrom - i) > 0; ++i) {
        if (footprints[largeIdx].str() == target)
            return largeIdx;
        if (footprints[smallIdx].str() == target)
            return smallIdx;
    }

    return -1;
}

template <typename T>
int EditFileBehavior::it2Idx(const std::vector<T> & v, const std::vector<T>::const_iterator & i) const {
    return i == v.end() ? v.size() - 1 : std::distance(v.begin(), i);
}
