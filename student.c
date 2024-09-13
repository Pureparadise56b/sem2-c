#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char name[40];
  int rollNo;
  float marks;
} Student;

Student getStudentDetails(void);
Student *getStudentsList(int);
void printStudentDetails(Student);
void printStudentList(Student*, int);
int getHighestScoreStudent(Student*, int);
int getLowestScoreStudent(Student*, int);
Student *copyStudentList(Student*, int);
void swapStudent(Student*, Student*);
Student *reorderStudentList(Student*, int);

int main(){

  Student *list;
  int list_size, choice;

  while(1){
    printf("\n1. create student list.");
    printf("\n2. show student list.");
    printf("\n3. show highest student details.");
    printf("\n4. show lowest student details.");
    printf("\n5. reorder student list (accending).");
    printf("\n6. exit.");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        free(list);
        printf("\nHow many students do you want? ");
        scanf("%d", &list_size);
        list = getStudentsList(list_size);
        break;
      case 2:
        printStudentList(list, list_size);
        break;
      case 3:
        printf("\nDetails of higest student\n");
        printStudentDetails(list[getHighestScoreStudent(list, list_size)]);
        break;
      case 4:
        printf("\nDetails of lowest student\n");
        printStudentDetails(list[getLowestScoreStudent(list, list_size)]);
        break;
      case 5:
        printStudentList(reorderStudentList(list, list_size), list_size);
        break;
      case 6:
        exit(0);
      default:
        printf("\n\tWrong Option!!!");
    }
  }

  return 0;
}

Student getStudentDetails(void){
  Student s;
  printf("Enter Name: ");
  scanf(" %[^\n]", s.name);
  printf("Enter roll no: ");
  scanf("%d", &s.rollNo);
  printf("Enter marks: ");
  scanf("%f", &s.marks);

  return s;
}

Student *getStudentsList(int list_size){
  Student *list;
  int i;
  list = (Student *) malloc(list_size * sizeof(Student));
  for(i=0; i < list_size; i++){
    printf("\nEnter details for Student %d\n", i + 1);
    list[i] = getStudentDetails();
  }
  return list;
}

void printStudentDetails(Student s){
  printf("roll: %03d,\tname: %s,\tmarks: %0.2f\n", s.rollNo, s.name, s.marks);
  return;
}

void printStudentList(Student *list, int list_size){
  int i;
  for ( i = 0; i < list_size; i++)
  {
    printf("\nDetails for Student %d - ", i + 1);
    printStudentDetails(list[i]);
  }
  return;
}

int getHighestScoreStudent(Student *list, int list_size){
  int higest_posititon = 0, i;

  for(i = 1; i < list_size; i++)
    if(list[i].marks > list[higest_posititon].marks) higest_posititon = i;
  
  return higest_posititon;
}

int getLowestScoreStudent(Student *list, int list_size){
  int lowest_position = 0, i;

  for(i = 1; i < list_size; i++)
    if(list[i].marks < list[lowest_position].marks) lowest_position = i;

  return lowest_position;
}

Student *copyStudentList(Student* list, int list_size){
  Student *copy_list;
  int i;

  copy_list = (Student *) malloc(list_size * sizeof(Student));

  for(i = 0; i < list_size; i++)
    copy_list[i] = list[i];
  
  return copy_list;
}

void swapStudent(Student *s1, Student *s2){
  Student temp_s;
  temp_s = *s1;
  *s1 = *s2;
  *s2 = temp_s;

  return;
}

Student *reorderStudentList(Student *list, int list_size){
  Student *copy_list;
  int pass, i, is_swapped;

  copy_list = copyStudentList(list, list_size);

  for(pass = 1; pass < list_size; pass++){
    is_swapped = 0;
    for(i = 0; i < (list_size - pass); i++){
      if(copy_list[i].marks > copy_list[i + 1].marks){
        swapStudent(&copy_list[i], &copy_list[i + 1]);
        is_swapped++;
      }
    }
    if(!is_swapped) break;
  }
  
  return copy_list;
}