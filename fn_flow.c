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
int (*fn_control(const char *s, va_list ap))(va_list ap)
{
	fn_ops ops[] = {
		{'c', _char},
		{'s', _string},
		{'d', _int},
		{'i', _int}
	};
	int i = 0;

	while (i < 4)
	{
		if (*s == ops[i].specifier)
		{
			(ops[i].control(ap));
		}
		i++;
	}

	return (NULL);
}
