/*Q. Write a program in C language to create a file containing names of persons.
Display the person name having the largest number of characters and store it in another file.
Use command line arguments for taking file names.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* createFile() function is used to build a list of person names (single word name) which is stored in a file. The file name is passed as an argument to this function. */
void createFile(char *fileName)
{
  char *name;
  int Response;
  FILE *Fpt;
  Fpt = fopen(fileName, "wt");
  if (Fpt == NULL)
  {
    printf("\nFile not found ....\n");
    exit(0);
  }
  name = (char *)malloc(100 * sizeof(char));
  while (1)
  {
    printf("\nAny more name of person (0 = No, 1=Yes):");
    scanf("%d", &Response);
    if (Response == 0)
      break;
    ;
    printf("\nEnter name of person:");
    scanf("%s", name);
    fprintf(Fpt, "%s\n", name);
  }
  fclose(Fpt);
}

/* displayFile() function is used to show the list of person names taking
from input file.*/
void displayFile(char *fileName)
{
  char *name;
  name = (char *)malloc(100 * sizeof(char));
  FILE *Fpt;
  Fpt = fopen(fileName, "rt");
  if (Fpt == NULL)
  {
    printf("\nFile not found ....\n");
    exit(0);
  }
  while (fscanf(Fpt, "%s", name) != EOF)
    printf("\n%s", name);
  fclose(Fpt);
}

/* getLargestName() function to find the largest length name from the file.*/
char *getLargestName(char *fileName)
{
  char *name;
  int max = 0;
  char *largestName;
  FILE *Fpt;
  Fpt = fopen(fileName, "rt");
  if (Fpt == NULL)
  {
    printf("\nFile not found ....\n");
    exit(0);
  }
  name = (char *)malloc(100 * sizeof(char));
  while (fscanf(Fpt, "%s", name) != EOF)
  {
    if (strlen(name) > max)
    {
      max = strlen(name);
      largestName = (char *)malloc(100 * sizeof(char));
      strcpy(largestName, name);
    }
  }
  fclose(Fpt);
  return largestName;
}

/*Save the largest person name in the other file*/
void saveInFile(char *fileName, char *name)
{
  FILE *Fpt;
  Fpt = fopen(fileName, "a");
  if (Fpt == NULL)
  {
    printf("\nFile not found ....\n");
    exit(0);
  }
  fprintf(Fpt, "%s\n", name);
  fclose(Fpt);
}
/* In the command line along with program file name (executable / compiled)
you have to provide two other file names which are used for input / output
operations.
Example:
for compilation
$gcc -o FileLargestLine FileLargestLine.c
for execution
$./FileLargestLine input.txt output.txt
*/
void main(int argc, char *argv[])
{
  char *name;
  if (argc != 3)
  {
    printf("\nInvalid command\n\n");
    exit(1);
  }
  printf("\nEnter names of people:\n");
  createFile(argv[1]);
  printf("\nFile created successfully\n");
  displayFile(argv[1]);
  name = (char *)malloc(100 * sizeof(char));
  name = getLargestName(argv[1]);
  printf("\nLargest name in the file is: %s\n", name);
  saveInFile(argv[2], name);
  printf("\nOk");
}