#include "main.h"

/**
 * print_int - prints an integer to stdout
 * @buf: pointer to buffer struct
 * @num: integer
 *
 * Return: number of printed characters
 */
int print_int(buffer *buf, int num)
{
	int sum;

	if (num < 0)
	{
		ctobuf(buf, '-');
		sum = 2;

		if (num / -10 > 0)
			sum += print_int(buf, num / -10);
		ctobuf(buf, (num % 10) * -1 + '0');
	}
	else
	{
		sum = 1;
		if (num / 10 > 0)
			sum += print_int(buf, num / 10);
		ctobuf(buf, num % 10 + '0');
	}
	return (sum);
}
