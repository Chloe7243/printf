#include "main.h"


/**
 * handle_plus - handle plus flag
 * @num: number
 */



void handle_plus(int num)
{
	if (num >= 0)
		_putchar('+');
	else
		_putchar('-');
		
	/* print numbers */
}






/**
 * handle_space - handle space flag
 * @num: number
 */



void handle_space(int num)
{
	if (num >= 0)
		_putchar(' ');
	else
		_putchar('-');
		
	/* print numbers */
}


/**
 * handle_zero - handle zero flag
 * @num: number
 * @format: pointer to flag format
 */



void handle_zero(int num, const char *format)
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
