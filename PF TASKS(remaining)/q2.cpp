#include<stdio.h>
int main() {
	int units;
	float bill = 0.00;
		
	printf("Enter electricity unit charges: ");
	scanf("%d", &units);

	if (units <= 30) {
		bill = units * 0.6;
	}else if (units > 30 && units<= 80){
		bill = units * 0.85;
	}else if (units > 80 && units<= 100){
		bill = units * 1.30;	
	}else if (units > 210){
		bill = units * 1.6;
	}else{
		printf("Invalid input!");
	}
	bill = bill + (bill * 15/100);
	printf("Your total bill including additional surcharge of 15 percent is %0.2f", bill);
	return 0;
}

