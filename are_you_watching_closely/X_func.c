#include "printf_header.h"

int X_func(va_list ap)
{
  long int decimal, rem;
  int i, j, ret;
  char hexadec[100];

  i = 1;
  decimal = va_arg(ap, unsigned int);
  /* convert decimal to hex char and put it in array */
  while (decimal != 0) {
    rem = decimal % 16;
    /*convert int to character */
    if (rem < 10) {
      rem += 48;
    } else {
      rem += 55;
    }
    hexadec[i++] = rem;
    decimal = decimal / 16;
  }
  /* ret needs to be length of array */
  j = i - 1;
  ret = j;
  while (j > 0) {
    print_char(hexadec[j]);
    j--;
  }
  return (ret);
}
