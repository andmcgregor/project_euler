#include <stdio.h>
#include <cmath>

int main(int argc, char** argv)
{
  int i = 2,
      current = 0,
      last = 0,
      sum = 0,
      result = 0;

  while (i - last < 200000) {
    sum = 0,
    current = i;

    while (current != 0) {
      sum += pow(current % 10, 5);
      current /= 10;
    }

    if (sum == i)
      result += i;

    i++;
  }

  printf("%i\n", result);

  return 0;
}

