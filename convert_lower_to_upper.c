#include <stdio.h>
#include <ctype.h>

#define EOL '\n'

int main()
{
  char sentence[100];
  int count = 0, flag;

  printf("\nEnter your sentence below 100 characters: ");
  while ((sentence[count] = getchar()) != EOL)
    ++count;

  flag = count;
  count = 0;

  while (count < flag)
  {
    putchar(toupper(sentence[count]));
    ++count;
  }

  return 0;
}