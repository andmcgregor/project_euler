#include <stdio.h>
#include <math.h>

int triangle_number_by_divisors(int num)
{
  int divisors = 0,
      upto = 0,
      sum = 0;

  while (divisors <= num) {
    divisors = 0;
    upto++;
    sum += upto;

    for (int i = 1; i < sqrt(sum); i++)
      if (sum % i == 0)
        divisors++;

    // 1..sqrt(sum) holds half number of divisors
    divisors *= 2;
  }

  return sum;
}

int main(int argc,char** argv)
{
  printf("%i\n", triangle_number_by_divisors(500));

  return 0;
}

