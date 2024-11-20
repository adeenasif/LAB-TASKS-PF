#include<stdio.h>

int Sum(int value){
	if (value == 0){
		return 0;
	} 
	int result = value%10 + Sum(value/10);
	return result;
}

int main(){
	int value;
	printf("Enter value to get the sum of digits: ");
	scanf("%d", &value);
	
	int SumOfDigits = Sum(value);
	printf("Sum of digits: %d", SumOfDigits);
	
	return 0;
}

