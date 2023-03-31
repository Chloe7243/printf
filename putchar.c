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


/**
 * _puts_limit - prints a string to stdout with a limit
 * @str: pointer to the string to print
 * @limit: limit of string
 * Return: number of chars written
 */
int _puts_limit(char *str, int limit)
{
	register int i;

	for (i = 0; i < limit; i++)
		_putchar(str[i]);
	return (i);
}
