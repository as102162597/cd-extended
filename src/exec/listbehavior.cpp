#include "listbehavior.hpp"
#include "service.hpp"

void ListBehavior::execute(CvExecutor * e) {
    switch (mode) {
        case Mode::PREV: executeCbExecutor(); break;
        case Mode::NEXT: executeCfExecutor(); break;
        default: executeCvExecutor();
    }
}

void ListBehavior::executeCbExecutor() const {
    const int curr { getFootprintIndexInVectorByIndex(currentIndex) };
    const int start { getFootprintIndexInVectorByIndex(currentIndex - count) };

    if (isAllInfo) {
        serv::doc(fp::field(fp::ALL));
        for (int i { start }; i < curr; ++i)
            serv::doc(footprints[i].str(fp::ALL));
        serv::doc(footprints[curr].str(fp::ALL) + getCurrentDirectoryNote());
    } else {
        serv::doc(fp::field(fp::BACKSTEPS));
        for (int i { start }; i < curr; ++i)
            serv::doc(footprints[i].str(fp::BACKSTEPS));
        serv::doc(footprints[curr].str(fp::BACKSTEPS) + getCurrentDirectoryNote());
    }
}

void ListBehavior::executeCfExecutor() const {
    const int curr { getFootprintIndexInVectorByIndex(currentIndex) };
    const int end { getFootprintIndexInVectorByIndex(currentIndex + count) + 1 };

    if (isAllInfo) {
        serv::doc(fp::field(fp::ALL));
        serv::doc(footprints[curr].str(fp::ALL) + getCurrentDirectoryNote());
        for (int i { curr + 1 }; i < end; ++i)
            serv::doc(footprints[i].str(fp::ALL));
    } else {
        serv::doc(fp::field(fp::FORWARDSTEPS));
        serv::doc(footprints[curr].str(fp::FORWARDSTEPS) + getCurrentDirectoryNote());
        for (int i { curr + 1 }; i < end; ++i)
            serv::doc(footprints[i].str(fp::FORWARDSTEPS));
    }
}

void ListBehavior::executeCvExecutor() const {
    const int curr { getFootprintIndexInVectorByIndex(currentIndex) };
    const int start { getFootprintIndexInVectorByIndex(currentIndex - count) };
    const int end { getFootprintIndexInVectorByIndex(currentIndex + count) + 1 };

    if (isAllInfo) {
        serv::doc(fp::field(fp::ALL));
        for (int i { start }; i < end; ++i)
            serv::doc(footprints[i].str(fp::ALL) + (i == curr ? getCurrentDirectoryNote() : ""));
    } else {
        serv::doc(fp::field(fp::INDEX));
        for (int i { start }; i < end; ++i)
            serv::doc(footprints[i].str(fp::INDEX) + (i == curr ? getCurrentDirectoryNote() : ""));
    }
}

std::string ListBehavior::getCurrentDirectoryNote() const {
    return std::string(" \e[43m\e[30m[" + serv::tr(phrz::CURRENT_DIRECTORY) + "]\033[0m");
}
