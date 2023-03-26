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

	va_start(args, format);
	len = strlen(format);

	if (!format || (format[0] == '%' & !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					outlen += _putchar(va_arg(args, int));
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
					break;
				case '%':
					outlen += _putchar('%');
					break;
			}
		}
		else
			outlen += _putchar(format[i]);
	}
	va_end(args);

	return (outlen);
}
