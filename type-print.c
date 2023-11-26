#include "main.h"
#include <stdlib.h>

/**
  * _print_char - Prints a char
  * @args: A list of arguments
  *
  * Return: The length of the character
  */
int _print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
  * _print_string - Prints a string
  * @args: A list of arguments
  *
  * Return: The length of the string
  */
int _print_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			_putchar(arg[i]);
			i++;
		}

		return (i);
	}
	else
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
}

/**
  * _print_decimal - Print decimal or integer
  * @args: A list of arguments
  *
  * Return: The length of the string
  */
int _print_decimal(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		_putchar('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	_integer(m);
	return (count);
}

/**
  * _integer - Prints a integer
  * @a: integer to print
  *
  * Return: Nothing
  */
void _integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		_integer(t / 10);
	_putchar(t % 10 + '0');
}
