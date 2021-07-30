#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h> 
#include "holberton.h"
#include "functions.c"
int _printf(const char *format, ...)
{
int len = _strlen(format);
char *fmt = (char *) malloc(sizeof(char) * len);
_strcpy(fmt, format);
int i;
va_list items;
va_start(items, format);

if (fmt != NULL)
{
for (i = 0; i < len; i++)
{
if (fmt[i] != '\\' && fmt[i] == '%')
{
i++;
switch (fmt[i])
{
case 'c':
_putchar(va_arg(items, int));
break;
case 's':
_puts(va_arg(items, char *));
break;
case 'd':
print_number(va_arg(items, int));
break;
case 'i':
print_number(va_arg(items, int));
break;
}
}
else if (fmt[i] == '\\')
{
i++;
switch (fmt[i])
{
case 't':
_putchar(9);
break;
case 'n':
_putchar(10);
break;
}
}
else
{
_putchar(fmt[i]);
}
}
}
return (0);
}