#include <stdio.h>
#include <cmath>
#include <math.h>
#include <inttypes.h>
#include <vector>
#include <algorithm>

int64_t sum_of_divisors(int64_t num)
{
  int64_t result = 0;

  for (int64_t i = 1; i <= num; i++)
    if (num % i == 0)
      result += i;

  return result;
}

int64_t sum_of_divisors_upto(int64_t upto, int64_t divisor)
{
  int64_t sum = 0,
          current_divisors;

  std::vector<int64_t> divisible;

  // find lowest divisible sum of divisors
  for (int64_t i = 1; i < upto; i++) {
    current_divisors = sum_of_divisors(i);

    if (current_divisors % divisor == 0) {
      sum += current_divisors;
      divisible.push_back(i);
      break;
    }
  }

  //printf("found lowest divisor: %" PRId64 "\n", divisible[0]);

  for (int64_t i = divisible[0] * 2; i < upto; i++) {
    for (int64_t j = 0; j < divisible.size(); j++) {
      if (i % divisible[j] == 0 || (i - 1) % divisible[j] == 0) {
      //if (i % divisible[j] == 0) {
      //if (true) {
        current_divisors = sum_of_divisors(i);

        if (current_divisors % divisor == 0) {
          sum += current_divisors;
          //printf("%" PRId64 "\n", i);
          divisible.push_back(i);
        }
        break;
      }
    }
  }

  return sum;
}

int main(int argc, char** argv)
{
  //printf("test case 0: 49 == %" PRId64 "\n", sum_of_divisors_upto(20, 7));
  //printf("test case 0: 189 == %" PRId64 "\n", sum_of_divisors_upto(30, 7));
  //printf("test case 0: 1001 == %" PRId64 "\n", sum_of_divisors_upto(70, 7));

  //printf("test case 1: 150850429 == %" PRId64 "\n", sum_of_divisors_upto(pow(10, 6), 2017));
  //printf("test case 2: 249652238344557 == %" PRId64 "\n", sum_of_divisors_upto(pow(10, 9), 2017));

  //printf("%" PRId64 "\n", sum_of_divisors_upto(pow(10, 11), 2017));

  return 0;
}

