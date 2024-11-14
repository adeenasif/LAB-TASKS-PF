#include<stdio.h>
int main(){
	int bolts, nuts, washers;
	printf("Enter the Number of Bolts: ");
	scanf("%d", &bolts);
	printf("Enter the Number of Nuts: ");
	scanf("%d", &nuts);
	printf("Enter the Number of Washers: ");
	scanf("%d", &washers);
	
	int Boltprice = 5 * bolts;
	int Nutsprice = 3 * nuts;
	int TotalPrice = Boltprice + Nutsprice + washers;
	
	if (bolts != nuts){
		printf("Check the Order: too few nuts\n");
	} else if((2*bolts) != washers){
		printf("Check the Order: too few washers\n");
	} else {
		printf("Order is OK!\n");
	}
	printf("Total Cost: %d", TotalPrice);
	return 0;
}
