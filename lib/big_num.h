class BigNum {
  public:
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

    void print(void)
    {
      for (int i = 0; i < num.size(); i++)
        printf("%i", num[i]);
      printf("\n");
    };

  private:
    std::vector<int> num = { 0 };
};

