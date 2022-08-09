#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - prints a character to stdout
 * @c: character to be printed
 *
 * Return: 1 if successfully printed
 *	or -1 on error and errno is set to indicate the error
 */
int _putchar(char c)
{
	return (write(stdout, &c, 1));
}
