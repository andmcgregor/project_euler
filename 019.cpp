#include <stdio.h>

int main(int argc, char** argv)
{
  int day_of_week = 0,
      day_of_month = 0,
      month = 1,
      year = 1900,
      sundays = 0;

  while (year < 2001) {
    day_of_week++;
    if (day_of_week > 7)
      day_of_week = 1;

    day_of_month++;

    switch (month) {
      case 2: // February
        if (day_of_month > (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28)) {
          month++;
          day_of_month = 0;
        }
        break;
      case 9:  // September
      case 4:  // April
      case 6:  // June
      case 11: // November
        if (day_of_month > 30) {
          month++;
          day_of_month = 0;
        }
        break;
      default: // All the rest
        if (day_of_month > 31) {
          month++;
          day_of_month = 0;
        }
        break;
    };

    if (month > 12) {
      month = 1;
      year++;
    }

    if (year >= 1901 && day_of_month == 1 && day_of_week == 7)
      sundays++;
  };

  printf("%i\n", sundays);

  return 0;
}

