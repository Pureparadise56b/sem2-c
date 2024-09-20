#include <stdio.h>

int main()
{
  int n;
  float result = 1;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (int i = 2; i <= n; i++)
  {
    if ((i % 2) == 0)
    {
      result -= (float)1 / i;
    }
    else
    {
      result += (float)1 / i;
    }
  }

  printf("result: %.3f", result);

  return 0;
}