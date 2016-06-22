#include <stdio.h>
#include <vector>

int main(int argc, char** argv)
{
  int max_length = 0,
      max_d,
      upto = 1000;

  for (int d = 1; d < upto; d++) {
    std::vector<int> digits;
    digits.resize(d);

    int value = 1,
        i = 0;

    while (digits[value] == 0 && value != 0) {
      digits[value] = i;
      value = value * 10 % d;
      i++;
    }

    if (i - digits[value] > max_length)
      max_length = i - digits[value],
      max_d = d;
  }

  printf("%i\n", max_d);

  return 0;
}

