#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return 1;
  return 0;
}

// Function to check if a given date is valid
int isValidDate(int day, int month, int year)
{
  // Check year range
  if (year < 1 || year > 9999)
    return 0;

  // Check month range
  if (month < 1 || month > 12)
    return 0;

  // Days in months
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Update February days in leap year
  if (isLeapYear(year))
    daysInMonth[2] = 29;

  // Check day range
  if (day < 1 || day > daysInMonth[month])
    return 0;

  return 1;
}

// Function to print the next date
void printNextDate(int day, int month, int year)
{
  // Days in months
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Update February days in leap year
  if (isLeapYear(year))
    daysInMonth[2] = 29;

  day++; // Increment the day

  // Handle overflow of days in the month
  if (day > daysInMonth[month])
  {
    day = 1; // Reset day to 1
    month++; // Increment month
  }

  // Handle overflow of months in the year
  if (month > 12)
  {
    month = 1; // Reset month to January
    year++;    // Increment year
  }

  printf("Next date: %02d/%02d/%04d\n", day, month, year);
}

int main()
{
  int day, month, year;

  // Input the date
  printf("Enter date in dd/mm/yyyy format: ");
  if (scanf("%d/%d/%d", &day, &month, &year) != 3)
  {
    printf("Invalid input format!\n");
    return 1;
  }

  // Check if the date is valid
  if (!isValidDate(day, month, year))
  {
    printf("Invalid date!\n");
    return 1;
  }

  // Print the next date
  printNextDate(day, month, year);

  return 0;
}
