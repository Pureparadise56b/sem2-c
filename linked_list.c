#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int item;
  struct Node *next;
} node;

node head;

void create(node*);
void display(node*);

int main(){
  int value;



  do{
    printf("enter the value: ");
    scanf("%d", &value);

    if(value < 0)break;

    

  }while(value > 0);
}