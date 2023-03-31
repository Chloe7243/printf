#include "main.h"

/**
 * _printf - Produces output according to a format
 *
 * @format: A character string containing zero or more directives
 *          to produce output
 * @...: A variable number of arguments to be printed according to
 *       the format
 *
 * Return: The number of characters printed (excluding the null byte
 *         used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list args;
	int outlen = 0;
	char int_size;
	char hash;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == '#')
			{
				if (*format == '#')
					hash = '#';
				format++;
			}
			if (*format == 'l' || *format == 'h')
			{
				if (*format == 'l')
					int_size = 'l';
				format++;
			}
			if (is_flag(*format))
			{
				handle_flag(format, args);
				format += count_flag(format);
			}
			else
				outlen += get_printf(hash, int_size, *format, args);
		}
		else
		{
			outlen += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (outlen);
}
