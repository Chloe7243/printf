#include "main.h"
#include <stdio.h>

/**
 * print_string - prints a string
 *
 * @s: string
 *
 * Return: int
 */

int print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += _putchar(*s);
		s++;
	}

	return (count);
}




/**
 * print_string_S - prints a string in a special way
 *
 * @s: string
 *
 * Return: int
 */

int print_string_S(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		if ((*s < 32 && *s > 0) || *s >= 127)
		{
			puts("\\x");
			print_number((int) (*s), 16, 1, 0);
		}
		else
			count += _putchar(*s);

		s++;
	}

	return (count);
}
