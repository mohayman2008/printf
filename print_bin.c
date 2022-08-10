#include "main.h"

/**
 * print_bin - prints an integer to stdout
 * @num: integer
 *
 * Return: number of printed characters or -1 on error
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
