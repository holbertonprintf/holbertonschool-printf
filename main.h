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
	int (*f)(va_list args);
} spc;

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list args);
int _print_string(va_list args);
int _print_format(const char *format, va_list args);
int print_percentage(void);
int _strlen(char *str);
int _strlenc(const char *str);
int _validate_char(const char *str_format);
int _print_specifiers(char format, va_list args);
int _print_invalid(char prev_format, char format, int count);

#endif
