#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_digit - count number of digits
 *
 * @num: number
 * @divisor: divisor
 *
 * Return: int
 */

int count_digit(int num, int divisor)
{
	int count = 0;
	unsigned int n;

	if (divisor == 2 && num < 0)
	{
		return (0);
	}

	if (num < 0)
	{
		n = -num;
		count = 1;
	}
	else
		n = num;
	do {
		count++;
		n /= divisor;
	} while (n != 0);

	return (divisor == 2 ? --count : count);
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

/**
 * print_binary - prints binary version of a digit
 *
 * @num: number
 *
 * Return: void
 */

void print_binary(unsigned int num)
{
	if (num > 1)
	{
		print_binary(num / 2);
	}
	_putchar('0' + num % 2);
}
