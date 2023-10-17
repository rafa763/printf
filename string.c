#include "main.h"


/**
 * _string - print a string
 *
 * @ap: list of the passed arguments
 *
 * Return: the number of digits printed (int)
 */
int _string(va_list ap)
{
	int count;
	char *str = va_arg(ap, char *);

	count = 0;
	while (*str)
	{
		_putchar(*str++);
		count++;
	}

	return (count);
}
