#include<stdio.h>;
	int main() {
	
	int Num;
	int Factorial = 1;
	printf("Enter the number to find its factorial: ");
	scanf("%d", &Num);
	if (Num >= 0) {
		for (int i = Num; i>0; i--){
		Factorial = Factorial * i;
		}
		printf("Factorial is %d", Factorial);	
	}else{
		printf("Inavlid value entered!");
	}
	return 0;

}
