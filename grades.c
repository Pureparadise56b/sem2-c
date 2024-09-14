/* Q. Develope a C language Program that will take marks obtained by the student in a number of different subjects and then it will calculate and show the average and grade letter as the result of the student. Use switch-case  for the grade calculation.

		Average Marks(%)	Grade Letter
			>=90				A+
			80<= and <90		A
			70<= and <80		B+
			60<= and <70		B
			50<= and <60		C+
			40<= and <50		C
			<40					FAIL
*/

#include<stdio.h>
#include<stdlib.h>

char *FindGrade(float);

int main(){
	int n,i,a[100],sum=0,flag;
	float avg=0;

	printf("Enter The Number Of Subjects: ");
	scanf("%d",&n);
	printf("\nEnter all Marks for the Student:\n");

	for(i = 0; i < n; i++){
		printf("\nMarks for Subject #%d:", i + 1);
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}

	avg=sum/n;

	//marks average upto two decimal points
	printf("\nAverage Marks obtained by the student:%.2f and Grade:%s\n\n\n", avg, FindGrade(avg));

	return 0;
}

char *FindGrade(float avg){	
	char *GradeStr = (char *) malloc(5 * sizeof(char));

	switch((int)(avg/10)){
		case 10:
			GradeStr = "A+";
			break;
		case 9:
			GradeStr = "A+";
			break;
		case 8:
			GradeStr = "A";
			break;
		case 7: 
			GradeStr = "B+";
			break;
		case 6: 
			GradeStr = "B";
			break;
		case 5: 
			GradeStr = "C+";
			break;
		case 4: 
			GradeStr = "C";
			break;
		case 3:
		case 2:
		case 1:
		case 0:
			GradeStr = "FAIL";
			break;
		default: 
			GradeStr = "N/A";
	}

	return GradeStr;
}