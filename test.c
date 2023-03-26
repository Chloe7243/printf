#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;
	char *s = "steph's";
	char c = 'A';

	len = _printf("%cLet's try to printf %s%% sentence.\n", c, s);
	len2 = printf("%cLet's try to printf %s%% sentence.\n", c, s);

	printf("\nLen: %d\nLen2: %d\n", len, len2);


	return (0);
}
