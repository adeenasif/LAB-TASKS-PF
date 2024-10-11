#include<stdio.h>
int main(){
	int num, Count = 0;
	int prime = 1;
	int temp1 = 0, temp2 = 1;
	
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
	if (prime == 1){
		printf("PRIME");
		printf("\nFibonacci series upto %d: ", num);
	        if (num >=0) {
	            printf("%d ", temp1);
	        }
	        if (num >=1) {
	            printf("%d ", temp2);
	        }
	        Count = temp1 + temp2;
	        while (Count < num){
	            printf ("%d ", Count);
	            temp1 = temp2;
	            temp2 = Count;
	            Count = temp1 + temp2;
	        }
	        printf("\n");
	}else{
		printf("NOT PRIME");
	}

	return 0;
}
