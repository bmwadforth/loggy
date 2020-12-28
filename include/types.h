#ifndef LOGGY_TYPES_H
#define LOGGY_TYPES_H

namespace Loggy::Types {
    enum OPERATING_SYSTEM {
        WINDOWS,
        LINUX,
        MAC
    } typedef OPERATING_SYSTEM;
}

extern Loggy::Types::OPERATING_SYSTEM operatingSystem;
#endif
