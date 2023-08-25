#ifndef _PUTCHAR_H
#define _PUTCHAR_H

#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - function to print char
 * @c: char being passed
 * Return: number of prints
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
#endif /* _PUTCHAR_H */
