#include <include/types.h>


size_t strlen(char *str)
{
	char *tmp = str;
	size_t length = 0;
	while(*tmp)
		tmp++,length++;
	return length;
}