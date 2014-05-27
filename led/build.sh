#!/bin/bash
##Specific script for Arduino UNO R3 with ATmega328p
avr-g++ -DF_CPU=16000000UL -mmcu=atmega328p -Os -c -o led.o led.cpp
avr-g++ -DF_CPU=16000000UL -mmcu=atmega328p -Os -o led.elf led.o
avr-objcopy -O ihex led.elf led.hex
##RUN IT LATER, WHEN YOU REBOOT
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
