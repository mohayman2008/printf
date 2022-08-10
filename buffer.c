#include "main.h"
#include <unistd.h>

/**
 * init_buffer - initialize the buffer memory
 * @buf: buffer struct
 * @size: size of the buffer
 *
 * Return: 1 on success or -1 on error or 0 if size is zero
 */
int init_buffer(buffer *buf, unsigned int size)
{
	unsigned int i = 0;

	if (!buf || !(buf->data))
		return (-1);
	if (size == 0)
		return (0);
	for (; i < size ; i++)
		buf->data[i] = '\0';
	buf->idx = 0;
	return (1);
}

/**
 * print_buffer - prints buffer to stdout
 * @buf: buffer struct
 *
 * Return: number of printed characters or -1 on error
 */
int print_buffer(buffer *buf)
{
	unsigned int sum = 0;

	if (!buf || !buf->data)
		return (-1);
	sum = write(1, buf->data, buf->idx);
	if (sum == buf->idx)
	{
		init_buffer(buf, BUFFER_SIZE);
		return (sum);
	}
	return (-1);
}

/**
 * ctobuf - writes a character to buffer at a specified index and shift the
 *		index to the next index
 * @buffer: destination buffer
 * @buffer_idx: offset from the beginning of the buffer
 * @c: character to be written
 *
 * Return: 1 on success or -1 on error
 */
int ctobuf(buffer *buf, char c)
{
	if (!buf || !buf->data)
		return (-1);
	buf->data[buf->idx] = c;
	(buf->idx)++;
	if (buf->idx == BUFFER_SIZE)
	{
		if (print_buffer(buf) < 0)
			return (-1);
	}
	return (1);
}
