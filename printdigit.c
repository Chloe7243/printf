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
	if (num < 0)
	{
		num = -num;
		count += _putchar('-');
	}

	if (num >= 10)
	{
		print_digit(num / 10);
	}

	 count += _putchar('0' + (num % 10));

	 return (count);
}
