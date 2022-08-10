#include "main.h"

/**
 * print_uint - prints an unsigned integer to stdout
 * @buf: pointer to buffer struct
 * @num: unsigned integer
 *
 * Return: number of printed characters or -1 on error
 */
int print_uint(buffer *buf, unsigned int num)
{
	int sum = 1;

	if (!buf)
		return (-1);
	if (num / 10 != 0)
		sum += print_uint(buf, num / 10);
	ctobuf(buf, num % 10 + '0');
	return (sum);
}

/**
 * print_oct - prints an unsigned integer to stdout in base 8
 * @buf: pointer to buffer struct
 * @num: unsigned integer
 *
 * Return: number of printed characters or -1 on error
 */
int print_oct(buffer *buf, unsigned int num)
{
	int sum = 1;

	if (!buf)
		return (-1);
	if (num / 8 != 0)
		sum += print_oct(buf, num / 8);
	ctobuf(buf, num % 8 + '0');
	return (sum);
}

/**
 * print_hex - prints an unsigned integer to stdout
 * @buf: pointer to buffer struct
 * @num: unsigned integer
 * @lower: flag to print letter digits in lower case
 *
 * Return: number of printed characters or -1 on error
 */
int print_hex(buffer *buf, unsigned int num, unsigned int lower)
{
	int sum = 1, offset = 'A' + (int) lower * ('a' - 'A') - 10;

	if (!buf)
		return (-1);
	if (num / 16 != 0)
		sum += print_hex(buf, num / 16, lower);
	ctobuf(buf, (num % 16 + ((num % 16 > 9) ? offset : '0')));
	return (sum);
}

/**
 * print_lhex - prints an unsigned long integer to stdout
 * @buf: pointer to buffer struct
 * @num: unsigned long integer
 * @lower: flag to print letter digits in lower case
 *
 * Return: number of printed characters or -1 on error
 */
int print_lhex(buffer *buf, unsigned long int num, unsigned int lower)
{
	int sum = 1, offset = 'A' + (int) lower * ('a' - 'A') - 10;

	if (!buf)
		return (-1);
	if (num / 16 != 0)
		sum += print_lhex(buf, num / 16, lower);
	ctobuf(buf, (num % 16 + ((num % 16 > 9) ? offset : '0')));
	return (sum);
}
