#include "holberton.h"
#include <stdarg.h>

/**
 * _printf - prints characters.
 * @str: strings.
 */ 

int _printf(char *format, ...)
{
	va_list argument; 
	int i = 0; 
	char *s;
       	char ch;
	/* 
	 * char fmtbuf[256];
	 */
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
				break;
		} 
	} 
	va_end(argument);

	
	return (i);
}

void printint(int i) 
{
	if (i < 0)
		_putchar('-');
	if (i / 10 != 0)
		printint(i / 10);
	_putchar((i % 10) + '0');
}

void printstring(char *s) 
{ 
	for (; *s != '\0'; s++) 
		_putchar(*s); 
} 
void printhex(int i) 
{
	_putchar(i);
}
