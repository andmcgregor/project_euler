#include <stdio.h>
#include <vector>
#include <algorithm>

int sum_of_divisors(int num)
{
  int result = 0;

  for (int i = 1; i < num; i++)
    if (num % i == 0)
      result += i;

  return result;
}

int sum_of_amicable_numbers(int upto)
{
  std::vector<int> amicable;
  int sum_i, sum = 0;

  for (int i = 1; i < upto; i++) {
    sum_i = sum_of_divisors(i);

    if (i == sum_of_divisors(sum_i)) {
      if (std::find(amicable.begin(), amicable.end(), i) == amicable.end() &&
          std::find(amicable.begin(), amicable.end(), sum_i) == amicable.end() &&
          sum_i != i) {
        amicable.push_back(i);
        amicable.push_back(sum_i);
      }
    }
  }

  for (int i = 0; i < amicable.size(); i++)
    sum += amicable[i];

  return sum;
}

int main(int argc, char** argv)
{
  printf("%i\n", sum_of_amicable_numbers(10000));

  return 0;
}

