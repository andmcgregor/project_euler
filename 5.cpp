#include <stdio.h>

int smallest_multiple(int min, int max)
{
  int upto = 1;

  while (true) {
    for (int i = min; i <= max; i++) {
      if (upto % i == 0) {
        if (i == max)
          return upto;
      } else {
        break;
      }
    }

    upto++;
  }
}

int main(int argc, char** argv)
{
  printf("%i\n", smallest_multiple(1, 20));

  return 0;
}

