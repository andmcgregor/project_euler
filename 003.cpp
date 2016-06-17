#include <stdio.h>
#include <inttypes.h>

int64_t largest_prime_factor(int64_t n)
{
  int64_t current = 2;

  while (n > current) {
    if (n % current == 0) {
      n /= current;
      current = 2;
    } else {
      current++;
    }
  }

  return current;
}

int main(int argc, char** argv)
{
  printf("%" PRId64 "\n", largest_prime_factor(600851475143));

  return 0;
}

