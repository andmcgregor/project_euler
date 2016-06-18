#include <stdio.h>
#include <vector>

std::vector<int> ones = {
  0, // (empty)
  3, // one
  3, // two
  5, // three
  4, // four
  4, // five
  3, // six
  5, // seven
  5, // eight
  4, // nine
};

std::vector<int> teens = {
  3, // ten
  6, // eleven
  6, // twelve
  8, // thirteen
  8, // fourteen
  7, // fifteen
  7, // sixteen
  9, // seventeen
  8, // eighteen
  8, // nineteen
};

std::vector<int> tens = {
  0, // (empty)
  0, // NOT USED (teens)
  6, // twenty
  6, // thirty
  5, // forty
  5, // fifty
  5, // sixty
  7, // seventy
  6, // eighty
  6, // ninety
};

std::vector<int> units = {
  0, // (empty)
  0, // one
  0, // ten
  7, // hundred
  8, // thousand
};

int word_count(int num)
{
  std::vector<int> numbers;
  int sum = 0;

  while (num != 0) {
    numbers.insert(numbers.begin(), num % 10);
    num /= 10;
  }

  int upto = 1;
  while (numbers.size() > 0) {
    int beforeSum = sum;
    switch (upto)
    {
      case 1: // ones
        if (numbers.size() > 1 && numbers[numbers.size() - 2] == 1) {
          sum += teens[numbers.back()];
          numbers.pop_back();
          upto++;
        } else {
          sum += ones[numbers.back()];
        }
        break;
      case 2: // tens
        sum += tens[numbers.back()];
        break;
      case 3: // hundreds
        if (sum != 0) sum += 3; // "and"

        sum += ones[numbers.back()];
        break;
      case 4: // thousands
        sum += ones[numbers.back()];
        break;
    }

    if (sum != 0) sum += units[upto];
    numbers.pop_back();
    upto++;
  }

  return sum;
}

int main(int argc, char** argv)
{
  int sum = 0;

  for (int i = 1; i <= 1000; i++)
    sum += word_count(i);

  printf("%i\n", sum);

  return 0;
}

