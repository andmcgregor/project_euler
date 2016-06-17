#include <stdio.h>
#include <vector>
#include <algorithm>

bool is_palindromic(int num)
{
  std::vector<int> original, reversed;

  while (num > 0) {
    reversed.push_back(num % 10);
    num /= 10;
  }

  original = reversed;
  std::reverse(original.begin(), original.end());

  for (int i = 0; i < original.size() / 2; i++)
    if (original[i] != reversed[i])
      return false;

  return true;
}

int main(int argc, char** argv)
{
  int a = 999,
      b = 999,
      largest = 0;

  while (a > 0) {
    while (b >= a) {
      if (is_palindromic(a * b)) {
        if (a * b > largest)
          largest = a * b;
        break;
      } else {
        b--;
      }
    }
    a--;
    b = 999;
  }

  printf("%i\n", largest);

  return 0;
}

