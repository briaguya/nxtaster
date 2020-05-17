# nxTASter
The goal of this is to test input from various TAS playback methods.

## What this currently does:
1. When the application is loaded, it waits for LSTICK and RSTICK to be clicked in at the same time
2. Once that input is recieved, P1's controller is polled and the input formatted and output to the [deko console](https://github.com/switchbrew/switch-examples/tree/master/graphics/deko3d/deko_console)

## Testing with [nx-TAS](https://github.com/hamhub7/nx-TAS)
* Copy [script1.txt](/script1.txt) to the nx-TAS [scripts folder](https://github.com/hamhub7/nx-TAS#scripts) on your sd card
* Attach an nx-TAS virtual controller as P1
* Open nxTASter and use nx-TAS to run [script1.txt](/script1.txt)
![Opening nxTASter from homebrew menu, running script1 with nx-TAS virtual controller](/docs/runtest.gif)

## What about script2.txt?
[script2.txt](/script2.txt) appears to cause [nx-TAS](https://github.com/hamhub7/nx-TAS) to exit prematurely.
![script2.gif](/docs/script2.gif)
