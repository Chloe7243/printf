#include "main.h"
#include <stdio.h>



int count_digit(int num)
{
	int count = 0;
	unsigned int n;

	if (num < 0)
	{
		n = -num;
		count = 1;
	}
	else
		n = num;
	do
	{
		count++;
		n /= 10;
	}while (n != 0);

	return (count);
}

/**
 * print_digit - prints a digit
 *
 * @num: number
 *
 * Return: void
 */

void print_digit(int num)
{
	unsigned int n;

	if (num < 0)
	{
		n = -num;
		_putchar('-');
	}
	else
		n = num;

	if (n >= 10)
	{
		print_digit(n / 10);
	}

	_putchar('0' + n % 10);
}
