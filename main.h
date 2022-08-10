#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int check_char(const char c, const char *list);
int print_string(const char *str);
int print_int(int num);
int print_bin(unsigned int num);
int print_uint(unsigned int num);
int print_oct(unsigned int num);
int print_hex(unsigned int num, unsigned int lower);
int print_special(const char *format, unsigned int *idx, va_list al);
int _printf(const char *format, ...);

#endif
