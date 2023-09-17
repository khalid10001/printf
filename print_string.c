#include "main.h"

/**
 * print_string - prints a string
 * @types: List of arguments
 * @buffer: character variable buffer array to handle print
 * @flags: calculates flags
 * @width: get width.
 * @precision: ineger precision specification
 * @size: integer size specifier
 * Return: returns the number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int l = 0, x;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[l] != '\0')
		l++;

	if (precision >= 0 && precision < l)
		l = precision;

	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], l);
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (width);
		}
	}

	return (write(1, s, l));
}
