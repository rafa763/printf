#include "main.h"
#include <stdlib.h>

/**
 * _int - determine the integer base and print the decimal ones
 * @ap: list of the passed arguments
 *
 * Return: number of the printed characters (int)
 */
int _int(va_list ap)
{
	int count;
	char *s, *p;

	s = int_stringify(va_arg(ap, int));
	p = s;

	if (*s == '0' && *(s + 1) == 'x')
		p = base(s, 16);
	else if (*s == '0' && (*s == 'b' || *s == 'B'))
		p = base(s, 2);
	else if (*s == '0')
		p = base(s, 8);

	count = 0;
	while (*p)
	{
		_putchar(*p++);
		count++;
	}

	free(s);
	return (count);
}

/**
 * int_length - determine the length of number recursively
 * @num: the passed number
 *
 * Return: the length of the number (int)
 */
int int_length(int num)
{
	if (num == 0)
		return (0);

	return (1 + int_length(num / 10));
}


/**
 * int_stringify - converts a number to a string
 * @num: the passed number to be converted
 *
 * Return: pointer to the converted string (char*)
 */
char *int_stringify(int num)
{
	char *str, *p;
	int negative = 0, len = 0, i;

	if (num < 0)
	{
		negative = 1;
		num *= -1;
		len = int_length(num) + 1;
	}
	else
	{
		len = int_length(num);
	}

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);

	p = str;
	while (num)
	{
		*str++ = num % 10 + '0';
		num /= 10;
	}

	if (negative)
		*str++ = '-';
	*str = '\0';

	for (i = 0; i < len / 2; i++)
	{
		p[i] ^= p[len - 1 - i];
		p[len - 1 - i] ^= p[i];
		p[i] ^= p[len - 1 - i];
	}

	return (p);
}
