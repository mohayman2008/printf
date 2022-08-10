#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct buffer - for managing a characters buffer
 * @data: buffer memory
 * @idx: index to the next available slot
 */
typedef struct buffer
{
	char *data;
	unsigned int idx;
} buffer;

int _putchar(char c);
int init_buffer(buffer *buf, unsigned int size);
int print_buffer(buffer *buf);
int ctobuf(buffer *buf, char c);
int check_char(const char c, const char *list);
int print_string(buffer *buf, const char *str);
int print_int(buffer *buf, int num);
int print_bin(buffer *buf, unsigned int num);
int print_uint(buffer *buf, unsigned int num);
int print_oct(buffer *buf, unsigned int num);
int print_hex(buffer *buf, unsigned int num, unsigned int lower);
int print_special(buffer *buf, const char *format, unsigned int *idx,
		va_list al);
int _printf(const char *format, ...);

#endif
