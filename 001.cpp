#include <stdio.h>

int sum_of_natural_numbers(int upto)
{
  int sum = 0;

  for (int i = 0; i < upto; i++)
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;

  return sum;
}

int main(int argc, char** argv)
{
  printf("%i\n", sum_of_natural_numbers(1000));
  return 0;
}

