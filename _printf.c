#include "main.h"

/**
 * check_char - checks if a character belongs to NUL terminated string
 * @c: character to be checked
 * @list: string of characters to check against
 *
 * Return: 1 if true, 0 if not, -1 on error
 */
int check_char(const char c, const char *list)
{
	unsigned int i = 0;

	if (!list)
		return (-1);
	while (list[i])
		if (c == list[i++])
			return (1);
	return (0);
}


/**
 * print_string - prints a string to stdout
 * @buf: pointer to buffer struct
 * @str: string
 *
 * Return: number of printed characters or -1 on error
 */
int print_string(buffer *buf, const char *str)
{
	int sum = 0, i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		ctobuf(buf, str[i++]), sum++;
	return (sum);
}

/**
 * print_special - print special character or formatted data in format string
 *	and sets the index into the first character after the special substring
 * @buf: pointer to buffer struct
 * @format: format string
 * @idx: pointer to the starting index integer
 * @al: arguments list
 *
 * Return: number of printed characters
 */
int print_special(buffer *buf, const char *format, unsigned int *idx,
		va_list al)
{
	int sum = 0;
	unsigned int i = *idx, ui;

	if (format[i] == '%')
	{
		i++;

		if (!format[i])
			(*idx) = ++i, sum = -1;
		else if (format[i] == '%')
			ctobuf(buf, format[i]), (*idx) = ++i, sum = 1;
		else if (format[i] == 'c')
			ctobuf(buf, va_arg(al, int)), (*idx) = ++i, sum = 1;
		else if (format[i] == 's')
			sum = print_string(buf, va_arg(al, char*)), (*idx) = ++i;
		else if (format[i] == 'd' || format[i] == 'i')
			sum = print_int(buf, va_arg(al, int)), (*idx) = ++i;
		else if (format[i] == 'b')
			sum = print_bin(buf, va_arg(al, unsigned int)), (*idx) = ++i;
		else if (format[i] == 'u')
			sum = print_uint(buf, va_arg(al, unsigned int)), (*idx) = ++i;
		else if (format[i] == 'o')
			sum = print_oct(buf, va_arg(al, unsigned int)), (*idx) = ++i;
		else if (format[i] == 'x' || format[i] == 'X')
		{
			ui = va_arg(al, unsigned int);
			sum = print_hex(buf, ui, (format[i] - 'X') / ('x' - 'X'));
			(*idx) = ++i;
		}
		else
			ctobuf(buf, format[i - 1]), (*idx) = i, sum = 1;
	}
	return (sum);
}

/**
 * _printf - print to stdout according to format string
 * @format: format string
 *
 * Return: number of printed characters, or -1 on error
 */
int _printf(const char *format, ...)
{
	int sum = 0, n_printed = 0;
	unsigned int i = 0;
	va_list al;
	buffer buf;

	if (!format)
		return (-1);
	buf.data = malloc(sizeof(*(buf.data)) * BUFFER_SIZE);
	if (!buf.data)
		return (-1);
	init_buffer(&buf, BUFFER_SIZE);
	va_start(al, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			n_printed = print_special(&buf, format, &i, al);
			if (n_printed < 0)
			{
				sum = n_printed, free(buf.data);
				break;
			}
			sum += n_printed;
		}
		else
		{
			ctobuf(&buf, format[i]);
			i++, sum++;
		}
	}
	print_buffer(&buf), free(buf.data), va_end(al);
	return (sum);
}
