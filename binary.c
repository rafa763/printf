#include "main.h"
#include <stdlib.h>

/**
 * _bin - convert passed decimal to binary
 * @ap: list of the passed arguments
 *
 * Return: number of characters printed (int)
 */
int _bin(va_list ap)
{
	int count = 0, temp;
	int num = va_arg(ap, int);
	char *s = NULL, *p = NULL;
	int size = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	for (temp = num; temp > 0; size++)
		temp /= 2;

	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (0);

	p = s;
	while (num > 0)
	{
		*p = (num % 2) + '0';
		num /= 2;
		p++;
	}
	*p = '\0';

	p = s;
	reverse_str(p, size);

	while (*p)
	{
		_putchar(*p++);
		count++;
	}

	free(s);
	return (count);
}

/**
 * reverse_str - reverse a passed string
 * @p: pointer to the passed string
 * @size: the length of the string
 *
 * Return: pointer to the reversed string (char *)
 */
char *reverse_str(char *p, int size)
{
	int i;

	for (i = 0; i < size / 2; i++)
	{
		p[i] ^= p[size - 1 - i];
		p[size - 1 - i] ^= p[i];
		p[i] ^= p[size - 1 - i];
	}

	return (p);
}
