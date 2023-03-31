#include "main.h"

/**
 * is_flag - checks if a character is a flag
 * @c: character to be checked
 * Return: (0) or (1)
 */
int is_flag(char c)
{
	char *flags = ".*+- 0123456789";
	
	while (*flags)
	{
		if (c == *flags)
			return (1);
		flags++;
	}

	return (0);
}
