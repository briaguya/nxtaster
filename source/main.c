#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
    consoleInit(NULL);

    // clear screen and home cursor
    printf(CONSOLE_ESC(2J));
    bool running = false;
    // #define CONSOLE_RED     CONSOLE_ESC(31;1m)
    int currentConsoleColor = 31;
    int currentLinePosition = 0;

    // todo: disconnect controllers here if we can

    //     // Color codes and attributes
    // for(int i=0; i<8; i++)
    // {
    //     printf(%1$dm);
    //     printf(    CONSOLE_ESC(%1$dm) /* Set color */
    //             "Default "
    //             CONSOLE_ESC(1m) "Bold "
    //             CONSOLE_ESC(7m) "Reversed "

    //             CONSOLE_ESC(0m) /* revert attributes*/
    //             CONSOLE_ESC(%1$dm)

    //             CONSOLE_ESC(2m) "Light "
    //             CONSOLE_ESC(7m) "Reversed "

    //             "\n"
    //             CONSOLE_ESC(0m) /* revert attributes*/
    //             , i + 30);
    // }

    //         #define CONSOLE_RESET   CONSOLE_ESC(0m)
    // #define CONSOLE_BLACK   CONSOLE_ESC(30m)
    // #define CONSOLE_RED     CONSOLE_ESC(31;1m)
    // #define CONSOLE_GREEN   CONSOLE_ESC(32;1m)
    // #define CONSOLE_YELLOW  CONSOLE_ESC(33;1m)
    // #define CONSOLE_BLUE    CONSOLE_ESC(34;1m)
    // #define CONSOLE_MAGENTA CONSOLE_ESC(35;1m)
    // #define CONSOLE_CYAN    CONSOLE_ESC(36;1m)
    // #define CONSOLE_WHITE

    // 
    printf(CONSOLE_WHITE CONSOLE_ESC(1m));
    printf("nxTASter v0.0.1\n");
    printf("Press LSTICK and RSTICK on P1 to start/stop reading inputs\n\n");

    // Main loop
    while (appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

        // Check for both stick clicks press to start/stop
        if ((kDown & KEY_LSTICK) && (kDown & KEY_RSTICK)) {
            if (running) {
                printf(CONSOLE_WHITE CONSOLE_ESC(1m));
                printf("\nStopped reading input from P1\n");
                running = false;
                currentLinePosition = 0;

            } else {
                running = true;
                printf(CONSOLE_WHITE CONSOLE_ESC(1m));
                printf("Started reading input from P1\n");
            }
        }

        if (running) {
            // If we're at the last color loop back to red
            if (currentConsoleColor == 37) {
                currentConsoleColor = 31;
            }

            if (currentLinePosition == 5) {
                printf("\n");
                currentLinePosition = 0;
            }
            
            printf(CONSOLE_ESC(%1$dm) CONSOLE_ESC(1m), currentConsoleColor);

    // KEY_A            = BIT(0),       ///< A
    // KEY_B            = BIT(1),       ///< B
    // KEY_X            = BIT(2),       ///< X
    // KEY_Y            = BIT(3),       ///< Y
    // KEY_LSTICK       = BIT(4),       ///< Left Stick Button
    // KEY_RSTICK       = BIT(5),       ///< Right Stick Button
    // KEY_L            = BIT(6),       ///< L
    // KEY_R            = BIT(7),       ///< R
    // KEY_ZL           = BIT(8),       ///< ZL
    // KEY_ZR           = BIT(9),       ///< ZR
    // KEY_PLUS         = BIT(10),      ///< Plus
    // KEY_MINUS        = BIT(11),      ///< Minus
    // KEY_DLEFT        = BIT(12),      ///< D-Pad Left
    // KEY_DUP          = BIT(13),      ///< D-Pad Up
    // KEY_DRIGHT       = BIT(14),      ///< D-Pad Right
    // KEY_DDOWN        = BIT(15), 

            printf(" ");
            // todo: eat this copypasta
            if (kDown & KEY_A) {
                printf("A");
            } else {
                printf(" ");
            };

            if (kDown & KEY_B) {
                printf("B");
            } else {
                printf(" ");
            };

            if (kDown & KEY_X) {
                printf("X");
            } else {
                printf(" ");
            };

            if (kDown & KEY_Y) {
                printf("Y");
            } else {
                printf(" ");
            };

            if (kDown & KEY_L) {
                printf("L");
            } else {
                printf(" ");
            };

            if (kDown & KEY_ZL) {
                printf("\\");
            } else {
                printf(" ");
            };

            if (kDown & KEY_R) {
                printf("R");
            } else {
                printf(" ");
            };

            if (kDown & KEY_ZR) {
                printf("/");
            } else {
                printf(" ");
            };

            if (kDown & KEY_PLUS) {
                printf("+");
            } else {
                printf(" ");
            };

            if (kDown & KEY_MINUS) {
                printf("-");
            } else {
                printf(" ");
            };

            if (kDown & KEY_DLEFT) {
                printf("<");
            } else {
                printf(" ");
            };

            if (kDown & KEY_DUP) {
                printf("^");
            } else {
                printf(" ");
            };

            if (kDown & KEY_DRIGHT) {
                printf(">");
            } else {
                printf(" ");
            };

            if (kDown & KEY_DDOWN) {
                printf("v");
            } else {
                printf(" ");
            };

            currentConsoleColor++;
            currentLinePosition++;
        }

        

        if (!running && (kDown & KEY_PLUS))
            break; // break in order to return to hbmenu

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
