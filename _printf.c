#include "main.h"
#include "_putchar.h"
/**
 * handle_string - prints a string with newline
 * @str: the string to print
 *
 * Return: number of prints.
 */

int handle_string(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		handle_string("(null)");
		return (6);
	}
	while (str[i])
	{
		putchar(str[i]);
		i++;
	}
	return (i);
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
				char c = va_arg(args, int);

				count += _putchar(c);
			}
			else if (*p == 's')
			{
				char *str = va_arg(args, char *);

				count += handle_string(str);
			}
			else if (*p == '%')
			{
				_putchar('%');
				count++; }
			else
			{
				continue;
			}
		}
		else
		{
			_putchar(*p);
			p++;
			count++; }
	}
	va_end(args);
	return (count);
}
/**
* main - Entry point of the program
* Return: number of prints.
*/
int main(void)
{
	int count;

	count = _printf("Hello, world %%\n");
	printf("The number of caracters is %d\n", count);

	return (0);

}
