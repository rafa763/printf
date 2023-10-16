#include "main.h"
#include <unistd.h>

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
	int chars;

	va_start(ap, format);

	chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			chars += (int)fn_control(++format, ap);
			format++;
		}
		_putchar(*format);
		format++;
		chars++;
	}

	va_end(ap);
	return (chars);
}
