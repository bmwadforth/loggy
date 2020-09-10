#ifndef LOGGY_KEYLOGGER_H
#define LOGGY_KEYLOGGER_H
#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
CGEventRef eventCallback(CGEventTapProxy, CGEventType, CGEventRef, void *);
#endif

#ifdef _WIN32
//TODO: Include Windows header files
#endif

#ifdef linux
//TODO: Include Linux header files
#endif


void getKeyStrokes();
#endif
