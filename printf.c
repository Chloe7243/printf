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
	char *s;

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
			switch (*format)
			{
				case 'c':
					outlen += _putchar(va_arg(args, int));
					break;
				case 's':
					s = va_arg(args, char*);
					if (s == NULL)
						s = "(null)";

					while (*s)
					{
						outlen += _putchar(*s);
						s++;
					}
					break;
				case '%':
					outlen += _putchar('%');
					break;
				default:
					outlen += _putchar('%');
					outlen += _putchar(*format);
					break;
			}
			
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
