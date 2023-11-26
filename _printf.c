#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - function my _printf
 * @format: string whit format to print
 *
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	va_list args;
	int valid = 0, len = 0;

	va_start(args, format);
	valid = _validate_char(format);
	if (valid == -1)
		return (valid);

	len = _print_format(format, args);
	va_end(args);
	
	return (len);
}
