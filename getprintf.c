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
	int rval = 0;
	char *s;

	switch (c)
	{
		case 'c':
			rval += _putchar(va_arg(args, int));
			break;
		case 's':
			s = va_arg(args, char*);
			if (!s)
				s = "(nil)";

			while (*s != '\0')
			{
				rval += _putchar(*s);
				s++;
			}
			break;
		case '%':
			rval += _putchar('%');
			break;
		default:
			rval += _putchar(c);
	}

	return (rval);
}
