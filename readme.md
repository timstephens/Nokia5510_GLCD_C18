#Nokia 5510 GLCD control code

This code is a direct port of the public domain Arduino source code to control the Nokia 5510 LCDs that are available from [Sparkfun](http://www.sparkfun.com/products/10168). It was converted and tested with a C18 toolchain in MPLABX against a PIC18F2550, but should be pretty easy to convert to XC8 -- in fact, I suspect that you just need to add it to your project.
Your PIC will need an SPI port connected to the MISO and MOSI pins on the LCD, 
##Usage

Add both glcd.h and glcd.c to your project, then in your main.c

	#include "glcd.h"
	#include <spi.h>
	
	#define _LCDSelect LATAbits.LATA3 //These can be any output pins, but these are the ones that I chose.
	#define _LCDReset LATAbits.LATA4
	#define _LCDData LATAbits.LATA5

Then in void main()

	void main()
	{
		TRISA=0;
		
		LCDInit();
		LCDClear();
		LCDString(myString, strlen(myString));
	}

Do not drive the backlight with 5V. It will smoke. However, the backlight on the LCD seems to be happy with direct drive from the 3.3V regulator.


##Support

C18 Port of original public domain code by Nathan Seidle of Sprakfun Electronics Inc. This code is public domain but you buy me (or him) a beer if you use this and we meet someday (Beerware license).

This code is provided as-is, without any warranty. Use at your own risk.