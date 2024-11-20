#include<stdio.h>
#include<string.h>

struct Cars{
	char make[30];
	char model[30];
	int year;
	float price, mileage;
};

void AddCar(struct Cars carInfo[], int *count){
	getchar();
	
	printf("Enter make of the car: ");
	fgets(carInfo[*count].make, 30, stdin);
	carInfo[*count].make[strcspn(carInfo[*count].make, "\n")] = '\0';

	printf("Enter model of the car: ");
	fgets(carInfo[*count].model, 30, stdin);
	carInfo[*count].model[strcspn(carInfo[*count].model, "\n")] = '\0';
	
	printf("Enter year: ");
	scanf("%d", &carInfo[*count].year);
	getchar();
	
	printf("Enter price: ");
	scanf("%f", &carInfo[*count].price);
	getchar();
	
	printf("Enter mileage: ");
	scanf("%f", &carInfo[*count].mileage);
	getchar();
	
	(*count)++;
	printf("Car Added Successfully!!");
	printf("\n");
}

int DisplayCars(struct Cars carInfo[], int count){
	for(int i = 0; i < count; i++){
		printf("\nMake: %s\n", carInfo[i].make);
		printf("Model: %s\n", carInfo[i].model);
		printf("Year: %d\n", carInfo[i].year);
		printf("Price: %.2f\n", carInfo[i].price);
		printf("Mileage: %.2f\n", carInfo[i].mileage);
	}
}

int SearchCar(struct Cars carInfo[], int count){
	char makeInput[30], modelInput[30];
	
	printf("Enter make of the car to search: ");
	getchar();
	fgets(makeInput, 30, stdin);
	makeInput[strcspn(makeInput, "\n")] = '\0';
	
	printf("Enter model of the car to search: ");
	fgets(modelInput, 30, stdin);
	modelInput[strcspn(modelInput, "\n")] = '\0';
	
	for(int i = 0; i < count; i++){
		if ((strcmp(makeInput, carInfo[i].make) == 0) && (strcmp(modelInput, carInfo[i].model) == 0)){
			printf("\nMake: %s\n", carInfo[i].make);
			printf("Model: %s\n", carInfo[i].model);
			printf("Year: %d\n", carInfo[i].year);
			printf("Price: %.2f\n", carInfo[i].price);
			printf("Mileage: %.2f\n", carInfo[i].mileage);
		} else{
			printf("Car not found!\n");
		}
	}
}

int main(){
	struct Cars Info[50];
    int count = 0;
	int choice;
	
	do{
		printf("\nCar Dealership\n");
		printf("1. Add new car\n");
		printf("2. Display list of available cars\n");
		printf("3. Search a car\n");
		printf("4. Exit\n");
		printf("\n");
		printf("Enter choice:");
		scanf("%d", &choice);
		if (choice == 1){
			AddCar(Info, &count);
		} else if (choice == 2){
			DisplayCars(Info, count);
		} else if (choice == 3){
			SearchCar(Info, count);
		} else {
			printf("Invalid Choice!!");
			break;
		}
	}while(choice!=4);
	return 0;
}
