#include "clearbehavior.hpp"
#include "service.hpp"

void ClearBehavior::clearPrev() {
    footprints.erase(
        footprints.begin(),
        footprints.begin() + getFootprintIndexInVectorByIndex(currentIndex)
    );
}

void ClearBehavior::clearNext() {
    footprints.erase(
        footprints.begin() + getFootprintIndexInVectorByIndex(currentIndex) + 1,
        footprints.end()
    );
}

void ClearBehavior::cleardNotification() { serv::inf(phrz::CLEARED_NOTIFICATION); }
