#include "main.h"
#include <stdlib.h>

void _print(unsigned int n, ...);

int main(void)
{
	_print(3, NULL, ", ", "Prueba Holberton");
	return (0);
}

void _print(unsigned int n, ...)
{
	va_list args;
	unsigned int i = 0;

	va_start(args, n);
	while (i < n)
	{
		_print_string(args);
		i++;
	}

	_putchar('\n');
	va_end(args);
}
