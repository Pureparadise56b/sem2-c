#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
  char input[50];
  int i_number;
  char *endptr;

  do
  {
    printf("\nEnter a number: ");
    // scanf("%d", &i_number);
    fgets(input, sizeof(input), stdin);

    i_number = strtol(input, &endptr, 10);

    if ((*endptr == '\n' || *endptr == '\0'))
    {
      if (i_number < 0)
      {
        printf("Number cannot be a negetive number!!\n");
      }
      else if (i_number == 0)
      {
        printf("Number must be a non-zero value!!\n");
      }
    }
    else
    {
      printf("Invalid number type, only integer value is accepted!!\n");
    }

  } while (!(*endptr == '\n' || *endptr == '\0') || i_number <= 0);

  ((i_number & (i_number - 1)) == 0) ? printf("\nEntered number is a power of two.\n") : printf("\nEntered number is not a power of two.\n");

  return 0;
}