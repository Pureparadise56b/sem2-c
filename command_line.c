/* Q. Write a program for the basic understanding of command line arguments. */

// Command line arguments based program
// OS Shell prompt is called Command Line
#include<stdio.h>

// Main has two arguments - generally named as
// int argc - number of command line arguments or argument count
// char *argv[] - array of command line arguments in string form
// argv[0] = program executable file name is the first argument
// this must be compulsary.
// Other arguments are optional and these are
// argv[1], argv[2], ...
// these are all array of characters or string terminated by EOS (\0)
int main(int argc,char *argv[]){
	int i;

	//Show the number of arguments value
	printf("\nNumber of command line arguments: argc = %d",argc);

	//show all command line arguments
	printf("\nValues of the all Command Line Arguments:\n");
	for(i=0;i<argc;i++)
		printf("\nargv[%d] = %s",i,argv[i]);
	
	return 0;
}