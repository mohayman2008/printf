#include "main.h"

/**
 * print_int - prints an integer to stdout
 * @num: integer
 *
 * Return: number of printed characters or -1 on error
 */
int print_int(int num)
{
	int sum;

	if (num < 0)
	{
		_putchar('-');
		sum = 2;

		if (num / -10 > 0)
			sum += print_int(num / -10);
		_putchar((num % 10) * -1 + '0');
	}
	else
	{
		sum = 1;
		if (num / 10 > 0)
			sum += print_int(num / 10);
		_putchar(num % 10 + '0');
	}
	return (sum);
}
