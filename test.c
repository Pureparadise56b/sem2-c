#include<stdio.h>
#include <string.h>

#define EMP_NO 5

typedef struct 
{
    int acct_no;
    char *name;
    float salary;
    char *contact;
} Employee;

Employee *search(Employee[], int);

int main(){

    Employee employees[EMP_NO] = {
        {1001, "Toufique", 23000, "9339813538"},
        {1002, "Amin", 72000, "7557044160"},
        {1003, "Tanjila", 36000, "6296780856"},
        {1004, "Sujay", 33000, "877356227"},
        {1005, "Geessa", 45000, "7699642138"},
    };
    Employee* result;
    int acctno, input_state;

    printf("Enter an Employee id for search (0 for exit)\n");
    do{
        printf("Employee ID: ");
        input_state = scanf("%d", &acctno);

        if(input_state == 0 || input_state == -1 || acctno == 0) break;

        result = search(employees, acctno);

        if(result != NULL){
            printf("Result Found!!\n");
            printf("\tEmployee Name: %s\n", result->name);
            printf("\tEmployee Salary: %.2f\n", result->salary);
            printf("\tEmployee Contact: %s\n", result->contact);
        }else{
            printf("Result Not Found!!!\n");
        }

    }while(acctno != 0);

    return 0;
}

Employee *search(Employee employees[], int acctno){
    for (int count = 0; count < EMP_NO ; count++)
        if(employees[count].acct_no == acctno) return (&employees[count]);

    return NULL;
    
}