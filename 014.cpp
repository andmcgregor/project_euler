#include <stdio.h>

long int term_count(long int num)
{
  long int count = 1;

  while (num != 1) {
    count++;

    if (num % 2 == 0)
      num /= 2;
    else
      num = num * 3 + 1;
  }

  return count;
}

int main(int argc, char** argv)
{
  long int highest_start = 0,
           highest_count = 0,
           current_count = 0;

  for (long int i = 1; i < 1000000; i++) {
    current_count = term_count(i);

    if (current_count > highest_count) {
      highest_start = i;
      highest_count = current_count;
    }
  }

  printf("%i\n", highest_start);

  return 0;
}

