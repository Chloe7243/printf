#include "main.h"
#include <stdio.h>

/**
 * _putchar - write a character to standard output stream
 * @c: character to be printed
 * Return: integer
 */

int _putchar(char c)
{
	if (sizeof(c) != 1)
	{
		system("clear");
	}
	return (write(STDOUT_FILENO, &c, 1));
}
