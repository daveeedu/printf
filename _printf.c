#include "main.h"


/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list args;
	char *buf;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;
			if (format[i] == '%')
			{
				_putchar('%');
				i++;
				continue;
			}
			f = get_func(format[i]);
			if (f == NULL)
				return (-1);
			len = f(args);
			i++;
		}
		else
		{
			_putchar(format[i]);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}


