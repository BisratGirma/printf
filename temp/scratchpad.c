
#include "../_putchar.c"
void print_binary(int n)
{
  int c, k;
  for (c = 31; c >= 0; c--)
  {
    k = n >> c;

    if (k & 1)
      _putchar('1');
    else
      _putchar('0');
  }

  _putchar('\n');

}