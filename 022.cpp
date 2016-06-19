#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "lib/big_num.h"

std::vector<std::string> names;

int partition(int low, int high)
{
  std::string pivot = names[high];
  int i = low;

  for (int j = low; j < high; j++) {
    if (names[j] <= pivot) {
      std::swap(names[i], names[j]);
      i++;
    }
  }

  std::swap(names[i], names[high]);

  return i;
}

void sort_names(int low, int high)
{
  if (low < high) {
    int i = partition(low, high);
    sort_names(low, i - 1);
    sort_names(i + 1, high);
  }
}

int get_score(std::string name)
{
  int score = 0;

  for (char& c : name)
    score += ((int) c) - 64;

  return score;
}

int main(int argc, char** argv)
{
  BigNum* bignum = new BigNum;

  std::ifstream file("data/p022_names.txt");
  std::string line, name;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    while (std::getline(iss, name, ',')) {
      names.push_back(name.substr(1, name.length() - 2));
    }
  }

  sort_names(0, names.size() - 1);

  for (int i = 0; i < names.size(); i++)
    bignum->add((i + 1) * get_score(names[i]));

  bignum->print();

  return 0;
}

