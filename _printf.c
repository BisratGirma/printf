#include "holberton.h"
#include <stdarg.h>

void printint(int i);
void printstring(char s);
void printhex(int i);

/**
 * _printf - prints characters.
 * @str: strings.
 */ 

int _printf(char *format, ...)
{
	va_list argument; 
	int i = 0; 
	/* char *s; 
	char fmtbuf[256];  
	va_start(argument, format); */ 

	for(; *format != '\0'; format++) 
	{ 
		if(*format != '%') 
		{ 
			_putchar(format);
		       i++;	
			continue; 
		} 
	/*	switch(*++p) 
		{ 
			case 'c': 
				i = va_arg(argument, char); 
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
				break; */
	//	} 
	} 
	//va_end(argument);

	
	return (i);
}
/*
void printint(int i) 
{ 
	
}

void printstring(char s) 
{ 
	_putchar(s); 
} 
void printhex(int i) 
{
 	_puts(i);
}
*/
