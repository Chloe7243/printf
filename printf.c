#include "main.h"

/**
 * _printf - advanced replica of printf function
 *
 * @format: string input
 *
 * Return: length of output string
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, len, outlen = 0;

	va_start(args, format);
	len = strlen(format);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			outlen += get_printf(format[i], args);
		}
		else
			outlen += _putchar(format[i]);
	}

	va_end(args);

	return (outlen);
}
