#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index.
 * @n: pointer to the bit
 * @index: index to set the value star at 0
 *
 * Return: error -1 other 1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n ^= (1 << index);
	return (1);
}
