#include "main.h"
/**
 * handle_string - prints a string with newline
 * @str: the string to print
 *
 * Return: number of prints.
 */
int handle_string(char *str)
{
	int g;

	g = 0;
	if (!str)
		str = "(null)";
	while (*str)
		g += write(1, str++, 1);
	return (g);
}
/**
 * _putchar - function to print char
 * @c: char being passed
 * Return: number of prints
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - Function to print a variety of data types
 * @format: The format string specifying the output format
 *
 * Return: The total number of bytes printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	const char *p = format;
	va_list args;

	va_start(args, format);
	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			if (*p == 'c')
			{
				p++;
				count += _putchar(va_arg(args, int));
			}
			else if (*p == 's')
			{
				p++;
				count += handle_string(va_arg(args, char *));
			}
			else if (*p == '%')
			{
				p++;
				count += _putchar('%');
			}
			else
			{
				_putchar('%');
				count += _putchar(*p);
			}
		}
		else if (*p != '%')
		{
			_putchar(*p);
			p++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
