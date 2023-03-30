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

int count_digit(long int num, int divisor)
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
	do {
		count++;
		n /= divisor;
	} while (n != 0);

	return (count);
}

/**
 * print_digit - prints a digit
 *
 * @num: number
 *
 * Return: void
 */

void print_digit(long int num)
{
	unsigned long int n;

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
 * @n: number
 *
 * Return: number of binaries printed
 */

int print_binary(unsigned int n)
{
	unsigned int m, i, sum;
	unsigned int a[32];
	int count;

	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			count += _putchar('0' + a[i]);

		}
	}
	return (count);

}
