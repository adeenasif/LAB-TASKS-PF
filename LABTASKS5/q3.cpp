#include<stdio.h>

int main() {
	int percentage;
	char grade;
	
	printf("Enter your percentage: ");
	scanf("%d", &percentage);
	
	grade = (percentage >= 90)? grade = 'A' :
	(percentage>= 80 && percentage <= 89)? grade ='B':
	(percentage>= 70 && percentage <= 79)? grade ='C': 
	(percentage>= 60 && percentage <= 59)? grade ='D' :
	(percentage < 60)? grade = 'F' : grade = 'Y';
	
	printf("Your grade is %c", grade);
	return 0;
	

}
