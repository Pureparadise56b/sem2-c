/*Q. Use command line arguments for the testing of basic operations on files:
  1. file open and close in different modes
  2. file read and write operations.  
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	FILE *FptIn, *FptOut; //Define the file pointers
	int x,y;
	int a,b;
	//This program run under a commond line.
	//At command line you have to give three arguments.
	//First the program name and 2nd & 3rd respectively
	// the name output and input file names.
	if (argc != 3)
	{
		printf("\nInvalid command\n\n");
		exit(1);
	}
	//This will create a new file. 
	//If the file already in the current directory then 
	//it will be erased without any warning.
	FptOut = fopen(argv[1], "wt");
	//If file creation is successful then File Point 
	// must point to a FILE like structure. So FptOut will
	// not NULL.
	if(FptOut == NULL)
	{
		printf("\nFile %s cannot be created\n\n", argv[1]);
		exit(1);
	}
	//This part is the illustration of file writing
	printf("\nEnter x & y:");
	scanf("%d%d",&x,&y);
	fprintf(FptOut, "%d,%d\n",x,y);
	
	printf("\nEnter x & y:");
	scanf("%d%d",&x,&y);
	fprintf(FptOut, "%d,%d\n",x,y);
	
	fclose(FptOut);
	//This part is for the illustration of file read.
	//FptIn = fopen(argv[2], "rt"); - open the existing file in read only mode. Here we are using text file.
	//File will be text file. It will be an existing file.
	//Both read and write operations can be performed on this file.
	FptIn = fopen(argv[2], "r+t");
	//If file cannot be opened the File Pointer is NULL.
	if(FptIn == NULL)
	{
		printf("\nFile %s cannot be opened\n", argv[2]);
		exit(1);
	}
	//Reading data from file. Between two integers there 
	//must be an comma separtion.
	fscanf(FptIn,"%d,%d",&a,&b);
	printf("\na=%d\tb=%d",a,b);
	fclose(FptIn);	
}