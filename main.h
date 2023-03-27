#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int get_printf(char c, va_list args);
int print_digit(int num);
int print_string(char *s);

#endif
