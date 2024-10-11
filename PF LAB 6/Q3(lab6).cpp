#include<stdio.h>
int main(){
	int number;
	do{
		printf("\nEnter a number: ");
		scanf("%d", &number);
		if (number<0){
			printf("NO");
		}
	} while(number<0);
	printf("~<_%d_>~", number);
	return 0;
}

