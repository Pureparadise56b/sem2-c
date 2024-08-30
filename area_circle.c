#include <stdio.h>

#define PI 3.14

float process(float);

int main()
{
  int counter = 0;
  float redius[100], area[100];

  printf("Enter 0 for exit..\n");

  printf("Enter value for redius: ");
  scanf("%f", &redius[counter]);

  while (redius[counter])
  {

    if (redius[counter] < 0)
      area[counter] = 0;
    else
      area[counter] = process(redius[counter]);

    printf("Enter value for redius: ");
    scanf("%f", &redius[++counter]);
  }

  for (int i = 0; i < counter; i++)
  {
    printf("\nArea of %.2f is %.2f", redius[i], area[i]);
  }

  return 0;
}

float process(float redius)
{
  return PI * redius * redius;
}