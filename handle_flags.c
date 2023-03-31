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
		rval = right_justify(ap, *format, size);
	else if (*format == '*')
	{
		size = v_arg(ap, int);
		rval = right_justify(ap, *format, size);
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
				rval = handle_space(va_arg(ap, int));
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
		
	rval += count_digit(num, 10);
	print_digit(num);

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
		
	
	
	rval += count_digit(num, 10);
	print_digit(num);

	return (rval);
}


/**
 * handle_zero - handle zero flag
 * @num: number
 * @format: pointer to flag format
 */



int  handle_zero(va_list ap, const char *format)
{
	int  flag_num, num, len, i = 0, j = 0, rval = 0;

	if (*format == '*')
	{
		format++;
		flag_num = va_arg(ap, int);
		num = va_arg(ap, int);
		len = count_digit(num);
	}
	else
	{
		flag_num = get_flag_num(format);
		num = va_arg(ap, int);
		len = count_digit(num);
	}

	if (num < 0)
	{
		rval += _putchar('-');
		i++;
	}
	if (len > flag_num)
	{
		/* rval += print numbers */
	}
	else
	{
		rval = flag_num;
		j = flag_num - len;

		while (i < j)
		{
			_putchar('0');
			i++;
		}
		/* print_number */ 
	}
	return (rval);
}

/**
 * handle_minus - handle minus flag (left justify)
 * @num: number
 * @format: pointer to flag format
 */



void handle_minus(int num, const char *format)
{	
	int  flag_num, num, len, i = 0, j = 0, rval = 0;

	if (*format == '*')
	{
		format++;
		flag_num = va_arg(ap, int);
		num = va_arg(ap, int);
		len = count_digit(num);
	}
	else
	{
		flag_num = get_flag_num(format);
		num = va_arg(ap, int);
		len = count_digit(num);
	}

	if (num < 0)
	{
		rval += _putchar('-');
		i++;
	}
	if (len > flag_num)
	{
		/* rval += print numbers */
	}
	else
	{
		rval = flag_num;
		j = flag_num - len;

		/* print_number */ 

		while (i < j)
		{
			_putchar(' ');
			i++;
		}
	}
	return (rval);
}

/**
 * handle_precision - handle precision flag
 * @ap: argument list
 * @format: format of flag
 */

int handle_precision(va_list ap, const char* format)
{
	int flag_num, num, len, rval = 0, i = 0;
	if (*format == '*')
	{
		flag_num = va_arg(ap, int);
		format++;
	}
	else
		flag_num = get_flag_num(format);

	format += count_digit(flag_num, 10);

	if (*format == 's' || *format == 'c')
	{
		rval += _puts_limit(va_arg(ap, char *), flag_num);
		return (rval);
	}

	num = va_arg(ap, int);
	len = count_digit(num, 10);

	if (num < 0)
	{
		rval += _putchar('-');
		i++;
	}

	if (flag_num > len)
	{
		j = flag_num - len;
		while (i < j)
		{
			_putchar('0');
			i++;
		}
		/* print number */
		rval = flag_num;
	}
	else
		/* rval += print number */
	return (rval);
}




/**
 * right_justify - justify stuff right
 * @ap: argument list
 * @c: non-conversion format specifier
 * @size: size
 */

int right_justify(va_list ap, char c, int size)
{
	int is_string = 0, rval = 0;

	if (c == 's' || c == 'c')
		is_string++;

	if (is_string)
		rval += justify_string(va_arg(ap, char *), size);
	else
		rval += justify_number(va_arg(ap, int), size);

	

}

int justify_string(char *str, int size)
{
	int rval = 0, len = strlen(str), i = 0, j;

	j = size - len;
	if (j > 0)
	{
		while (i < j)
		{
			_putchar(' ');
			i++;
		}
		_puts(str);
		rval = size;
	}
	else
		rval += _puts(str);

	return (rval);
}


int justify_number(int num, int size)
{
	int rval = 0, len = count_digit(num, 10), i = 0, j;

	j = size - len;
	if (j > 0)
	{
		while (i < j)
		{
			_putchar(' ');
			i++;
		}
		/* print number */
		rval = size;
	}
	else
		/* rval += _print number); */

	return (rval);
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
