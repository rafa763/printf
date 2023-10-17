#include "main.h"

/**
 * power - calculate the power of a number recursively
 * @base: base of the number
 * @exponent: power of the base
 *
 * Return: the integer raised to the @exponent
 */
int power(int base, int exponent)
{
	if (exponent == 0)
		return (1);

	return (base * power(base, exponent - 1));
}


/**
 * base - convert any number of any base to decimal
 * @num: the passed number
 * @b: the base of that number
 *
 * Return: stringfied decimal format
 */
char *base(char *num, int b)
{
	char *n;
	int i, digit;
	int length = 0, conv = 0;

	while (num[length])
		length++;

	for (i = 0; i < length; i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
			digit = num[i] - '0';
		else if (num[i] >= 'A' && num[i] <= 'F')
			digit = num[i] - 'A' + 10;
		else if (num[i] >= 'a' && num[i] <= 'f')
			digit = num[i] - 'f' + 10;

		conv += digit * power(b, i);
	}

	n = int_stringify(conv);
	return (n);
}
