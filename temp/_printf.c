#include "holberton.h"
#include "functions.c"
#include <stdarg.h>

/**
 * _printf - prints characters.
 * @str: strings.
 * 
 * Return: the number of characters printed.
 */ 

int _printf(char *format, ...)
{
	va_list argument; 
	int i = 0; 
	va_start(argument, format);

	for(; *format != '\0'; format++) 
	{ 
		if(*format != '%') 
		{ 
			_putchar(*format);
		       i++;	
			continue; 
		} 
		switch(*++format) 
		{ 
			case 'c': 
				_putchar(va_arg(argument, int));
			       i++;	
				break; 
			case 'd': 
				printint(va_arg(argument, int));
				i++;	
				break; 
			case 'u':
				printunsigned(va_arg(argument, unsigned int));
				i++;
				break;
			case 'o':
				i = i + printocta(va_arg(argument, unsigned int));
				break;
			case 'i':
				i = va_arg(argument, int);
				printint(i);
				i++;
				break;
			case 's' : 
				printstring(va_arg(argument, char *));
			       i++;	
				break; 
            case 'S': 
				printstring(va_arg(argument, char *));
			       i++;	
				break; 
			case 'x': 
				i = i + printhex(va_arg(argument, unsigned int));
				break; 
			case '%': 
				_putchar('%'); 
				i++;
				break;
            case 'b': 
            i = va_arg(argument, int);
            print_binary(i); 
            i++;
            break;
		} 
	} 
	va_end(argument);

	
	return (i);
}

/**
 * printunsigned - prints unsinged int
 * @i: the unsigned integer.
 */
void printunsigned(unsigned int i)
{
	if (i / 10 != 0)
	       printunsigned(i / 10);
	_putchar((i % 10) + '0');
}
