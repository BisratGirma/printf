#include "holberton.h"

/**
 * print_char - prints characters
 *
 * @arg_list: arguments list
 *
 * Return: number of characters printed
 */

int print_char(va_list arg_list)
{
	int c = va_arg(arg_list, int);

	_putchar(c);

	return (1);
}




/**
 * print_string - prints strings
 *
 * @arg_list: arguments list
 *
 * Return: number of characters printed
 */

int print_string(va_list arg_list)
{
	char *string;
	int print_count;

	string = va_arg(arg_list, char *);

	if (string == NULL)
	{
		string = "(null)";
	}

	for (print_count = 0; string[print_count] != '\0'; print_count++)
		_putchar(string[print_count]);

	return (print_count);
}


/**
 * print_decimal - prints decimal numbers
 *
 * @arg_list: arguments list
 *
 * Return: number of characters printed
 */

int print_decimal(va_list arg_list)
{
	long int d = va_arg(arg_list, int), mult = 1, dc, print_count = 0;

	if (d < 0)
	{
		d = -d;
		_putchar('-');
		print_count++;
	}

	dc = d;
	if (d < 10 && d >= 0)
	{
		_putchar(d + '0');
		print_count++;
	}
	else
	{
		while (dc > 9)
		{
			mult *= 10;
			dc /= 10;
		}
		while (mult > 0)
		{
			_putchar((d / mult) + '0');
			print_count++;
			d -= (d / mult) * mult;
			mult /= 10;
		}
	}

	return (print_count);
}


/**
 * print_hex - prints hex numbers
 *
 * @arg_list: arguments list
 *
 * Return: number of characters printed
 */

int print_hex(va_list arg_list)
{
	unsigned int num = va_arg(arg_list, unsigned int);
	unsigned int num2;
	int i, i2, copy, contame = 0;
	char *numhex;

	if (num == 0)
		return (_putchar('0'));
	for (num2 = num; num2 != 0; contame++)
	{
		num2 = num2 / 16;
	}
	numhex = malloc(contame);
	for (i = 0; num != 0; i++)
	{
		copy = num % 16;
		if (copy < 10)
			numhex[i] = copy + '0';
		else
			numhex[i] = copy - 10  + 'a';
		num = num / 16;
	}
	for (i2 = i - 1; i2 >= 0; i2--)
		_putchar(numhex[i2]);
	free(numhex);
	return (contame);
}


/**
 * inttostr - convert numbers to string
 *
 * @number: number to convert
 *
 * Return: the string containing the number
 */

char *inttostr(int number)
{
	int i, nlen = intlen(number), rem;
	char *str = malloc(sizeof(char) * nlen + 1);

	for (i = 0; i < nlen; i++)
	{
		rem = number % 10;
		number = number / 10;
		str[nlen - (i + 1)] = rem + '0';
	}
	str[nlen] = '\0';
	return (str);
}
