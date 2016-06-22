#include <vector>

class BigNum {
  public:
    BigNum(int initial)
    {
      add(initial);
    };

    void add(int small_number)
    {
      int remainder = small_number;

      for (int i = num.size() - 1; i >= 0; i--) {
        num[i] += remainder;
        remainder = num[i] / 10;
        num[i] = num[i] % 10;
      }

      while (remainder != 0) {
        num.insert(num.begin(), remainder % 10);
        remainder /= 10;
      }
    };

    void add(BigNum* other)
    {
      int remainder = 0;

      for (int i = num.size() - 1, j = other->num.size() - 1; (i >= 0 || j >= 0) || remainder != 0; i--, j--) {
        if (i >= 0) {
          num[i] += remainder + (j >= 0 ? other->num[j] : 0);
          remainder = num[i] / 10;
          num[i] = num[i] % 10;
        } else if (j >= 0) {
          num.insert(num.begin(), (remainder % 10) + other->num[j]);
          remainder /= 10;
        } else {
          num.insert(num.begin(), remainder % 10);
          remainder /= 10;
        }
      }
    };

    void print(void)
    {
      for (int i = 0; i < num.size(); i++)
        printf("%i", num[i]);
      printf("\n");
    };

    int size(void)
    {
      return num.size();
    };

    std::vector<int> num = { 0 };
};

