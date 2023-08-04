#include "main.h"
#include <stdio.h>
/**
  * get_endianness - returns processor endianness
  * Return: 0 if big endian, 1 if little endian
  */

int get_endianness(void)
{
	unsigned int n;
	char *c = (char *) &n;

	n = 1;
	if (*c)
		return (1);
	else
		return (0);
}
