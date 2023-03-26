#include "main.h"

/**
 * _putchar - write a character to standard output stream
 * @c: character to be printed
 * Return: integer
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
