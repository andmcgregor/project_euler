#include <stdio.h>
#include <cmath>

bool is_prime(int num)
{
  if (num <= 1)
    return false;
  if (num <= 3)
    return true;
  if (num % 2 == 0 || num % 3 == 0)
    return false;

  int i = 5;

  while (i * i <= num) {
    if (num % i == 0 || num % (i + 2) == 0)
      return false;

    i += 6;
  }

  return true;
}

int count_primes(int a, int b)
{
  int n = 0;

  while (is_prime(std::abs(n) * std::abs(n) + a * std::abs(n) + b))
    n++;

  return n;
}

int main(int argc, char** argv)
{
  int max_a, max_b, max_primes = 0;

  for (int a = -1000; a < 1000; a++) {
    for (int b = -1000; b < 1000; b++) {
      int primes = count_primes(a, b);

      if (primes > max_primes)
        max_a = a,
        max_b = b,
        max_primes = primes;
    }
  }

  printf("%i\n", max_a * max_b);

  return 0;
}

