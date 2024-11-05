#ifndef __EDIT_FILE_BEHAVIOR_HPP__
#define __EDIT_FILE_BEHAVIOR_HPP__

#include <vector>

#include "behavior.hpp"
#include "footprint.hpp"

class EditFileBehavior : public Behavior {
public:
    EditFileBehavior(const std::filesystem::path & p, const std::string sourceDirectory);
    virtual ~EditFileBehavior();

protected:
    int getStrictFootprintIndexInVectorByIndex(const int index) const;
    int getFootprintIndexInVectorByIndex(const int index) const;
    int getFootprintIndexInVectorByBackSteps(const int backSteps) const;
    int getFootprintIndexInVectorByForwardSteps(const int forwardSteps) const;

    int currentIndex;
    std::filesystem::path filepath;
    std::vector<fp> footprints;

private:
    void loadFile();
    void calibrate(const std::string & sourceDirectory);
    void updateBackSteps();
    void updateForwardSteps();
    void removeExcess();
    void saveFile() const;

    int findClosestFpIndexInVector(const int idxFrom, const std::string & target) const;

    template <typename T>
    int it2Idx(const std::vector<T> & v, const std::vector<T>::const_iterator & i) const;

};

#endif
