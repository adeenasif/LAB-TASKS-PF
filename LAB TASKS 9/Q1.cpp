#include<stdio.h>

int Shape(int Num){
	for (int i = Num+1; i >= 1; i--){
		for (int j = 0; j <= i; j++){
			if (j >= i && j <= Num+1){
				for (int k = j; k <= Num+1; k++){
					printf("o");	
				}
			}else{
				printf(". ");
			}
		}
		printf("\n");
	}
	for (int i = 2; i <= Num+1; i++){
		for (int j = 0; j <= i; j++){
			if (j >= i && j <= Num+1){
				for (int k = j; k <= Num+1; k++){
					printf("o");	
				}
			}else{
				printf(". ");
			}
		}
		printf("\n");
	}
}

int main(){
	int Num;
	printf("Enter number: ");
	scanf("%d", &Num);
	Shape(Num);
}
