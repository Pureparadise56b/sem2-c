#include<stdio.h>
#include<stdlib.h>

typedef struct Node_Tag {
  int data;
  struct Node_Tag *next;
} Node;

Node *createNode(void);
Node *createList(void);
Node *insertAtBeg(Node*, int);
Node *insertAtEnd(Node*, int);
Node *insertAfterData(Node*, int, int);
Node *deleteNodeFromList(Node*, int);
void showList(Node *list);
void showRevList(Node *list);
void searchList(Node*, int);

int main(){

  Node *list = NULL;
  int choice, data, search_data;

  while(1){
    printf("\n1. create linked list.");
    printf("\n2. insert at begining of the list.");
    printf("\n3. insert at end of the list.");
    printf("\n4. insert after a certain data.");
    printf("\n5. show the list");
    printf("\n6. show the list in reverse.");
    printf("\n7. search data in the list.");
    printf("\n8. delete a node from the list.");
    printf("\n9. exit.");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        list = createList();
        break;
      case 2:
        printf("\nEnter the data: ");
        scanf("%d", &data);
        list = insertAtBeg(list, data);
        break;
      case 3:
        printf("\nEnter the data: ");
        scanf("%d", &data);
        list = insertAtEnd(list, data);
        break;
      case 4:
        printf("\nEnter the node data after you want to insert: ");
        scanf("%d", &search_data);
        printf("Enter the data: ");
        scanf("%d", &data);
        list = insertAfterData(list, data, search_data);
        break;
      case 5:
        printf("\nResult -> ");
        showList(list);
        printf("\n");
        break;
      case 6:
        printf("\nResult -> ");
        showRevList(list);
        printf("\n");
        break;
      case 7:
        printf("\nEnter the data that you want to search: ");
        scanf("%d", &data);
        searchList(list, data);
        break;
      case 8:
        printf("\nEnter the data that you want to delete: ");
        scanf("%d", &data);
        list = deleteNodeFromList(list, data);
        break;
      case 9:
        exit(0);
      default:
        printf("\n\tWrong Option!!!\n");
    }
  }

  return 0;
}

Node *createNode(void){
  Node *ptr;
  ptr = (Node *) malloc(sizeof(Node));
  ptr->next = NULL;
  return ptr;
}

Node *createList(void){
  Node *start = NULL;
  char choice = 'y';
  int data;

  while(1){
    if(choice == 'n' || choice == 'N') return start;
    else if(choice == 'y' || choice == 'Y'){
      printf("\nEnter the data: ");
      scanf("%d", &data);
      start = insertAtBeg(start, data);
    }
    else
      printf("\n\tPlease choose between y or n!!\n");
    
    printf("\nAny more node to add? (y/n): ");
    scanf(" %c", &choice);
  }
}

Node *insertAtBeg(Node* list, int data){
  Node *node = createNode();

  if(node == NULL){
    printf("\n\tNo enough space!!\n");
    return list;
  }

  node->data = data;
  node->next = list;
  list = node;

  return node;
}

Node *insertAtEnd(Node *list, int data){
  Node *node, *ptr;
  ptr = list;
  node = createNode();

  if(node == NULL){
    printf("\n\tNo enough space!!\n");
    return list;
  }
  node->data = data;

  if(list == NULL) return node;

  while(ptr->next != NULL)
    ptr = ptr->next;
  
  ptr->next = node;

  return list;
}

Node *insertAfterData(Node *list, int data, int search_data){
  Node *node, *ptr;

  node = createNode();

  if(node == NULL){
    printf("\n\tNo enough space!!\n");
    return list;
  }

  node->data = data;
  ptr = list;

  while(ptr->next != NULL && ptr->data != search_data)
    ptr = ptr->next;

  if(ptr->next == NULL)
    ptr->next = node;
  else {
    node->next = ptr->next;
    ptr->next = node;
  }

  return list;
}

Node *deleteNodeFromList(Node *list, int data) {
  Node *deleted_node = NULL, *ptr, *prev;

  if (list == NULL) {
    printf("\n\tnothing to delete!!\n");
    return list;
  }

  if (list->data == data) {
    deleted_node = list;
    list = deleted_node->next;
  } else {
    ptr = list;
    prev = NULL;

    while (ptr != NULL && ptr->data != data) {
      prev = ptr;
      ptr = ptr->next;
    }

    if (ptr != NULL && ptr->data == data) {
      deleted_node = ptr;
      prev->next = deleted_node->next;
    } else {
      printf("\n\tNo data found\n");
      return list;
    }
  }

  if (deleted_node != NULL) {
    deleted_node->next = NULL;
    free(deleted_node);
  }

  return list;
}

void showList(Node *list){
  Node *ptr;
  ptr = list;
  while (ptr != NULL)
  {
    printf("%d\t", ptr->data);
    ptr = ptr->next;
  }
  return;
}

// recursion method
void showRevList(Node *list){
  if(list == NULL) return;

  // if change the position of this two statement then it shows the original list
  showRevList(list->next);
  printf("%d\t", list->data);
}

void searchList(Node *list, int data){
  Node *ptr;
  ptr = list;

  while(ptr->next != NULL && ptr->data != data)
    ptr = ptr->next;

  if(ptr->data == data)
    printf("\n\tData found\n");
  else
    printf("\n\tNo data found\n");
  
  return;
}