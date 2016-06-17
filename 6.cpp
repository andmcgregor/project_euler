#include <stdio.h>

int sum_square_difference(int num)
{
  int sum_of_squares = 0,
      square_of_sums = 0;

  for (int i = 1; i <= num; i++) {
    sum_of_squares += i * i;
    square_of_sums += i;
  }

  square_of_sums *= square_of_sums;

  return square_of_sums - sum_of_squares;
}

int main(int argc, char** argv)
{
  printf("%i\n", sum_square_difference(100));

  return 0;
}

