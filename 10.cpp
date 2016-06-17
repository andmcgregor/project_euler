#include <stdio.h>
#include <inttypes.h>

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

int64_t prime_sum(int upto)
{
  int64_t sum = 0;

  for (int i = 1; i < upto; i++)
    if (is_prime(i))
      sum += i;

  return sum;
}

int main(int argc, char** argv)
{
  printf("%" PRId64 "\n", prime_sum(2000000));

  return 0;
}

