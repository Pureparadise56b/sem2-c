#include <stdio.h>
#include <stdlib.h>

char *reverseString(char *, int);
void checkPalindrom(char *, char *, int);

int main()
{
  char str[100], *rev_str;
  int length = 0;

  printf("\nEnter the string: ");
  scanf("%99s", str);

  while (str[length] != '\0')
    ++length;

  rev_str = reverseString(str, length);

  checkPalindrom(str, rev_str, length);

  return 0;
}

char *reverseString(char *str, int length)
{
  char *rev_str = (char *)malloc(length * sizeof(char));

  for (int i = length - 1; i >= 0; i--)
  {
    rev_str[(length - (i + 1))] = str[i];
  }

  rev_str[length] = '\0';

  return rev_str;
}

void checkPalindrom(char *str, char *rev_str, int lenght)
{
  int matched = 1;

  for (int i = 0; i < lenght; i++)
  {
    if (str[i] != rev_str[i])
    {
      matched = 0;
      break;
    }
  }

  if (!matched)
    printf("\nEnter string is not a palindrom");
  else
    printf("\nEntered string is a palindrom.");

  return;
}