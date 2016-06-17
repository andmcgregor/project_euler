#include <stdio.h>

int prime(int num)
{
  int upto_prime = 0,
      counter = 1;

  while (counter < num) {
    upto_prime++;

    for (int i = 2; i < upto_prime; i++) {
      if (upto_prime % i == 0)
        break;

      if (i == upto_prime - 1)
        counter++;
    }
  }

  return upto_prime;
}

int main(int argc, char** argv)
{
  printf("%i\n", prime(10001));

  return 0;
}

