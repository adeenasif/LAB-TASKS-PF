#include<stdio.h>
int main(){
	int number, sum;

	do{
	printf("Enter a number: ");
	scanf("%d", &number);
	sum += number;
	printf("Sum of the current numbers is %d.\n", sum);
	}while(number!=0);
	printf("The final sum is %d.", sum);
	return 0;
}

