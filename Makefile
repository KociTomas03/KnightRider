default:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o KnightRider.o KnightRider.c
	avr-gcc -o KnightRider.bin KnightRider.o
	avr-objcopy -O ihex -R .eeprom KnightRider.bin KnightRider.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P COM3 -b 115200 -U flash:w:KnightRider.hex