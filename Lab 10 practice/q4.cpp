#include<stdio.h>
#include<string.h>

struct Flight{
	char flightNumber[10];
	char departureCity[30];
	char arrivalCity[30];
	char departureTime[10];
	char arrivalTime[10];
	int availableSeats;
};

void bookSeats(struct Flight Info[], int count){
	char flight[10];
	
	getchar();	
	printf("\nEnter flight number to book a seat: ");
	fgets(flight, 10, stdin);
    flight[strcspn(flight, "\n")] = '\0';
	
	for(int i = 0; i < count; i++){
		if(strcmp(flight, Info[i].flightNumber) == 0){
			if(Info[i].availableSeats > 0){
				printf("\nFlight booked!\n\n");
				Info[i].availableSeats--;
			} else {
				printf("Seats not available!\n\n");
			}
			return;
		} 
	}
	printf ("\nInvalid Flight Number!\n\n");
}

void displayFlights(struct Flight Info[], int count){
	char departure[30], arrival[30];
	getchar();
	printf("\nEnter departure city: ");
	fgets(departure, 30, stdin);
    departure[strcspn(departure, "\n")] = '\0';
    
	printf("Enter arrival city: ");
	fgets(arrival, 30, stdin);
    arrival[strcspn(arrival, "\n")] = '\0';
	
	int found = 0;
	printf("\nAvailable Flights: \n\n");
	for (int i = 0; i < count; i++){
		if(strcmp(Info[i].departureCity, departure) == 0 && strcmp(Info[i].arrivalCity, arrival) == 0 ){
			if(Info[i].availableSeats > 0){
				found = 1;
				printf("Flight Number: %s\n", Info[i].flightNumber);
				printf("Departure City: %s\n", Info[i].departureCity);
				printf("Arrival City: %s\n", Info[i].arrivalCity);
				printf("Departure Time: %s\n", Info[i].departureTime);
				printf("Arrival Time: %s\n", Info[i].arrivalTime);
				printf("No. of seats available: %d\n", Info[i].availableSeats);
				printf("\n");	
			} 
		}
	}
	
    if (!found) {
        printf("No flights available!\n\n");
    }
}

void updateDetails(struct Flight Info[], int count){
	char flight[10];
	printf("Enter flight number to update its schedule: ");
	getchar();
	fgets(flight, 10, stdin);
    flight[strcspn(flight, "\n")] = '\0';

	for(int i = 0; i < count; i++){
		if(strcmp(Info[i].flightNumber, flight) == 0){
			printf("Enter new departure time: ");
 			fgets(Info[i].departureTime, 10, stdin);
 		    Info[i].departureTime[strcspn(Info[i].departureTime, "\n")] = '\0';
		
 			printf("Enter new arrival time: ");
			fgets(Info[i].arrivalTime, 10, stdin);
			Info[i].arrivalTime[strcspn(Info[i].arrivalTime, "\n")] = '\0';
			 
			printf("Schedule updated successfuly!\n\n");
			return;
		} 
	}
	printf("No flight available of this number!\n\n");

}

int main(){
	int count = 3, choice;
	struct Flight flights[100] = {
        {"AB123", "Pakistan", "Dubai", "10:00", "13:00", 10},
        {"BA456", "New York", "London", "08:00", "09:30", 50},
        {"BA456", "Dubai", "Pakistan", "09:00", "11:00", 20}
    };
    
    do{
    	printf("1. Display available flights\n");
    	printf("2. Book flight\n");
    	printf("3. Update flight details\n");
    	printf("4. Exit\n\n");
    	printf("Enter choice: ");
		scanf("%d", &choice);
		
		if (choice == 1){
			displayFlights(flights, count);
		} else if (choice == 2){
			bookSeats(flights, count);
		} else if (choice == 3){
			updateDetails(flights, count);
		} else if (choice == 4){
			printf("Exiting..");
		} else {
			break;
		}
	} while (choice != 4);
    
    return 0;
}
