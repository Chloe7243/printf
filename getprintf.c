#include "main.h"

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
			while (*s != '\0')
			{
				rval += _putchar(*s);
				s++;
			}
			break;
		case '%':
			rval += _putchar('%');
			break;
	}

	return (rval);
}
