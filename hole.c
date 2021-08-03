#include "holberton.h"
#include <stdarg.h>


/**
 * fs_looper - parser helper becuasebetty can't allow more than 40 lines
 * >:(
 * @format: format
 * @formatt: pointer to original format
 * @arg_list: arg list
 * @format_list: format_list struct  array
 * Return: print count
 */

int finalstage(const char *format, const char **formatt, va_list arg_list,
specy format_list[])
{
	int print_count = 0, s = 0, list_len = 12;

	while (s < list_len)
	{
		if (*(format + 1) == " "[0])
		{
			format++;
			(*formatt)++;
			s = 0;
			continue;
		}
		if (*(format + 1) == (format_list + s)->specifier[0])
		{
			print_count += (format_list + s)->printer(arg_list);
			format++;
			break;
		}
		s++;
	}
	if (s == list_len)
	{
		if (*(format + 1) > 96 && *(format + 1) < 123 &&
			*(format + 1) != 'r')
		return (-1);

		_putchar(*format);
		_putchar(*(format + 1));
		format++;
		formatt++;
		return (2);

	}

	return (print_count);
}

/**
 * format_looper - parser helper becuasebetty can't allow more than 40 lines
 * >:(
 * @format: format
 * @arg_list: arg list
 * @format_list: format_list struct  array
 * Return: print count
 */

int loophole(const char *format, va_list arg_list, specy format_list[])
{
	int print_count = 0;

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
			{
				return (-1);
			}
			if (*(format + 1) == '%')
			{
				_putchar('%');
				format++;
				print_count++;
			} else
			{
				print_count += finalstage(format, &format, arg_list, format_list);
				format++;
			}
		} else
		{
			_putchar(*format);
			print_count++;
		}
	}
	return (print_count);
}


/**
 * hole - passes format lists
 *
 * @format: format string
 * @arg_list: arguments list
 * Return: number of characters printed
 */

int hole(const char *format, va_list arg_list)
{
	specy format_list[] = {
	{"c", print_char},
	{"s", print_string},
	{"d", print_decimal},
	{"i", print_decimal},
	{"x", print_hex},
	{"X", print_HEX},
	{"o", print_octal},
	{"u", print_unsigned},
	{"b", print_binary},
	{"S", print_STR},
	{"p", print_hex},
	{"R", print_R}
	};

	return (loophole(format, arg_list, format_list));
}
