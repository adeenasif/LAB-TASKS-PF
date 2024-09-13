#include<stdio.h>

int main() {
	int num1, num2;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	
	if (num1 > num2) {
		if (num1 > 100) {
			printf("First number is significantly larger");
		}else {
			printf("First number is larger");
		}
	}else if (num1 < num2) {
		if (num1 < 0) {
			printf("First number is negative and smaller");
		}else {
			printf("First number is smaller");
		}
	}else if (num1== num2) {
		printf("Both numbers are equal");
	}else {
		printf("Invalid Input!");
	}
	return 0;
}
