#include <stdio.h>
#include <vector>
#include <map>

bool is_abundant(int num)
{
  int sum = 0;

  for (int i = 1; i < num; i++) {
    if (num % i == 0) {
      sum += i;

      if (sum > num)
        return true;
    }
  }

  return false;
}

int main(int argc, char** argv)
{
  std::vector<int> abundant;
  std::map<int, bool> summable;
  int sum = 0;
  int upto = 28123;

  for (int i = 0; i <= upto; i++)
    summable[i] = false;

  for (int i = 1; i <= upto; i++)
    if (is_abundant(i))
      abundant.push_back(i);

  for (int a = 0; a < abundant.size(); a++)
    for (int b = a; b < abundant.size(); b++)
      if (abundant[a] + abundant[b] <= upto)
        summable[abundant[a] + abundant[b]] = true;

  for (std::map<int, bool>::iterator it = summable.begin(); it != summable.end(); it++)
    if (!it->second)
      sum += it->first;

  printf("%i\n", sum);

  return 0;
}

