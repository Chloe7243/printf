#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


int _putchar(char c);
int _puts(char *str);
int _printf(const char *frmat, ...);
int get_printf(char c, va_list args);
void print_digit(int num);
int print_binary(unsigned int num);
int print_string(char *s);
int print_rev_string(char *s);
int print_string_S(char *s);
int count_digit(int num, int divisor);
int print_number(unsigned int n, int base, int is_lowercase);
int print_address(unsigned long int p);

#endif
