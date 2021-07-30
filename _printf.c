#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"
#include "functions.c"

int _printf(const char *format, ...)
{
int len = _strlen(format), i;
char *fmt = (char *) malloc(sizeof(char) * len);
va_list items;
_strcpy(fmt, format);

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
case 'u':
print_unsigned(va_arg(items, unsigned int));
i++;
break;
case 'o':
print_unsigned(va_arg(items, unsigned int));
i++;
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