#include <stdio.h>
#include <vector>

int power_digit_sum(int base, int product)
{
  std::vector<int> bignum = { base };
  int remainder = 0,
      sum = 0;

  for (int iter = 1; iter < product; iter++) {
    for (int i = bignum.size() - 1; i >= 0; i--) {
      bignum[i] *= base;
      bignum[i] += remainder;

      remainder = bignum[i] / 10;
      bignum[i] = bignum[i] % 10;
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
  printf("%i\n", power_digit_sum(2, 1000));

  return 0;
}

