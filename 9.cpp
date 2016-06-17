#include <stdio.h>

int pythagorean_product(int sum)
{
  for (int ax = sum; ax > 0; ax--) {
    for (int bx = sum; bx > 0; bx--) {
      for (int cx = sum; cx > 0; cx--) {
        if (ax + bx + cx == sum &&
            ax * ax + bx * bx == cx * cx)
          return ax * bx * cx;
      }
    }
  }

  return -1;
}

int main(int argc, char** argv)
{
  printf("%i\n", pythagorean_product(1000));

  return 0;
}

