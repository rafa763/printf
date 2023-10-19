#include "main.h"

/**
 * _rev - revserses a string
 * @ap: list of the passed arguments
 *
 * Return: count of chars
 */
int _rev(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, size = 0, count = 0;

	while (str[size])
		size++;

	for (i = size - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
}
