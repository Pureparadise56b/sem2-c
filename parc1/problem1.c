#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *firstFileFp, *secondFileFp, *outputFileFp;
  char ch;

  outputFileFp = fopen("result.dat", "wt");
  firstFileFp = fopen("first.dat", "rt");

  if (outputFileFp == NULL)
  {
    printf("Error while opening output file.");
    exit(1);
  }

  if (firstFileFp == NULL)
  {
    printf("Error while opening first file.");
    exit(1);
  }

  // while (!feof(firstFileFp))
  // {
  //   ch = fgetc(firstFileFp);
  //   fputc(ch, outputFileFp);
  // }

  while ((ch = fgetc(firstFileFp)) != EOF)
    fputc(ch, outputFileFp);

  fclose(firstFileFp);

  secondFileFp = fopen("second.dat", "rt");

  if (secondFileFp == NULL)
  {
    printf("Error while opening second file.");
    exit(1);
  }

  // while (!feof(secondFileFp))
  // {
  //   ch = fgetc(secondFileFp);
  //   fputc(ch, outputFileFp);
  // }

  while ((ch = fgetc(secondFileFp)) != EOF)
    fputc(ch, outputFileFp);

  fclose(secondFileFp);
  fclose(outputFileFp);

  return 0;
}