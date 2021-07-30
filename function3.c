#include "holberton.h"

/**
 * print_unsigned - prints unsigned integer character.
 * @arg_list: arguments list
 *
 * Return: number
 */

int print_unsigned(va_list arg_list)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(arg_list, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
	;
	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}
	return (i + 1);
}



/**
 * print_octal - prints a hexadecimal characters.
 * @arg_list: list that contains the hexadecimal
 *
 * Return: total printed number.
 */
int print_octal(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	unsigned int copia;
	char *octa;
	int i, s = 0, print_count = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copia = num; copia != 0; s++)
	{
		copia = copia / 8;
	}
	octa = malloc(s);
	if (!octa)
		return (-1);
	for (i = s - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}
	for (i = 0; i < s && octa[i] == '0'; i++)
		;
	for (; i < s; i++)
	{
		_putchar(octa[i]);
		print_count++;
	}
	free(octa);
	return (print_count);
}

/**
 * print_binary - prints the binary characters.
 * @arg_list: argument list
 *
 * Return: number of charachters printed
 */


int print_binary(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	int print_count = 0, size = 0;
	int tmp, j, i = 0;
	char *str;

	tmp = num;
	while (tmp > 0)
	{
		size++;
		tmp /= 2;
	}
	if (num == 0)
	{
		_putchar('0');
		print_count++;
	}
	str = malloc(sizeof(char) * size);

	if (str == NULL)
		return (-1);

	while (num > 0)
	{
		str[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print_count++;
		_putchar(str[j]);
	}

	free(str);

	return (print_count);
}
