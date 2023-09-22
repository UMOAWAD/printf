#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/**
 * _printf - Produces an output according to a format.
 *
 * @format: The string to print.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int i, n, j;
	char *print;
	va_list ap;
	va_start(ap, format);

	n = 0;
	print = malloc(sizeof(char) * sizeof(format));

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == '%')
			{
				print[n] = va_arg(ap, int);
				n++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *arg = va_arg(ap, char *);

				for (j = 0; arg[j] != '\0'; j++)
				{
					print[n] = arg[j];
					n++;
				}

				n++;
				i++;
			}
		}
		else
		{
			print[n] = format[i];
			n++;
		}
	}

	print[n] = '\0';

	write(1, print, n);

	va_end(ap);

	free(print);

	return(n);
}
