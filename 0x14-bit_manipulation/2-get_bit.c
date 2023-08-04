#include "main.h"

/**
 * get_bit - return value bit
 * @n: number
 * @index: starting with 0
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int num;
	unsigned int x, count = 0;

	if (n == 0)
	{
		count = 1;
	}
	else
	{
		for (num = n; num > 0; num >>= 1)
			count++;
	}

	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	if (index > count - 1)
		return (0);

	x = n >> index;
	if (x & 1)
		return (1);
	else
		return (0);
}
