#include "main.h"
#include <stdio.h>

/**
 * _putchar - write a character to standard output stream
 * @c: character to be printed
 * Return: integer
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: number of chars written
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
