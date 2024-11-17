#include<stdio.h>
#include<string.h>

struct Book{
	char Title[50];
	char Author[50];
	int Year, ISBN;
	int isAvailable;
};

void AddBooks(struct Book BookInfo[], int *count){
	getchar();
	printf("\nEnter Book Details here: \n\n");
	printf("Enter book Title: ");
	fgets(BookInfo[*count].Title, 50, stdin);
	BookInfo[*count].Title[strcspn(BookInfo[*count].Title, "\n")] = '\0';
	
	printf("Enter Author name: ");
	fgets(BookInfo[*count].Author, 50, stdin);
	BookInfo[*count].Author[strcspn(BookInfo[*count].Author, "\n")] = '\0';
	
	printf("Enter ISBN number: ");
	scanf("%d", &BookInfo[*count].ISBN);
	
	printf("Enter Publication Year: ");
	scanf("%d", &BookInfo[*count].Year);
	
	BookInfo[*count].isAvailable = 1;
	
	(*count)++;
}

void SearchBook(struct Book BookInfo[], int count){
	char search[50];
	
	if (count == 0){
		printf("No books available in the Library!");
		return;
	}
	
	getchar();
	printf("Enter title or author of book to search: ");
	fgets(search, 50, stdin);
	search[strcspn(search, "\n")] = '\0';
	
	int found = 0, index = 0;
	for (int i = 0; i < count; i++){
		if((strcmp(search, BookInfo[i].Title) == 0) || (strcmp(search, BookInfo[i].Author) == 0)){
			found = 1;
			printf("Book Found!\n");
			printf("Book Title: %s\n", BookInfo[i].Title);
			printf("Book Author: %s\n", BookInfo[i].Author);
			printf("Book ISBN number: %d\n", BookInfo[i].ISBN);
			printf("Book Publication Year: %d\n", BookInfo[i].Year);
            printf("Availability: %s\n", BookInfo[i].isAvailable ? "Available" : "Checked Out");
			break;
		} 
	}
	if(!found){
		printf("Book not found!\n\n");
	}
}

void Availability(struct Book BookInfo[], int count){
	char title[50];
    int option;

    if (count == 0) {
        printf("No books available in the library!\n\n");
        return;
    }

    getchar(); 
    printf("Enter title of the book to update its status: ");
    fgets(title, 50, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(title, BookInfo[i].Title) == 0) {
            printf("Enter 0 to check out the book or 1 to return the book: ");
            scanf("%d", &option);

            if (option == 0) {
                if (BookInfo[i].isAvailable) {
                    BookInfo[i].isAvailable = 0; 
                    printf("Book checked out successfully!\n\n");
                } else {
                    printf("Book is already checked out!\n\n");
                }
            } else if (option == 1) {
                if (!BookInfo[i].isAvailable) {
                    BookInfo[i].isAvailable = 1; 
                    printf("Book returned successfully!\n\n");
                } else {
                    printf("Book is already available!\n\n");
                }
            } else {
                printf("Invalid option!\n\n");
            }
            return;
        }
	}
    printf("Book not found!\n\n");
}

int main(){
	int choice, count = 0;
	struct Book BookInfo[100];
	
	do{
		printf("\n1. Enter 1 to add new book\n");
		printf("2. Enter 2 to search for a book\n");
		printf("3. Enter 3 to check availability status (Check Out or Return)\n");
		printf("4. Enter 4 to exit\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		if (choice == 1){
			AddBooks(BookInfo, &count);
		} else if (choice == 2){
			SearchBook(BookInfo, count);
		} else if (choice == 3){
			Availability(BookInfo, count);
		} else if(choice == 4){
			printf("Exiting..");
		}else{
			printf("Invalid Choice!");
			break;
		}
	}while(choice!=4);

	return 0;
}


