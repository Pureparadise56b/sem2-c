#include <stdio.h>

int main()
{
  int integer_value;
  float decimal_value;
  double double_value;
  char character_value;

  short int short_integer;
  long int long_integer;
  unsigned int unsigned_integer;
  signed int signed_integer;

  printf("\nSize of integer is %d bytes\n", sizeof integer_value);
  printf("Size of float is %d bytes\n", sizeof decimal_value);
  printf("Size of double is %d bytes\n", sizeof double_value);
  printf("Size of char is %d byte\n", sizeof character_value);

  printf("\nSize of short int is %d bytes\n", sizeof short_integer);
  printf("Size of long int is %d bytes\n", sizeof long_integer);
  printf("Size of unsigned int is %d bytes\n", sizeof unsigned_integer);
  printf("Size of signed int is %d bytes\n", sizeof signed_integer);

  return 0;
}