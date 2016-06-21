#include <stdio.h>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
  std::vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  int target = 1000000,
      current = 0;

  std::sort(digits.begin(), digits.end());

  do {
    current++;

    if (current == target) {
      for (int i = 0; i < digits.size(); i++)
        printf("%i", digits[i]);
      printf("\n");
      break;
    }
  } while (std::next_permutation(digits.begin(), digits.end()));

  return 0;
}

