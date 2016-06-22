#include <stdio.h>
#include <vector>
#include <cmath>

int main(int argc, char** argv)
{
  int size = 1001,
      diagonal_sum = 0,
      upto = size * size,
      upto_x = size,
      upto_y = 0,
      dir_x = -1,
      dir_y = 0;

  std::vector< std::vector<int> > spiral;

  spiral.resize(size);
  for (int x = 0; x < spiral.size(); x++) {
    spiral[x].resize(size);
    for (int y = 0; y < spiral.size(); y++)
      spiral[x][y] = 0;
  }

  // generate spiral
  while (true) {
    // choose direction
    if (upto_x + 1 < size && spiral[upto_x + 1][upto_y] == 0)      // right
      dir_x = 1, dir_y = 0;
    else if (upto_y - 1 >= 0 && spiral[upto_x][upto_y - 1] == 0)   // up
      dir_x = 0, dir_y = -1;
    else if (upto_x - 1 >= 0 && spiral[upto_x - 1][upto_y] == 0)   // left
      dir_x = -1, dir_y = 0;
    else if (upto_y + 1 < size && spiral[upto_x][upto_y + 1] == 0) // down
      dir_x = 0, dir_y = 1;
    else
      break;

    // continue in direction until reached array boudary or pre-existing value
    while (upto_x + dir_x >= 0 && upto_x + dir_x < size &&
           upto_y + dir_y >= 0 && upto_y + dir_y < size &&
           spiral[upto_x + dir_x][upto_y + dir_y] == 0) {
      upto_x += dir_x;
      upto_y += dir_y;
      spiral[upto_x][upto_y] = upto--;
    }
  };

  // calculate sum of diagonals
  for (int i = 0; i < spiral.size(); i++)
    diagonal_sum += spiral[i][i] + spiral[i][size - i - 1];

  // remove double-counted center
  diagonal_sum -= 1;

  printf("%i\n", diagonal_sum);

  return 0;
}

