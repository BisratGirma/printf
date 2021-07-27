#include "holberton.h"
#include <stdarg.h>
/**
 * _printf - prints characters.
 * @str: strings.
 */ 

int _printf(char *str, ...)
{
	int count = 0;
	int printint;
	char intstr[10];
       	char *printstr;
	va_list args;

	va_start(args, str);

	while(*str)
	{
		if (*str == '%')
		{
			str++;
			switch(*str)
			{
				case 's':
					printstr = va_arg(args, char *);
					_putchar(printstr);
					str++;
					count += strlen(printstr);
				       break;
				case 'i':
					printint = va_arg(args, int);
				 	_itoa(printint, intstr, 10);
					_putchar(intstr);
					str++;
					count += strlen(intstr);
					break;
				case '%':
					_putchar('%');
					str++;
					count++;
					break;
				case '\0':
					break;
				default:
					_putchar('%');
					_putchar(*str);
					str++;
					count += 2;
			}
		}
		else 
		{
			_putchar(*str);
			str++;
			count++;
		}
	}
	return (count);
}
