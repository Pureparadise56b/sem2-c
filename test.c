// #include<stdio.h>

// int a = 10; // global (extern) variable

// void print_gl_var(void){
//   printf("\nGlobal 'a' - %d", a);
//   return;
// }

// int main(){
//   int a = 100; // local (automatic | auto) variable
//   printf("%d", a);

//   extern int a; // refers to the global variable 'a'
//   a = 400; // change the value of global variable
//   print_gl_var();
//   return 0;
// }

#include<stdio.h>

int a = 10;

void increment(void){
  static int num = 0;
  printf("%d\n", ++num);
}

int main(){
  for(int i = 1; i <= 5; i++) increment();
  return 0;
}
