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
	int i, j;
	va_list ap;
	va_start(ap, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == '%')
			{
				_writ(va_arg(ap, int);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *arg = va_arg(ap, char *);

				for (j = 0; arg[j] != '\0'; j++)
				{
					_writ(arg[j]);
				}
				i++;
			}
		}
		else
		{
			_writ(format[i]);
		}
	}

	_writ('\0');

	va_end(ap);

	return(n);
}

/**
 * _writ - prints a character.
 *
 * @c: The character to print.
 *
 * Return: write.
 */

int _writ(char c)
{
	return(write(1, &c, 1));
}
