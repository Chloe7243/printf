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
int _puts_limit(char *str, int limit);
int _printf(const char *format, ...);
int get_printf(char hash, char size, char c, va_list args);
int get_printf_2(char hash, char size, char c, va_list args);
void print_digit(long int num);
int print_binary(unsigned int num);
int print_string(char *s);
int print_rev_string(char *s);
int print_rot13_string(char *s);
int print_string_S(char *s);
int count_digit(long int num, int divisor);
int print_number(unsigned long int n, int base, int is_lowercase, char *prefix);
int print_address(unsigned long int p);
int is_flag(char c);
FLAGS get_flags(const char *format);
int handle_flag(const char *format, va_list ap);
int  handle_plus(int num);
int handle_space(int num);
int  handle_zero(va_list ap, const char *format);
int handle_minus(int num, const char *format);
int handle_precision(va_list ap, const char* format);
int right_justify(va_list ap, char c, int size);
int justify_string(char *str, int size);
int justify_number(va_list ap, char c, int size);
char get_specifier(const char *format);
int get_flag_num(const char *format);
int count_flag(const char *format);
#endif
