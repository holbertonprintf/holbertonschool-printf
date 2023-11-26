#include "main.h"
#include <stdlib.h>

/**
  * _print_char - Prints a char
  * @args: A list of arguments
  *
  * Return: print
  */
void _print_char(va_list args)
{
	_putchar(va_arg(args, int));
}

/**
  * _print_string - Prints a string
  * @args: A list of arguments
  *
  * Return: print
  */
void _print_string(va_list args)
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
	}
}
