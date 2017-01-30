#include "../include/console.h"
/*
 * start function from where kernel will start executing
 */

int kmain()
{
	char* vidmem = (char *)0xB8000;
    /*
	vidmem[0] = 'H'; vidmem[1] = 0x0F; vidmem[2] = 'E'; vidmem[3] = 0x0F; vidmem[4] = 'L'; 
    vidmem[5] = 0x0F; vidmem[6] = 'L'; vidmem[7] = 0x0F; vidmem[8] = 'O'; vidmem[9] = 0x0F; 
    */

    print("Initializing console");
    init_console();
    print("Welcome to MyOS");
    print("Here is Cursor");
    return 0x0;

}
