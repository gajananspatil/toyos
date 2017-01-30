#include <include/types.h>

#ifndef _CONSOLE_
#define _CONSOLE_


#define VGA_BUFFER_START	0xb8000
#define	VGA_SCREEN_WIDTH	80
#define VGA_SCREEN_HEIGHT	25

#define VID_VGA_MODE		0x01


enum vga_colors {	CLR_BLACK=0x00,
					CLR_BLUE,
					CLR_GREEN,
					CLR_CYAN,
					CLR_RED,
					CLR_MAGENTA,
					CLR_BROWN,
					CLR_LIGHT_GRAY,
					CLR_DARK_GRAY, 		/* 0+8 */
					CLR_LIGHT_BLUE, 	/* 1+8 */
					CLR_LIGHT_GREEN, 	/* 2+8 */
					CLR_LIGHT_CYAN,
					CLR_LIGHT_RED,
					CLR_LIGHT_MAGENTA,
					CLR_YELLOW,
					CLR_WHITE};			/* 7+8 */



struct video_mode
{
		uint_16	mode;		/** video mode **/
		uint_16	x;			/** cursor x co-ordinate **/
		uint_16 y;			/** cursor y co-ordinate **/
		uint_16 depth;		/** depth of each co-ordinate **/
		uint_16	color;		/** text color **/
};


void init_console();


void clearline(int from ,int to);

void dispchar(unsigned char c);

void print(char *buffer);

void scroll_up();
#endif
