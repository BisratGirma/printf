#include "holberton.h"
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
	char *s;
       	char ch;
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
				ch = va_arg(argument, int); 
				_putchar(ch);
			       i++;	
				break; 
			case 'd': 
				i = va_arg(argument, int);
				printint(i);
				i++;	
				break; 
			case 'u':
				i = va_arg(argument,unsigned int);
				printunsigned(i);
				i++;
				break;
			case 'o':
			        i = va_arg(argument, int);
				printint(i);
				i++;
				break;
			case 'i':
				i = va_arg(argument, int);
				printint(i);
				i++;
				break;
			case 's': 
				s = va_arg(argument, char *); 
				printstring(s);
			       i++;	
				break; 
			case 'x': 
				i = va_arg(argument, int); 
				printhex(i); 
				break; 
			case '%': 
				_putchar('%'); 
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

/**
 * printint - prints integers and decimals
 * @i: the integer to be printed.
 */
void printint(int i) 
{
	if (i < 0)
	{
		i = i * -1;
		_putchar('-');
	}
	if (i / 10 != 0)
		printint(i / 10);

	_putchar((i % 10) + '0');
}

void printstring(char *s) 
{ 
	for (; *s != '\0'; s++) 
		_putchar(*s); 
}

/**
 * printhex - prints hex number
 * @i: the number to be hexed
 */
void printhex(int i) 
{
	_putchar(i);
}
