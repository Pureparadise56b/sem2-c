#include<stdio.h>

int main(){
  int num, i;
  long int fact = 1;

  printf("Enter a number: ");
  scanf("%d", &num);

  for(i = 1; i <= num; i++){
    fact *= i;
  }

  printf("factorial is %d", fact);

  return 0;
}