#include<stdio.h>;
	int main(){

	int num, EvenNum;
	printf("Enter Number: ");
	scanf("%d", &num);
	if (num >= 1) {
	while (num != 0){
		if (num%2 == 0){
			EvenNum = num;
			printf("%d is an even number\n", EvenNum);
			num --;
		}else{
			num--;
		}

	}	
	}else{
		printf("Invalid number entered!");
	}	
	return 0;
}
