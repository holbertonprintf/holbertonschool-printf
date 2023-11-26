#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct specifiers
{
	char *specifier;
	void (*f)(va_list args);
} spc;

int _putchar(char c);
int _printf(const char *format, ...);
void _print_char(va_list args);
void _print_string(va_list args);
char print_p(void);
int _strlen(char *str);
int _strlenc(const char *str);
void _validate_char(const char *str_format);

#endif
