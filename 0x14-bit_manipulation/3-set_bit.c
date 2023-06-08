#include "main.h"

/**
 * set_bit - sets the value of a bit at index to 1
 * @n: the number
 * @index: the index
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	*n |= (1 << index);
	return (1);
}
