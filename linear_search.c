#include<stdio.h>
#include<stdlib.h>

#define NOTFOUND -1

int *createArray(int *, int);
int searchArray(int *, int, int);

int main(){
  int *ptr = NULL, n, choice, search_value, searched_indexed;
  while (1){
    printf("\n1. create a new array.\n");
    printf("2. search a value in the array.\n");
    printf("3. exit.\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("\nEnter the size of the array: ");
        scanf("%d", &n);
        ptr = createArray(ptr, n);
        break;
      case 2:
        printf("\nEnter the value that you want to search: ");
        scanf("%d", &search_value);
        searched_indexed = searchArray(ptr, n, search_value);

        if(searched_indexed == NOTFOUND)
          printf("\nValue not found");
        else
          printf("\nValue found, position of the element is %d", searched_indexed + 1);
        break;
      case 3:
        exit(0);
      default:
        printf("\nWrong options!!!\n");
    }
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d, ", ptr[i]);
  }

  return 0;
}

int *createArray(int *ptr, int array_size){
  
  /* memory deallocation of previous array */
  if(ptr != NULL){
    free(ptr);
    ptr = NULL;
  }

  ptr = (int *) malloc(array_size * sizeof(int));

  if(ptr == NULL){
    printf("\nNo available memory!!\n");
    exit(1);
  }

  for(int i = 0; i < array_size; i++){
    printf("\nEnter the value for %dth element: ", i + 1);
    scanf("%d", ptr + i);
  }

  return ptr;
}

int searchArray(int *ptr, int array_size, int search_value){
  for (int i = 0; i < array_size; i++){
    if(ptr[i] == search_value) return i;
  }

  return -1;
}