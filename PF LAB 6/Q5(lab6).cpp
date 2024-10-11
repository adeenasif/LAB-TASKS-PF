#include<stdio.h>

int main(){
	int num;
	int prime = 1;
	printf("Enter number to check if it is a prime number or not: ");
	scanf("%d", &num);
	if (num <= 1){
        prime = 0;
    }else{
	for (int i = 2; i*i <= (num); i++) {
		if (num % i == 0){
			prime = 0;
			break;
		}	
	}
}
	if (prime ==1){
		printf("PRIME");
	}else{
		printf("NOT PRIME");
	}
	
	return 0;
}
       
