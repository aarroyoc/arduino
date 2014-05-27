LED Serial Communication
========================

This example shows how to communicate between Arduino and a PC. You should compile via Arduino IDE the simple_ino sketch and the simple2.cpp on your PC. make sure to have installed libSerial
Then, start the Arduino and on your command line put:
```
./simple2 -d/dev/ttyXXX
```
Where /dev/ttyXXX is the place of your Arduino

###Compilation
```
g++ -o simple2 simple2.cpp -lserial
```
