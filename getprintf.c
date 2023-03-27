#include "main.h"
#include <stdio.h>

/**
 * get_printf - prints value
 *
 * @c: char value
 * @args: arguments
 *
 * Return: integer
 */

int get_printf(char c, va_list args)
{
	int digit, rval = 0;
	char *s;

	switch (c)
	{
		case 'c':
			rval += _putchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char*);
			rval += print_string(s);
			break;
		case '%':
			rval += _putchar('%');
			break;
		case 'd':
		case 'i':
			digit = va_arg(args, int);
			rval += count_digit(digit);
			print_digit(digit);
			break;
		default:
			rval += _putchar('%');
			rval += _putchar(c);
			break;
	}

	return (rval);
}
