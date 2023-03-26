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
	char *s = "steph";
	char c = 65;
	char c2 = 97;

	len = _printf("This is %c, %s sence\n", c2, s);
	len2 = printf("%c, %s", c, s);

	printf("\nLen: %d\nLen2: %d\n", len, len2);


	return (0);
}
