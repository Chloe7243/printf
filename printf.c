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
	int printed = 0;
	char c;
	char *str;

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					printed += write(1, &c, 1);
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						printed += write(1, str, 1);
						str++;
					}
					break;
				case '%':
					printed += write(1, "%", 1);
					break;
				default:
					printed += write(1, "%", 1);
					printed += write(1, &(*format), 1);
					break;
			}
		}
		else
		{
			printed += write(1, &(*format), 1);
		}

		format++;
	}

	va_end(args);

	return (printed);
}
