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
	int i, outlen = 0;
	char flags[] = "#0 -+";
	FLAGS flag_struct;

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

			for (i = 0; flags[i] != '\0'; i++)
			{
				if (*format == flags[i])
				{
					flag_struct = get_flags(*format);
					break;
				}
			}
			outlen += get_printf(*format, args);
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
