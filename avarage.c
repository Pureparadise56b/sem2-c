#include <stdio.h>
#include <ctype.h>

#define EOL '\n'

int main()
{

  char line[80];
  int count;

  printf("Enter your string: ");
  scanf("%[^\n]", line);

  for (count = 0; line[count] != '\0'; count++)
  {
    if ((line[count] > '0' && line[count] < '9') || (line[count] > 'A' && line[count] < 'Z') || (line[count] > 'a' && line[count] < 'z'))
      line[count] += 1;
    else if (line[count] == '9')
      line[count] = '0';
    else if (line[count] == 'Z')
      line[count] = 'A';
    else if (line[count] == 'z')
      line[count] = 'a';
    else
      line[count] = '.';
  }

  for (int i = 0; i < count; i++)
  {
    putchar(line[i]);
  }

  return 0;
}