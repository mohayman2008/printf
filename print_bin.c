#include "main.h"

/**
 * print_bin - prints an unsigned integer to stdout in binary
 * @num: unsigned integer
 *
 * Return: number of printed characters
 */
int print_bin(unsigned int num)
{
	int sum;

	sum = 1;
	if (num / 2 != 0)
		sum += print_bin(num / 2);
	_putchar(num % 2 + '0');
	return (sum);
}
