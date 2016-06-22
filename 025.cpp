#include <stdio.h>
#include "lib/big_num.h"

int main(int argc, char** argv)
{
  int count = 2,
      targetSize = 1000;;

  BigNum *a = new BigNum(1),
         *b = new BigNum(1);

  while (b->size() < targetSize) {
    if (count % 2 == 0)
      a->add(b);
    else
      b->add(a);
    count++;
  };

  return 0;
}

