#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  fp = fopen("numbers.dat", "rt");
  int num, sum = 0;

  if (fp == NULL)
  {
    printf("\nError while opening the numbers.dat file");
    exit(1);
  }

  while (!feof(fp))
  {
    fscanf(fp, "%d", &num);
    sum += num;
  }

  fclose(fp);

  fp = fopen("numbers.dat", "at");

  if (fp == NULL)
  {
    printf("\nError while opening the numbers.dat file");
    exit(1);
  }

  fprintf(fp, "\n%d", sum);

  fclose(fp);

  return 0;
}