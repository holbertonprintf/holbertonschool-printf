#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _validate_char - evaluate if each character of the string format is correct
 * @str_format: character
 *
 */


void _validate_char(const char *str_format)
{
	char array_type[2] = {'c', 's'};
	int i = 0, j = 0, flag_character = 0;

	if ((str_format != NULL) && (str_format[i] == '\0'))
		return (-1);
	while (str_format[i] != '\0')
	{
		if (str_format[i] == '%')
		{
			while (array_type[j])
			{
				if (str_format[i + 1] == array_type[j])
					flag_character = 1;
				j++;
			}
			if (flag_character == 0)
				return (-1);
			flag_character = 0;
		}
		i++;
	}
	return (0);
}

/**
 * _print_specifiers - prints valid specifiers
 * @format: The specifier to print
 * @args: a list of variadic arguments
 *
 * Return: the length
 */

int _print_specifiers(char format, va_list args)
{
	int i = 0; len = 0;
	spc _types[] = {
		{"c", _print_char},
		{"s", _print_string},
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
