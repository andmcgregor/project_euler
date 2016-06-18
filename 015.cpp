#include <stdio.h>
#include <vector>
#include <inttypes.h>

/*
int64_t path_count(int x, int y)
{
  if (x == 0 && y == 0)
    return 1;
  else
    return (x > 0 ? path_count(x - 1, y) : 0) + (y > 0 ? path_count(x, y - 1) : 0);
}
*/

int64_t path_count(int size)
{
  std::vector<std::vector<int64_t>> grid;

  grid.resize(size + 1);
  for (int x = 0; x <= size; x++) {
    grid[x].resize(size + 1);

    for (int y = 0; y <= size; y++)
      if (x == size || y == size)
        grid[x][y] = 1;
  }

  for (int x = size - 1; x >= 0; x--)
    for (int y = size - 1; y >= 0; y--)
      grid[x][y] = grid[x + 1][y] + grid[x][y + 1];

  return grid[0][0];
}

int main(int argc, char** argv)
{
  printf("%" PRId64 "\n", path_count(20));

  return 0;
}

