#include "main.h"
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: constants pointer character variable
 * Return: the number of characters
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);

while (*format)
if (*format == '%')
format++;
switch (*format)
case 'c':
char c = va_arg(args, int);
putchar(c);
count++;
break;
case 's':
char *str = va_arg(args, char *);
while (*str)
putchar(*str);
str++;
count++;
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
else
putchar(*format);
count++;
format++;
va_end(args);
return (count);
}
