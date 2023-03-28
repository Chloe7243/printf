#include "main.h"


/**
 * print_number - prints a number to standard output stream
 * @n: number to be printed
 * @base: base of the number to be printed (e.g. 10 for decimal, 16 for hex)
 * @is_unsigned: whether the number is unsigned or not
 * Return: number of digits printed
 */

int print_number(int n, int base, int is_unsigned)
{
	char *digits = "0123456789abcdef";
	int printed, i = 0, digit;
	char buffer[1024];


	if (is_unsigned == 1)
		n = (unsigned int) n;

	do
	{
		digit = n % base;
		buffer[i++] = digits[digit];
		n /= base;
	} while (n > 0);

	for (i = (i -1); i >= 0; i--)
		printed += _putchar(buffer[i]);

	return (printed);
}
