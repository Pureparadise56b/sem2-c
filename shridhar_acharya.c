#include <stdio.h>
#include <math.h>

void solveQuadratic(double a, double b, double c)
{
  double discriminant, root1, root2;

  // Calculate the discriminant
  discriminant = b * b - 4 * a * c;

  // Check if the discriminant is positive, zero or negative
  if (discriminant > 0)
  {
    // Two distinct real roots
    root1 = (-b + sqrt(discriminant)) / (2 * a);
    root2 = (-b - sqrt(discriminant)) / (2 * a);
    printf("Root 1 = %.2lf\n", root1);
    printf("Root 2 = %.2lf\n", root2);
  }
  else if (discriminant == 0)
  {
    // One real root (both roots are the same)
    root1 = root2 = -b / (2 * a);
    printf("Root = %.2lf\n", root1);
  }
  else
  {
    // Complex roots
    double realPart = -b / (2 * a);
    double imaginaryPart = sqrt(-discriminant) / (2 * a);
    printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
    printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
  }

  return;
}

int main()
{
  double a, b, c;

  // Input coefficients a, b and c
  printf("Enter coefficients a, b and c: ");
  if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    return 1;

  // Solve the quadratic equation
  solveQuadratic(a, b, c);

  return 0;
}
