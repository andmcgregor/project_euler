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

  bool check = true;

  // find lowest divisible sum of divisors
  for (int64_t i = 1; i < upto; i++) {
    /*
    printf("checking: %" PRId64 "\n", i);

    printf("divisible: \n");
    for (int x = 0; x < divisible.size(); x++)
      printf("%" PRId64 " ", divisible[x]);
    printf("\n");
    */

    if (divisible.size() != 0) {
      for (int64_t j = 0; j < divisible.size(); j++) {
        if (i % divisible[j] == 0) {
          check = true;
          break;
        }
      }
    } else {
      check = true;
    }

    current_divisors = sum_of_divisors(i);

    if (current_divisors % divisor == 0) {
      sum += current_divisors;
      divisible.push_back(i);
      divisible.push_back(i + 1);
      printf("%" PRId64 "\n", i);
    }

    check = false;
  }

  /*
  printf("---------\n");

  int64_t last_divisible_size = 0;

  while (last_divisible_size != divisible.size()) {
    last_divisible_size = divisible.size();

    for (int64_t i = 0; i < divisible.size(); i++) {
      int64_t to_check = divisible[i] + divisible[j];
      printf("%" PRId64 "\n", to_check);

      if (to_check < upto &&
          std::find(added.begin(), added.end(), to_check) == added.end()) {
        current_divisors = sum_of_divisors(to_check);

        if (current_divisors % divisor == 0) {
          divisible.push_back(to_check);
          sum += current_divisors;
          added.push_back(to_check);
        }
      }
    }
  }
  */

  return sum;
}

int main(int argc, char** argv)
{
  //printf("test case 0: 49 == %" PRId64 "\n", sum_of_divisors_upto(20, 7));
  printf("test case 0: 49 == %" PRId64 "\n", sum_of_divisors_upto(30, 7));
  //printf("test case x: 150850429 == %" PRId64 "\n", sum_of_divisors_upto(pow(10, 6), 2017));
  //printf("test case 1: 150850429 == %" PRId64 "\n", sum_of_divisors_upto(pow(10, 6), 2017));

  //printf("test case 2: 249652238344557 == %" PRId64 "\n", sum_of_divisors(pow(10, 9), 2017));

  //printf("%i\n", sum_of_divisors(pow(10, 11), 2017));

  return 0;
}

