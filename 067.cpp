#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

int maximum_path(std::vector<std::vector<int>> triangle)
{
  for (int y = triangle.size() - 2; y >= 0; y--)
    for (int x = 0; x < triangle[y].size(); x++)
      triangle[y][x] += std::max(triangle[y + 1][x], triangle[y + 1][x + 1]);

  return triangle[0][0];
}

int main(int argc, char** argv)
{
  std::vector<std::vector<int>> triangle;

  std::ifstream file("data/p067_triangle.txt");
  std::string line, num;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    triangle.push_back({});

    while (getline(iss, num, ' '))
      triangle.back().push_back(std::stoi(num));
  }

  printf("%i\n", maximum_path(triangle));

  return 0;
}

