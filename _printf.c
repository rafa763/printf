#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - function that takes variable number of arguments
 * and prints them or point to another function to be called to print
 * different formats
 *
 * @format: the string to be printed
 *
 * Return: the number of printed characters (int)
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, chars, temp;

	va_start(ap, format);

	chars = 0;
	temp = 0;

	if (!format)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2]))
				return (-1);

			temp = fn_control(&format[i + 1], ap);
			chars += temp;


			if (temp == 0 && format[i + 1] == '%')
			{
				_putchar(format[i + 1]);
				chars++;
				i++;
			}
			else if (temp == 0)
			{
				_putchar(format[i]);
				chars++;
			}
			else
			{
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			chars++;
		}
	}

	va_end(ap);
	return (chars);
}
