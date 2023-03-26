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
	int i, j, size, len, outlen = 0;
	char *s;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	len = strlen(format);

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					outlen += _putchar(va_arg(args, int));
					i++;
					break;
				case 's':
					j = 0;
					s = va_arg(args, char*);
					size = strlen(s);
					while (j < size)
					{
						outlen += _putchar(s[j]);
						j++;
					}
					i++;
					break;
				case '%':
					outlen += _putchar('%');
					i++;
					break;
				default:
					return(-1);
			}
			continue;
		}
		outlen += _putchar(format[i]);
	}
	va_end(args);

	return (outlen);
}
