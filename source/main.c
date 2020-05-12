#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    consoleInit(NULL);

    // clear screen and home cursor
    printf( CONSOLE_ESC(2J) );

    // todo: disconnect controllers here if we can

    // Main loop
    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);



        if (kDown & KEY_A) {
            printf(CONSOLE_ESC(7m) " ");
        } else {
            printf(CONSOLE_ESC(0m) " ");
        }

        if (kDown & KEY_PLUS) break; // break in order to return to hbmenu

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
