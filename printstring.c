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
