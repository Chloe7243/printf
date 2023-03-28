#include "main.h"
#include <stdio.h>


/**
 * print_number - prints a number to standard output stream
 * @n: number to be printed
 * @base: base of the number to be printed (e.g. 10 for decimal, 16 for hex)
 * @is_unsigned: whether the number is unsigned or not
 * @is_lowercase: checks for lowercase
 * Return: number of digits printed
 */

int print_number(int n, int base, int is_unsigned, int is_lowercase)
{
	char *digits = (is_lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	int printed = 0, i = 0, digit;
	char buffer[1024];

	if (is_unsigned == 1)
		n = (unsigned int) n;

	do {
		digit = n % base;
		buffer[i++] = digits[digit];
		n /= base;
	} while (n > 0);

	for (i = (i - 1); i >= 0; i--)
	{
		printed += _putchar(buffer[i]);
	}

	return (printed);
}
