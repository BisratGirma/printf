#ifndef functions_c
#define functions_c
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* _puts - holbertons puts
* @str: string that gets passed to the _puts function
*Description: prints a char
*Return:
*/
void _puts(char *str)
{
int i = 0, j;
while (str[i])
{
i++;
}
for (j = 0; j < i; j++)
{
_putchar(str[j]);
}
}

/**
* _strlen - strlen alternative representation
* @s: the char array or string
*Description: strlen alt
*Return: the length of the string
*/

int _strlen(const char *s)
{
int i = 0;
while (s[i])
{
i++;
}
return (i);
}
/**
* _strcpy - string copier...more like assigner
* @dest: target
* @src: source
*Description:
*Return: string
*/
char *_strcpy(char *dest, const char *src)
{
int i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
/**
* print_number - prints numbers
* @n: integer to be printed
*Description:
*Return: nothing
*/
void print_number(int n)
{
int copy, nth, size = 1, ones = n % 10;

n /= 10;
copy = n;
if (n < 0)
{
ones *= -1, copy *= -1, n *= -1;
_putchar('-');
}
if (copy > 0)
{
while (copy / 10 != 0)
{
copy /= 10, size *= 10;
}
while (size > 0)
{
nth = n / size;
_putchar('0' + nth);
n = n - (nth *size);
size /= 10;
}
}
_putchar('0' + ones);
}
/**
 * printunsigned - prints unsinged int
 * @i: the unsigned integer.
 */
void print_unsigned(unsigned int n)
{
if(n)
{
unsigned int copy, nth, size = 1, ones = n % 10;
n /= 10;
copy = n;
while (copy / 10 != 0)
{
copy /= 10, size *= 10;
}
while (size > 0)
{
nth = n / size;
_putchar('0' + nth);
n = n - (nth *size);
size /= 10;
}
_putchar('0' + ones);
}
}

#endif