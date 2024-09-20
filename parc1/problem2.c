#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

void printContentInReverse(char ch)
{
  char next_char;
  if (ch == EOF)
    return;
  next_char = fgetc(fp);
  printContentInReverse(next_char);
  printf("%c", ch);
}

int main()
{
  char ch;

  fp = fopen("content.dat", "rt");

  if (fp == NULL)
  {
    printf("\nError while opening content.dat file");
    exit(1);
  }

  ch = fgetc(fp);

  printContentInReverse(ch);

  fclose(fp);

  return 0;
}