# nxTASter
The goal of this will be to test input against nx-tas scripts

## What this currently does:
1. When the application is loaded, it waits for LSTICK and RSTICK to be clicked in at the same time
2. Once that input is recieved, P1's controller is polled and the input formatted and output to the [deko console](https://github.com/switchbrew/switch-examples/tree/master/graphics/deko3d/deko_console)

## Testing with [nx-TAS](https://github.com/hamhub7/nx-TAS)
1. Copy script1.txt to the nx-TAS scripts folder on your sd card
2. Attach an nx-TAS virtual controller as P1
3. Open nxTASter
4. Use nx-TAS to [run script1.txt](https://github.com/hamhub7/nx-TAS#scripts)

TODO: video

## What this hopefully will do in the future
I think the basic idea will be:
* load script into ram (maybe ui to pick a script to verify)
* start a game loop, poll for input
* todo: figure out a better way to know when we started input (right now we're [looking for ABXY getting pressed at the same time](https://github.com/briaguya/nxtaster/blob/3ef0fcf08b53d4e39632886c9e5c478d9595cfc7/source/main.c#L74-L89))
* verify we're getting the input we expect from the script
* output to log file (maybe UI to display it)
