#include "keyboardevents.h"
#include <X11/XKBlib.h>
#include <stdlib.h>
#include <unistd.h>
KeyboardEvents::KeyboardEvents()
{

}

QString KeyboardEvents::getFirstKeyEvent()
{
    if(!getCapsStatus())
        system("xdotool key Caps_Lock");
    if(!getNumLockStatus())
        system("xdotool key Num_Lock");
    if(!getScrollLockStatus())
        system("xdotool key Scroll_Lock");
    sleep(5);
    system("xdotool key Caps_Lock");
    system("xdotool key Num_Lock");
    system("xdotool key Scroll_Lock");
    return "Key digit 1 pressed\nCaps_Lock: On\nNum Lock: On\nScroll Lock: On\nAll off";
}

QString KeyboardEvents::getSecondKeyEvent()
{
    bool capsState = getCapsStatus();
    bool numLockState = getNumLockStatus();
    bool scrollLockState = getScrollLockStatus();
    return "Caps Lock:" + QString((capsState ? "On\n" : "Off\n"))
            + "Num Lock: " + QString((numLockState ? "On\n" : "Off\n"))
            + "Scroll Lock: " + QString((scrollLockState ? "On\n" : "Off\n"));
}

QString KeyboardEvents::getThirdKeyEvent()
{
    system("xdotool key Caps_Lock");
    system("xdotool key Insert");
    system("xdotool key Num_Lock");
    return "Caps_Lock Inverted\nInsert Inverted\nNum Lock Inverted";
}

QString KeyboardEvents::getFourthKeyDEvent()
{
    int activeIndicators = getCapsStatus() + getNumLockStatus() + getScrollLockStatus();
    //В вашем случае снять побитовую маску и и рассматривать каждый индикатор
    return "Indicators On " + QString::number(activeIndicators);
}

QString KeyboardEvents::getFourthKeyPageUpEvent()
{
    if(getCapsStatus())
        system("xdotool key Caps_Lock");
    if(getNumLockStatus())
        system("xdotool key Num_Lock");
    if(getScrollLockStatus())
        system("xdotool key Scroll_Lock");
    return "Off all indicators\n";

}

bool KeyboardEvents::getCapsStatus()
{
    Display *d = XOpenDisplay((const char*)0);
    bool state = false;
    if(!d)
    {
        return false;
    }
    unsigned int n;
    XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
    state = (n & 1) == 1;
    XCloseDisplay(d);
    return state;
}

bool KeyboardEvents::getNumLockStatus()
{
    Display *d = XOpenDisplay((const char*)0);
    bool state = false;
    if(!d)
    {
        return false;
    }
    unsigned int n;
    XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
    state = (n & 2) == 2;
    XCloseDisplay(d);
    return state;
}

bool KeyboardEvents::getScrollLockStatus()
{
    Display *d = XOpenDisplay((const char*)0);
    bool state = false;
    if(!d)
    {
        return false;
    }
    unsigned int n;
    XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
    state = (n & 8) == 8;
    XCloseDisplay(d);
    return state;
}
