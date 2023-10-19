#include "main.h"
#include <stdlib.h>

/**
 * fn_control - takes a flag and the argument and calls the
 * appropriate function to print
 *
 * @s: the format specifier
 * @ap: the list of the passed arguments
 *
 * Return: the number of chars printed (int)
 */
int fn_control(const char *s, va_list ap)
{
	fn_ops ops[] = {
		{'c', _char},
		{'s', _string},
		{'d', _int},
		{'i', _int},
		{'b', _bin},
		{'r', _rev},
		{0, NULL}
	};
	int i = 0;
	int chars_printed = 0;

	while (ops[i].specifier)
	{
		if (*s == ops[i].specifier)
			chars_printed += ops[i].control(ap);
		i++;
	}

	/*
	*if (chars_printed == 0)
	*{
	*	_putchar('%');
	*	_putchar(*s);
	*	chars_printed += 2;
	*}
	*/

	return (chars_printed);
}
