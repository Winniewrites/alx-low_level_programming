#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * clear_bit - function that sets the value of a bit to 0 at a given index
 * @n: pointer to the bit
 * @index: index to set value
 *
 * Return: Error -1 / Other 1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);

	return (1);
}
