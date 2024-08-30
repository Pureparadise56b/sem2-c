#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int stringToInteger(char *);

int main()
{
  char number1[] = "30abc";
  char number2[] = "20";
  printf("%d", stringToInteger(number1) + stringToInteger(number2));
  return 0;
}

int stringToInteger(char *str)
{
  int result = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {

    if (str[i] < '0' || str[i] > '9')
    {
      perror("Value is out of range!");
      exit(1);
    }

    result = ((result * 10) + (str[i] - '0'));
  }

  return result;
}