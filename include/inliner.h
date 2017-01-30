//#include "include/inlinerasm.h"


/*
 * @desc: An function to send data/command to a port
 * @param: unsigned short port 
 * @param: unsigned short value
 * 
 */

static inline void outb(uint_16 port,uint_16 val)
{
    __asm__ __volatile__ ("out %0, %1 \n\t" 
                            : 
			    :"a" (val),"r"(port)
			    :"memory");
}

static inline uint_16 inb(uint_16 port)
{
    uint_16 ret;
    __asm__ __volatile__("in %0 \n\t" 
                        :"=a" (ret) 
                        :"r" (port)
			:"memory");
    return ret;
}


