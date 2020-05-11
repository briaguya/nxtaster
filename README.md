# nx-tas-tester
The goal of this will be to test input against nx-tas scripts

I think the basic idea will be:
* load script into ram (maybe ui to pick a script to verify)
* start a "game" loop, poll for input
* todo: figure out a way to know when we started input
* verify each frame (hit/miss)
* output to log file (maybe UI to display it)