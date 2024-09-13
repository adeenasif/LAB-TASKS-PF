#include<stdio.h>
int main() {
	int amount;
	int disamount = 0;
	printf("Enter the total cost of shopping: ");
	scanf("%d", &amount);
	
	if (amount < 1500) {
		disamount = amount - amount*7/100;		
	}else if (amount <= 3000 || amount >= 1500) {
		disamount = amount - amount*12/100;		
	}else if (amount <= 5000 || amount > 3000) {
		disamount = amount - amount*22/100;
	}else if (amount > 5000) {
		disamount = amount - amount*30/100;	
	}
	printf("The original amount was %d. \n", amount);
	printf("The amount of money you saved is %d. \n", amount - disamount);
	printf("The amount after applying discount is %d. \n", disamount);
	return 0;
}
