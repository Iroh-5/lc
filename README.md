# lc is a program that (as someone might have guessed) counts lines
Motives behind this small "project" are simple - I just wanted to be able to measure the amount of lines I've written.
But I'm sure everyone understands that number of lines of code is awful measure. It is like measuring the quality of plane by its weight.
## Functionality:
Program may be launched in two ways:
* with command line arguments
* without them

In first case program outputs number of lines in each provided file.
In second case user inputs desired number of file names into the program, and then program outputs files' number of lines in the same way as in first case. 
## Use cases:
* If you're on Linux, you can do so:
     ls -p | grep -v / | ./lc
* It you're on Windows, you can do so:
     dir /A:-D-R /S > lc.exe
These commands will make program read every file that is in current directory.
