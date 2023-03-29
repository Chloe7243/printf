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
 * print_rev_string - prints a string
 *
 * @s: string
 *
 * Return: int
 */

int print_rev_string(char *s)
{
	int count = 0, i = 0;

	if (s == NULL)
		_puts(")llun(");

	for (i = 0; s[i] != '\0'; i++)
		;
	i--;

	while (i >= 0)
	{
		count += _putchar(s[i]);
		i--;
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
		if ((*s < 32 || *s >= 127) && *s > 0)
		{
			count += _puts("\\x");
			if (*s <= 15)
				count += _putchar('0');
			count += print_number((unsigned int)*s, 16, 0);
		}
		else
			count += _putchar(*s);

		s++;
	}

	return (count);
}
