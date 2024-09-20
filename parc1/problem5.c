#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year)
{
  if ((year % 100 == 0) && (year % 400 == 0))
    return 1;
  else if (year % 4 == 0)
    return 1;
  else
    return 0;
}

int main()
{
  int day, month, year;

  printf("\nEnter the date (dd/mm/yyyy): ");
  scanf("%d/%d/%d", &day, &month, &year);

  if (month > 12)
  {
    printf("\nMonth is invalid!!");
    exit(1);
  }

  if ((isLeapYear(year) && month == 2 && day > 29) || (!isLeapYear(year) && month == 2 && day > 28))
  {
    printf("\nDay is invalid!!");
    exit(1);
  }

  if (month != 2 && day > 31)
  {
    printf("\nDay is invalid!!");
    exit(1);
  }

  return 0;
}