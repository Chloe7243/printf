#include "main.h"
#include <stdio.h>

/**
 * print_number - prints a number to standard output stream
 * @n: number to be printed
 * @base: base of the number to be printed (e.g. 10 for decimal, 16 for hex)
 * @is_lowercase: checks for lowercase
 * Return: number of digits printed
 */

int print_number(unsigned long int n, int base, int is_lowercase, char *prefix)
{
	char *digits = (is_lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	int printed = 0, i = 0, digit;
	char buffer[1024];

	do {
		digit = n % base;
		buffer[i++] = digits[digit];
		n /= base;
	} while (n > 0);

	_puts(prefix);
	for (i = (i - 1); i >= 0; i--)
	{
		printed += _putchar(buffer[i]);
	}

	return (printed);
}

/**
 *  print_address - prints a number to standard output stream
 *  @p: number to be printed
 *   Return: number of printed values
 */

int print_address(unsigned long int p)
{
	int count = 0, i = 0, digit;
	char *digits = "0123456789abcdef";
	char buffer[1024];

	if (!p)
		return (_puts("(nil)"));
	count += _puts("0x");

	do {
		digit = p % 16;
		buffer[i++] = digits[digit];
		p /= 16;
	} while (p > 0);

	for (i = (i - 1); i >= 0; i--)
	{
		count += _putchar(buffer[i]);
	}

	return (count);
}

