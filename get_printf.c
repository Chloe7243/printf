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
			rval += count_digit(digit, 10);
			print_digit(digit);
			break;
		case 'b':
			digit = va_arg(args, unsigned int);
			rval += print_binary(digit);
			break;
		case 'u':
			digit = va_arg(args, unsigned int);
			rval += print_number(digit, 10, 1);
			break;
		case 'o':
			digit = va_arg(args, unsigned int);
			rval += print_number(digit, 8, 1);
			break;
		case 'x':
			digit = va_arg(args, unsigned int);
			rval += print_number(digit, 16, 1);
			break;
		case 'X':
			digit = va_arg(args, unsigned int);
			rval += print_number(digit, 16, 0);
			break;
		case 'S':
			s = va_arg(args, char*);
			rval += print_string_S(s);
			break;
		case 'p':
			rval += print_address(va_arg(args, unsigned long int));
			break;
		case 'r':
			s = va_arg(args, char*);
			rval += print_rev_string(s);
			break;
		case 'R':
			s = va_arg(args, char*);
			rval += print_rot13_string(s);
			break;
		default:
			rval += _putchar('%');
			rval += _putchar(c);
			break;
	}

	return (rval);
}
