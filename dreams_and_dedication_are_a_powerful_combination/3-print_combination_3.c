#include "my_functions.h"

void print_combination_3(void)
{
  int n, i, k;
  for (n = 0; n <= 9; n++)
    {
      for (i = n + 1; i <= 9; i++)
	{
	  for (k = i + 1; k <=9; k++)
	    {
	      print_char((n + 48));
	      print_char((i + 48));
	      print_char((k + 48));
	      if (n < 7) 
		{
		  print_char(',');
		  print_char(' ');
		}
	    }
	}
    }
}
