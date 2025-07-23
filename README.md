This is the test task repo for InfoTecs. 

The 'lib' directory contains the source code of the logging library. The library is available for building in dynamic and static versions.

The 'client' directory contains the source code of the test application for checking the library.
Application launch parameters:
<path>
Path to the text log file.

<level>
Default message importance level (specified as a number: 1 - low, 2 - standard, 3 - high).

Example of running the program:
```
./сlient log.txt 2
```
