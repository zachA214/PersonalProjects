#define ESCAPEKEY 27 // 27 is the escape key on the keyboard on the ASCII table

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For kbhit()
#include <time.h> // For time
#include <windows.h>
#include <stdlib.h>

LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam );

typedef enum myBool
{
    True, False
} myBool;
