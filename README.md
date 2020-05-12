# nxTASter
The goal of this will be to test input against nx-tas scripts

## What this currently does:
When used in conjuntion with nx-TAS (specifically [this script](https://github.com/briaguya/nx-TAS/blob/master/sd_card/scripts/script1.txt)), it will wait for the input we have defined on the first line (ABXY all pressed at the same time) and then start counting frames and A presses. The current frame count and A press count are output to the [deko console](https://github.com/switchbrew/switch-examples/tree/master/graphics/deko3d/deko_console). It's currently hardcoded to stop after all 30 presses have happened.

![seee it in action](/docs/running_script.gif)

## What this hopefully will do in the future
I think the basic idea will be:
* load script into ram (maybe ui to pick a script to verify)
* start a game loop, poll for input
* todo: figure out a better way to know when we started input (right now we're [looking for ABXY getting pressed at the same time](https://github.com/briaguya/nxtaster/blob/3ef0fcf08b53d4e39632886c9e5c478d9595cfc7/source/main.c#L74-L89))
* verify we're getting the input we expect from the script
* output to log file (maybe UI to display it)
