#include "main.h"
#include <stdio.h>

/**
 * print_digit - prints a digit
 *
 * @num: number
 *
 * Return: int
 */

int print_digit(int num)
{
	int count = 0;
	unsigned int n;
	signed int n1;

	if (num < 0)
	{
		n = -num;
		count += _putchar('-');
	}
	else
		n = num;

	if (n >= 10)
	{
		print_digit(n / 10);
	}

	n1 = n % 10;

	count += _putchar('0' + n1);

	return (count);
}
