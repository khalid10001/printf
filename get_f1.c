#include "main.h"

/**
 * get_f1 - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: F1:
 */
int get_f1(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, k;
	int f1 = 0;
	const char FL_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FL_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (a = 0; FL_CH[a] != '\0'; a++)
			if (format[k] == FL_CH[a])
			{
				f1 |= FL_ARR[a];
				break;
			}

		if (FL_CH[a] == 0)
			break;
	}

	*i = k - 1;

	return (f1);
}
