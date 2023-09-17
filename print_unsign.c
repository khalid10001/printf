#include "main.h"

int print_unsign(va_list types, char buffer[],
			int f1, int w1, int p1, int s1)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(num, size);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_unsign(0, x, buffer, f1, w1, p1, s1));
}
