/* Q. Develope a C Language program for basic calculator with +, -, *, %, and / operators using command line arguments. 
*/

// Command line arguments based program
// OS Shell prompt is called Command Line
// This a basic calculator using command line arguments.
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	int a,b,c;
	//Check the minimum number of arguments
	if(argc != 4){
		printf("\nInvalid number of arguments");
		exit(0);
	}

	if (argv[2][1] != '\0'){
		printf("\nInvalid operators");
		exit(0);
	} else {
		a = atoi(argv[1]);
		b = atoi(argv[3]);

		switch(argv[2][0]){
      case '+':
        c = a + b;
        break;
      case '-':
        c = a - b;
        break;
      case '*':
        c = a * b;
        break;
      case '%':
        c = a % b;
        break;
      case '/':
        c = a / b;
        break;
      default:
        printf("\nInvalid operators");
        exit(0);
		}
		printf("\n%d %c %d = %d", a, argv[2][0], b, c);
	}
  return 0;
}