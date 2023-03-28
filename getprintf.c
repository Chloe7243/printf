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

	digit = va_arg(args, int);
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
			rval += count_digit(digit, 10);
			print_digit(digit);
			break;
		case 'b':
			digit = va_arg(args, unsigned int);
			rval += (count_digit(digit, 2) - 1);
			print_binary(digit);
			break;
		case 'u':
			rval += print_number(digit, 10, 1, 1);
			break;
		case 'o':
			rval += print_number(digit, 8, 1, 1);
			break;
		case 'x':
			rval += print_number(digit, 16, 1, 1);
			break;
		case 'X':
			rval += print_number(digit, 16, 1, 0);
			break;
		case 'S':
			s = va_arg(args, char*);
			rval += print_string_S(s);
			break;
		default:
			rval += _putchar('%');
			rval += _putchar(c);
			break;
	}

	return (rval);
}
