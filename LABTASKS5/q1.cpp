#include<stdio.h>

int main(){
	int age;
	int CitizenshipStatus = 0;
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("Enter 1 for Pakistani Citizenship status and 0 for non-Pakistani Citizenship status: ");
	scanf("%d", &CitizenshipStatus);
	
	if (age >= 18 && CitizenshipStatus == 1) {
	printf("You can vote!");
	}else {
		printf("You are not eligible to vote!");
	}
	return 0;
}
