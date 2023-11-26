#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * _print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int _print_format(const char *format, va_list args)
{
	int count = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);

			i++;

			while (format[i] == ' ')
				i++;

			if (format[i] == '%')
				count += _putchar(format[i]);

			if (_validate_char(format[i]) == 0)
			{
				count = _print_invalid(format[i - 1], format[i], count);
			}
			else
			{
				count += _print_specificiers(format[i], args);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}

		i++;
	}

	return (count);
}

/**
 * _print_specificiers - prints valid specifiers
 * @format: The specifier to print
 * @args: a list of variadic arguments
 *
 * Return: the length
 */

int _print_specificiers(char format, va_list args)
{
	int i = 0;
	int len = 0;
	spc _types[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"d", _print_decimal},
		{"i", _print_decimal},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			len = _types[i].f(args);

		i++;
	}

	return (len);
}

/**
 * _print_invalid - prints invalid specifiers
 * @prev_format: The previous specifier of actual specifier
 * @format: The specifier to prints
 * @count: The current count before prints invalid specifiers
 *
 * Return: The current count after prints invalidspecifiers
 */

int _print_invalid(char prev_format, char format, int count)
{
	count += _putchar('%');

	if (prev_format == ' ')
	{
		count += _putchar(' ');
		count += _putchar(format);
	}
	else
	{
		count += _putchar(format);
	}

	return (count);
}

/**
  * _validate_char - validate the type
  * @_type: character to be comparate
  *
  * Return: 1 if char is equal
  */
int _validate_char(char _type)
{
	char _types[] = {'c', 's', '%', 'd', 'i'};
	int i = 0;

	while (_types[i])
	{
		if (_types[i] == _type)
			return (1);
		i++;
	}
	return (0);
}
