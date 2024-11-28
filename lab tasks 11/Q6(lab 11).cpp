#include<stdio.h>
#include<string.h>
struct Invoice{
	char part[10];
	char description[20];
	int quantity;
	float price;
};

int main(){
	float invoiceAmount;
	struct Invoice details;
	
	strcpy(details.part, "P123");
    strcpy(details.description, "Tool");
	details.quantity = 4;
	details.price = 1234.56;
	
	if (details.price < 0){
		details.price = 0;
	}	
	if ( details.quantity < 0){
		details.quantity = 0;
	}
	
	invoiceAmount = details.price * details.quantity;
	
	printf("Invoice Amount: %.2f", invoiceAmount);
	return 0;
}

