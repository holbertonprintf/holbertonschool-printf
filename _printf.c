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
	int len = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	len = _print_format(format, args);
	va_end(args);	
	return (len);
}
