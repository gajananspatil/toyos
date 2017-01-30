/*
 * This file contains the functions related to screen text output
 *
 */

#include "include/console.h"
#include "string.h"
#include "include/inliner.h"

struct video_mode cursor_pos; //= {	VID_VGA_MODE, 0, 0, 2 };
char *vid_mem = (char *) VGA_BUFFER_START;

								

void init_console()
{
    cursor_pos.x=0;
    cursor_pos.y=0;
    cursor_pos.mode = VID_VGA_MODE;
    cursor_pos.depth = 2;
    cursor_pos.color = CLR_BLACK|CLR_WHITE;


	uint_16 x = 0;
	uint_16 y = 0;

	uint_16 *buffer = (uint_16*) vid_mem;
    static	uint_8 blank=0;
	static uint_16 color = ((CLR_BLACK|CLR_WHITE )<<8); /* to store color in higher byte of char array **/

	for(;y<VGA_SCREEN_HEIGHT;y++)
		for(x=0;x<VGA_SCREEN_WIDTH;x++)
		{
			/*
				vid_mem[x+(y*VGA_SCREEN_WIDTH)] = '';
				vid_mem[x+(y*VGA_SCREEN_WIDTH)+(depth-1)] = CLR_BLACK|CLR_WHITE;
			*/
			buffer[x+(y*VGA_SCREEN_WIDTH)] = (uint_16)(blank|color);
		}

    return;
}


/*
 *function to erase contents of rows on screen
 */
void clearline(int from ,int to)
{
	int y=from;
    int x=0;
    static	uint_8 blank=0;
	static uint_16 color = (CLR_BLACK|CLR_WHITE )<<8; /* to store color in higher byte of char array **/


	for(;y<=to;y++)
        for(x=0;x<VGA_SCREEN_WIDTH;x++)
		((uint_16*)vid_mem)[x+(y*VGA_SCREEN_WIDTH)]=(uint_16)(blank|color);
}

/*
 * Scroll the screen up by 1 row
 */
void scroll_up()
{
    int xrow=0;
    int xcol=0;

    for(xrow=0 ;xrow<VGA_SCREEN_HEIGHT;xrow++)
    {
        for(xcol=0;xcol<VGA_SCREEN_WIDTH;xcol++)
        {
            vid_mem[xcol+(xrow*VGA_SCREEN_WIDTH)] = vid_mem[xcol+((xcol+1)*VGA_SCREEN_WIDTH)];

        }

    }
    clearline(24,2);
}

 void update_cursor(int row, int col)
 {
     unsigned short position=(row*VGA_SCREEN_WIDTH) + col;
              
  // cursor LOW port to vga INDEX register
     outb(0x3D4, 0x0F);
     outb(0x3D5, (unsigned char)(position&0xFF));
  // cursor HIGH port to vga INDEX register
     outb(0x3D4, 0x0E);
     outb(0x3D5, (unsigned char )((position>>8)&0xFF));
 }


/*
 *	write character at current cursor position
 */
void dispchar(unsigned char c)
{
		vid_mem[(cursor_pos.x)+(cursor_pos.y*VGA_SCREEN_WIDTH)]     = c;
		vid_mem[((cursor_pos.x)+(cursor_pos.y*VGA_SCREEN_WIDTH))+1] = cursor_pos.color;
		cursor_pos.x+=2;

		if(cursor_pos.x>= VGA_SCREEN_WIDTH)
			cursor_pos.x=0,cursor_pos.y++;
			
		if(cursor_pos.y>= VGA_SCREEN_HEIGHT)
        {
            cursor_pos.y--;
	    	scroll_up();
        }
        update_cursor(cursor_pos.x,cursor_pos.y);
}


/*
 *  Function to print string of characters
 */
void print(char *buff)
{
	size_t len = strlen(buff);
	size_t count=0;
	while(count<len)
		dispchar(*(buff+count++));
}

