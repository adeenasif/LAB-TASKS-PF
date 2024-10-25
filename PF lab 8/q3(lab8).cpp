#include<stdio.h>
int main(){
	int num;
	
	printf("Enter the num to print the pyramid: ");
	scanf("%d", &num);
	
	for(int i = num; i >= 1; i--){
		for(int j = 0; j<(num-i); j++){
			printf(" ");
		}
		for(int j = i; j>=1; j--){
			printf("%d ", j);
		}
		printf("\n");
	}
	
	for(int i = 2; i<= num; i++){
		for(int j = 0; j<(num-i); j++){
			printf(" ");
		}
		for(int j = i; j >= 1; j--){
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
