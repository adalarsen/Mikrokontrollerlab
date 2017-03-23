main:
	avr-gcc -mmcu=at90usb1287 -Os *.c -o main.o -std=c11
	avr-objcopy -j .text -j .data -O ihex main.o main.hex
	avrdude -p usb1287 -c atmelice -U flash:w:main.hex:i

clean:
	find . -type f -name "*.hex" ! -name "example.hex" -delete
	rm *.o

test:
	avrdude -p usb1287 -c atmelice -U flash:w:example.hex:i

