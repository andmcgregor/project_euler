#include <stdio.h>

int fib(int i)
{
  if (i < 2) return i;

  return fib(i - 1) + fib(i - 2);
}

int main(int argc, char** argv)
{
  int upto = 1,
      last = 0,
      max = 4000000,
      sum = 0;


  while (last < max) {
    last = fib(upto);

    if (last % 2 == 0)
      sum += last;

    upto++;
  }

  printf("%i\n", sum);

  return 0;
}

