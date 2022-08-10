#include "main.h"

/**
 * print_ptr - prints a void *ptr to stdout
 * @buf: pointer to buffer struct
 * @ptr: (void *) pointer
 *
 * Return: number of printed characters or -1 on error
 */
int print_ptr(buffer *buf, void *ptr)
{
	unsigned long int add = (unsigned long int) ptr;
	int sum = 0;

	if (!buf)
		return (-1);
	if (!ptr)
		return (print_string(buf, "(nil)"));
	
	sum += print_string(buf, "0x");
	sum += print_lhex(buf, add, 1);
	return (sum);
}
