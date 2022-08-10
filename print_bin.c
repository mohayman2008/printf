#include "main.h"

/**
 * print_bin - prints an unsigned integer to stdout in binary
 * @buf: pointer to buffer struct
 * @num: unsigned integer
 *
 * Return: number of printed characters
 */
int print_bin(buffer *buf, unsigned int num)
{
	int sum;

	sum = 1;
	if (num / 2 != 0)
		sum += print_bin(buf, num / 2);
	ctobuf(buf, num % 2 + '0');
	return (sum);
}
