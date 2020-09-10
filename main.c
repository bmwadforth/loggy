#include <stdio.h>
#include "include/types.h"
#include "include/keystroke/keylogger.h"

#ifdef _WIN32
OPERATING_SYSTEM operatingSystem = WINDOWS;
#endif

#ifdef linux
OPERATING_SYSTEM operatingSystem = LINUX;
#endif

#ifdef __APPLE__
OPERATING_SYSTEM operatingSystem = MAC;
#endif

int main() {
    switch (operatingSystem) {
        case WINDOWS:
            printf("Operating System: Windows Not Implemented\n");
            return 1;
        case MAC:
            printf("Operating System: MacOS\n");
            getKeyStrokes();
            break;
        case LINUX:
            printf("Operating System: Linux Not Implemented\n");
            return 1;
        default:
            printf("OS Not Supported\n");
            return 1;
    }

    return 0;
}
