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
 * @str: string
 *
 * Return: number of printed characters or -1 on error
 */
int print_string(const char *str)
{
	int sum = 0, i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]), sum++;
	return (sum);
}

/**
 * print_special - print special character or formatted data in format string
 *	and sets the index into the first character after the special substring
 * @format: format string
 * @idx: pointer to the starting index integer
 * @al: arguments list
 *
 * Return: number of printed characters
 */
int print_special(const char *format, unsigned int *idx, va_list al)
{
	int sum = 0;
	unsigned int i = *idx;

	if (format[i] == '%')
	{
		i++;

		if (!format[i])
			(*idx) = ++i, sum = -1;
		else if (format[i] == '%')
			_putchar(format[i]), (*idx) = ++i, sum = 1;
		else if (format[i] == 'c')
			_putchar(va_arg(al, int)), (*idx) = ++i, sum = 1;
		else if (format[i] == 's')
			sum = print_string(va_arg(al, char*)), (*idx) = ++i;
		else if (format[i] == 'd' || format[i] == 'i')
			sum = print_int(va_arg(al, int)), (*idx) = ++i;
		else if (format[i] == 'b')
			sum = print_bin(va_arg(al, unsigned int)), (*idx) = ++i;
		else
			_putchar(format[i - 1]), (*idx) = i, sum = 1;
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

	if (!format)
	{
		return (-1);
	}
	va_start(al, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			n_printed = print_special(format, &i, al);
			if (n_printed < 0)
				return (n_printed);
			sum += n_printed;
		}
		else
		{
			_putchar(format[i]);
			i++, sum++;
		}
	}
	va_end(al);
	return (sum);
}
