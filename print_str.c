#include "main.h"

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

	if (!buf)
		return (-1);
	if (!str)
		str = "(null)";
	while (str[i])
		ctobuf(buf, str[i++]), sum++;
	return (sum);
}

/**
 * print_no_special - prints the printable characters of a string to stdout
 *		and replaces the unprintable with their ASCII values in hex
 * @buf: pointer to buffer struct
 * @str: string of unsigned chars
 *
 * Return: number of printed characters or -1 on error
 */
int print_no_special(buffer *buf, const unsigned char *str)
{
	int sum = 0, i = 0;

	if (!buf)
		return (-1);
	if (!str)
		str = (unsigned char *) "(null)";
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			sum += print_string(buf, "\\x");

			if (str[i] / 0x10 == 0)
				ctobuf(buf, '0'), sum++;
			sum += print_hex(buf, str[i], 0);
		}
		else
			ctobuf(buf, str[i]), sum++;
		i++;
	}
	return (sum);
}
