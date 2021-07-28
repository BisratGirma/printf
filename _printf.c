#include "holberton.h"
#include <stdarg.h>

void printint(int i);
void printstring(char s);
void printhex(int i);

/**
 * _printf - prints characters.
 * @str: strings.
 */ 

int _printf(char *p, ...)
{
	char *p; 
	va_list argp; 
	int i; 
	char *s; 
	char fmtbuf[256]; 
	va_start(argp, fmt); 

	for(p + fmt; *p != '\0'; p++) 
	{ 
		if(*p != '%') 
		{ 
			putchar(*p); 
			continue; 
		} 
		switch(*++p) 
		{ 
			case 'c': 
				i = va_arg(argp, int); 
				_putchar(i); 
				break; 
			case 'd': 
				i = va_arg(argp, int); 
				printint(i); 
				break; 
			case 's': 
				s = va_arg(argp, char *); 
				printstring(s); 
				break; 
			case 'x': 
				i = va_arg(argp, int); 
				printhex(i); 
				break; 
			case '%': 
				_putchar('%'); 
				break; 
		} 
	} 
	va_end(argp);

	
	return (count);
}
void printint(int i) 
{ 
	int digit; 
	digit = i % 10; 
	digit = digit + '0'; 
	i = i / 10; 
	_putchar(i); 
}

void printstring(char s) 
{ 
	_putchar(s); 
} 
void printhex(int i) 
{
 	_puts(i);
}
