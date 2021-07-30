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
			case 's': 
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
 * printocta - prints octa numbers.
 * @num: an integer number to be converted.
 *
 * Return: the number of characters printed.
 */
int printocta(unsigned int num)
{
	unsigned int copy;
	char *octa;
	int i, s = 0, print_count = 0;

	if (num == 0)
		return (_putchar('0'));

	for (copy = num; copy != 0; s++)
	{
		copy = copy / 8;
	}

	octa = malloc(s);

	if (!octa)
		return (-1);

	for (i = s - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}
	
	for (; i < s; i++)
	{
		_putchar(octa[i]);
		print_count++;
	}
	free(octa);
	return (print_count);
}
/**
 * printhex - prints hex number
 * @i: the number to be hexed
 */
int printhex(int unsigned num) 
{
	unsigned int copy;
	int i, j, repl, count = 0;
	char *hex;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; count++)
	{
		copy = copy / 16;
	}
	hex = malloc(count);
	for (i = 0; num != 0; i++)
	{
		repl = num % 16;
		if (repl < 10)
			hex[i] = repl + '0';
		else
			hex[i] = repl - 10 + 'A';
		num = num / 16;
	}
	for (j = i - 1; j >= 0; j--)
		_putchar(hex[j]);
	free(hex);
	return (count);
}
