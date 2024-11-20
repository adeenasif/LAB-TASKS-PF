#include<stdio.h>
#include<string.h>

struct Travel{
	char name[30];
	char destination[30];
	int duration;
	float cost;
	int seats;
	
};

void DisplayPackage(struct Travel package[], int count){
	for (int i = 0; i < count; i++){
		printf("\nDetails of Package %d: \n\n", i+1);
		printf("Package Name: %s\n", package[i].name);
		printf("Destination: %s\n", package[i].destination);
		printf("Duration of trip: %d\n", package[i].duration);
		printf("Package Cost: %.2f\n", package[i].cost);
		printf("Number of seats available: %d\n", package[i].seats);
	}
}

void bookPackage(struct Travel package[], int count) {
    int choice;
    printf("Enter the package number to book (1 to %d): ", count);
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Invalid package number!\n");
        return;
    }

    if (package[choice - 1].seats > 0) {
        package[choice - 1].seats--;
        printf("Booking successful for package: %s\n", package[choice - 1].name);
    } else {
        printf("Sorry, no seats available for the selected package.\n");
    }
}

int main(){
	int choice;
	struct Travel package[2] = {
        {"Turkey Tour", "Turkey", 5, 1900.0, 10},
        {"Tropical Adventure", "Maldives", 7, 1500.57, 5}
    };
    
    int count = 2;
    do{
    	printf("\nTravel Packages\n");
		printf("1. Book a travel package\n");
		printf("2. Display available packages\n");
		printf("3. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				bookPackage(package, count);
				break;
			case 2:
				DisplayPackage(package, count);
				break;
			case 3:
				printf("Bye!");
				break;
			default:
				printf("Invalid choice\n");
		}	
	} while (choice != 3);
	
	return 0;	
}
