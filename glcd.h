/*
 17Apr2013
 Tim Stephens www.tjstephens.com
 C18 Port of original public domain code by Nathan Seidle of Sprakfun Electronics Inc.
 
 This code is public domain but you buy me (or him) a beer if you use this and we meet someday (Beerware license).
 
 This code writes a series of images and text to the Nokia 5110 84x48 graphic LCD:
 http://www.sparkfun.com/products/10168
 
 Do not drive the backlight with 5V. It will smoke. However, the backlight on the LCD seems to be 
 happy with direct drive from the 3.3V regulator.

 Although the PCD8544 controller datasheet recommends 3.3V, the graphic Nokia 5110 LCD can run at 3.3V or 5V. 
 No resistors needed on the signal lines, but I used 1K anyway.
 
 You will need 5 signal lines to connect to the LCD, 3.3 or 5V for power, 3.3V for LED backlight, and 1 for ground.
 */
#ifndef _GLCD_H_
#define _GLCD_H_

#define _LCDSelect LATAbits.LATA3
#define _LCDReset LATAbits.LATA4
#define _LCDData LATAbits.LATA5


//The DC pin tells the LCD if we are sending a command or data
#define LCD_COMMAND 0 
#define LCD_DATA  1

//You may find a different size screen, but this one is 84 by 48 pixels
#define LCD_X 84
#define LCD_Y 48




//Function Prototypes
void gotoXY(int x, int y);
void LCDBitmap(char my_array[], int x, int y, int width, int height);
void LCDCharacter(char character, char invertMode);
void LCDString(char characters[], int length);
void LCDClear(void);
void LCDInit(void);
void LCDWrite(char data_or_command, char data);
void LCDAwesome(void); 
void LCDCat(void);





#endif // _GLCD_H_