This is the test task repo for InfoTecs. 
The following tasks are considered completed: part 1 (completely), part 2 (completely).

The 'lib' directory contains the source code of the logging library. The library is available for building in dynamic and static versions. 
The library supports writing to a socket and to a file.

The 'file_client' directory contains the source code of the test application for checking the library in file writing mode.
Application launch parameters:
```
<path>
Path to the text log file.

<level>
Default message importance level (specified as a number: 1 - low, 2 - standard, 3 - high).
```

Example of running the program:
```
./file_client log.txt 2
```

The directory 'socket_client' contains the source code of the reader and writer test applications for checking the library in UDP socket writing mode (127.0.0.1:48001).

Example of running applications:
```
./socket_writer
./socket_reader
```