#include "main.h"

/**
 * print_uint - prints an unsigned integer to stdout
 * @num: unsigned integer
 *
 * Return: number of printed characters
 */
int print_uint(unsigned int num)
{
	int sum = 1;

	sum = 1;
	if (num / 10 != 0)
		sum += print_uint(num / 10);
	_putchar(num % 10 + '0');
	return (sum);
}

/**
 * print_oct - prints an unsigned integer to stdout in base 8
 * @num: unsigned integer
 *
 * Return: number of printed characters
 */
int print_oct(unsigned int num)
{
	int sum = 1;

	if (num / 8 != 0)
		sum += print_oct(num / 8);
	_putchar(num % 8 + '0');
	return (sum);
}

/**
 * print_hex - prints an unsigned integer to stdout
 * @num: unsigned integer
 * @lower: flag to print letter digits in lower case
 *
 * Return: number of printed characters
 */
int print_hex(unsigned int num, unsigned int lower)
{
	int sum = 1, offset = 'A' + (int) lower * ('a' - 'A') - 10;

	if (num / 16 != 0)
		sum += print_hex(num / 16, lower);
	_putchar(num % 16 + ((num % 16 > 9) ? offset : '0'));
	return (sum);
}
