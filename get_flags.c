#include "main.h"


/**
 * get_flags - define the properties of the flag if they exist
 * @format: string to get flags from
 * Return: FLAGS structure
 */


FLAGS get_flags(char *format)
{
	FLAGS flag_struct = {.sign = 0, .justify = 0, .precision = 0, .length = 0};
	char *flags = flag_struct.flags;

	while (is_flag(*format))
	{

		flag_struct.flags[flag_struct.length] = *format; 
		flag_struct.length += 1;
		format++;
	}
	format++;


	if (*format > '0' &&  *format <= '9')
	{
		flag_struct.length += 1;
		flag_struct.precision = atoi(*format);
	}
	while (*flags)
	{
		if (*flags == '+' || *flags == ' ')
			flag_struct.sign += 1;
		if (*flags == '0' || *flags == '-')
			flag_struct.justify += 1;

		flags++;
	}

	return (flag_struct);
}



/**
 * is_flag - checks if a character is a flag
 * @c: character to be checked
 * Return; (0) or (1)
 */
int is_flag(char c)
{
	char *flags = "#+- 0";
	
	while (*flags)
	{
		if (c == *flags)
			return (1);
	}

	return (0);
}
