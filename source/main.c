// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
    // This example uses a text console, as a simple way to output text to the screen.
    // If you want to write a software-rendered graphics application,
    //   take a look at the graphics/simplegfx example, which uses the libnx Framebuffer API instead.
    // If on the other hand you want to write an OpenGL based application,
    //   take a look at the graphics/opengl set of examples, which uses EGL instead.
    consoleInit(NULL);

    // Other initialization goes here. As a demonstration, we print hello world.
    printf("Hello World!\n");
    int aPresses = 0;
    int framesSinceLast = 0;

    // Main loop
    while (appletMainLoop())
    {
        // Scan all the inputs. This should be done once for each frame
        hidScanInput();

        // hidKeysDown returns information about which buttons have been
        // just pressed in this frame compared to the previous one
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        

        // if (p2kDown & KEY_PLUS) {
        //     printf("A presses: %d\n", aPresses);
        // }
            // break; // break in order to return to hbmenu

        // Your code goes here
        if (kDown & KEY_A) {
            printf("A press #%d - frames since last a press #%d\n", ++aPresses, framesSinceLast);
            framesSinceLast = 0;
        }

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
        framesSinceLast++;
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
