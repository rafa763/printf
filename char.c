#include "main.h"

/**
 * _char - print a single char
 *
 * @ap: list of the passed arguments
 *
 * Return: the number of digits printed (1)
 */
int _char(va_list ap)
{
	int str = va_arg(ap, int);

	_putchar(str);
	return (1);
}
