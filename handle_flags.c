#include "main.h"


/**
 * handle_flag - handle flags if any
 * @format: format
 * @ap: argument list
 */


int handle_flag(const char *format, va_list ap)
{
	int rval, size = 0;

	if (*format > '0' && *format <= '9')
		rval = right_justify(va_arg(ap, int), format, size);
	else if (*format == '*')
	{
		size = v_arg(ap, int);
		rval = right_justify(va_arg(ap, int), format, size);
	}
	else
	{
		switch (format)
		{
			case '+':
				rval = handle_plus(va_arg(ap, int));
				break;
			case '-':
				rval = handle_minus(ap, ++format);
				break;
			case ' ':
				rval = handle_space(ap, ++format);
				break;
			case '#':
				rval = handle_hash(va_arg(ap, int));
				break;
			case '.':
				rval = handle_precision(ap, ++format);
				break;
			case '0':
				rval = handle_zero(ap, ++format);
			default:
				rval = _putchar('%');
				rval += _putchar(*format);
				break;


		}
	}

	return (rval);

}

/**
 * handle_plus - handle plus flag
 * @num: number
 */



int  handle_plus(int num)
{
	int rval;

	if (num >= 0)
		rval = _putchar('+');
	else
		rval = _putchar('-');
		
	/* print numbers */

	return (rval);
}






/**
 * handle_space - handle space flag
 * @num: number
 */



int handle_space(int num)
{
	int rval = 0;

	if (num >= 0)
		rval += putchar(' ');
	else
		rval += _putchar('-');
		
	/* print numbers */

	return (rval);
}


/**
 * handle_zero - handle zero flag
 * @num: number
 * @format: pointer to flag format
 */



void handle_zero(va_list ap, const char *format)
{
	int  flag_num, len;
	int i = 0, j = 0;

	if (*format == '*')

	if (num < 0)
	{
		_putchar('-');
		i++;
	}

	if (len > flag_num)
		/* print numbers */
	else
	{
		j = flag_num - len;

		while (i < j)
		{
			_putchar('0');
			i++;
		}

		/* print_number */ 
	}

}

/**
 * handle_minus - handle minus flag
 * @num: number
 * @format: pointer to flag format
 */



void handle_minus(int num, const char *format)
{
	int  flag_num = get_flag_num(format), len = count_digit(num);
	int i = 0, j = 0;

	if (num < 0)
	{
		_putchar('-');
		i++;
	}

	if (len > flag_num)
		/* print numbers */
	else
	{
		/* print_number */

		j = flag_num - len;

		while (i < j)
		{
			_putchar(' ');
			i++;
		}

	}

}




/**
 * get_flag_num - get the number in the flag
 * @format: flag format
 * Retrun: number in flag
 */


int get_flag_num(const char *format)
{

	char flag_num_str[6];
	int i = 0, flag_num;

	while(*format > '0' && *format <= '9')
	{
		flag_num_str[i++] = *format;
		format++;
	}

	flag_num = atoi(flag_num_str);
	return (flag_num);
}
