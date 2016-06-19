#include <stdio.h>
#include <vector>

int factorial_sum(int num)
{
  std::vector<int> bignum = { num };
  int sum = 0,
      remainder = 0;

  for (int i = num - 1; i > 0; i--) {
    for (int j = bignum.size() - 1; j >= 0; j--) {
      bignum[j] *= i;
      bignum[j] += remainder;

      remainder = bignum[j] / 10;
      bignum[j] = bignum[j] % 10;
    }

    while (remainder != 0) {
      bignum.insert(bignum.begin(), remainder % 10);
      remainder /= 10;
    }
  }

  for (int i = 0; i < bignum.size(); i++)
    sum += bignum[i];

  return sum;
}

int main(int argc, char** argv)
{
  printf("%i\n", factorial_sum(100));

  return 0;
}

