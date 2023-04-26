#include "main.h"

/**
 * add - Adds two integers and returns
 * the result.
 *
 * @a: number one.
 * @b: number two.
 *
 * Return: Add of number one and number two.
 */
int add(int a, int b)
{
	return (a + b);
}

Task 11

vi 11-print_to_98.c

#include <stdio.h>
/**
 * print_to_98 - Prints all natural numbers
 * from n to 98.
 *
 * @n: input number.
 *
 * Return: no return.
 */
void print_to_98(int n)
{
	if (n > 98)
	{
		for (; n > 98; n--)
		{
			printf("%d, ", n);
		}
	}
	else if (n < 98)
	{
		for (; n < 98; n++)
		{
			printf("%d, ", n);
		}
	}
	printf("%d\n", n);
}
