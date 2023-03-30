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

int get_printf(char hash, char size, char c, va_list args)
{
	int rval = 0;
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
		case 'S':
			s = va_arg(args, char*);
			rval += print_string_S(s);
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
			rval += get_printf_2(hash, size, c, args);
			break;
	}

	return (rval);
}

/**
 * get_printf_2 - prints value
 *
 * @c: char value
 * @args: arguments
 *
 * Return: integer
 */

int get_printf_2(char hash, char size, char c, va_list args)
{
	long int digit, rval = 0;
	char *prefix = "";

	switch (c)
	{
		case 'd':
		case 'i':
			digit = (size == 'l') ? va_arg(args, long int) : va_arg(args, int);
			rval += count_digit(digit, 10);
			print_digit(digit);
			break;
		case 'b':
			digit = va_arg(args, unsigned int);
			rval += print_binary(digit);
			break;
		case 'p':
			rval += print_address(va_arg(args, unsigned long int));
			break;
		case 'u':
			digit = (size == 'l') ? va_arg(args, unsigned long int) : va_arg(args, unsigned int);
			rval += print_number(digit, 10, 1, prefix);
			break;
		case 'o':
			if (hash == '#')
				prefix = "0";
			digit = (size == 'l') ? va_arg(args, unsigned long int) : va_arg(args, unsigned int);
			rval += print_number(digit, 8, 1, prefix);
			break;
		case 'x':
			if (hash == '#')
				prefix = "0x";
			digit = (size == 'l') ? va_arg(args, unsigned long int) : va_arg(args, unsigned int);
			rval += print_number(digit, 16, 1, prefix);
			break;
		case 'X':
			if (hash == '#')
				prefix = "0X";
			digit = (size == 'l') ? va_arg(args, unsigned long int) : va_arg(args, unsigned int);
			rval += print_number(digit, 16, 0, prefix);
			break;
		default:
			rval += _putchar('%');
			rval += _putchar(c);
			break;
	}

	return (rval);
}
