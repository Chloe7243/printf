#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

typedef struct FLAGS
{
	int sign;
	int justify;
	int precision;
	int length;
	char flags[10];
} FLAGS;


int _putchar(char c);
int _puts(char *str);
int _printf(const char *frmat, ...);
int get_printf(char c, va_list args);
int get_printf_2(char c, va_list args);
void print_digit(int num);
int print_binary(unsigned int num);
int print_string(char *s);
int print_rev_string(char *s);
int print_rot13_string(char *s);
int print_string_S(char *s);
int count_digit(int num, int divisor);
int print_number(unsigned int n, int base, int is_lowercase);
int print_address(unsigned long int p);
int is_flag(char c);
FLAGS get_flags(const char *format);
int handle_flags(FLAGS flag_struct, const char *format);

#endif
