#ifndef _MAIN_H_
#define _MAIN_H_

/* Importing Libraries */
#include <stdarg.h>


/* Type definitions */

/**
 * struct fn_ops - controls the flow of the print function
 * @specifier: what will come after the % sign
 * @control: function pointer that will pointer to the function
 * matching the specifier
 */
typedef struct fn_ops
{
	char specifier;
	int (*control)(va_list ap);
} fn_ops;


/* Function Prototypes */
int fn_control(const char *s, va_list ap);
int _putchar(char c);
char *int_stringify(long int num);
int _printf(const char *format, ...);
int _char(va_list ap);
int _string(va_list ap);
int _int(va_list ap);
int _bin(va_list ap);
int int_length(int num);
char *base(char *num, int b);
char *reverse_str(char *p, int size);
int _rev(va_list ap);

#endif /* _MAIN_H_ */
