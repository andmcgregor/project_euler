#include <stdio.h>
#include <set>
#include <cmath>

int main(int argc, char** argv)
{
  std::set<double> values;

  for (int a = 2; a <= 100; a++)
    for (int b = 2; b <= 100; b++)
      values.insert(pow(a, b));

  printf("%i\n", values.size());

  return 0;
}

