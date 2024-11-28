#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 200

struct Book {
    char id[20];
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook() {
    FILE *file = fopen("library.txt", "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    printf("Enter Book ID: ");
    scanf(" %[^\n]", book.id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", book.title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", book.author);
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);

    fprintf(file, "%s,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    fclose(file);
    printf("Book added successfully.\n");
}

void viewBooks() {
    FILE *file = fopen("library.txt", "r");
    if (!file) {
        printf("No books found or error opening file.\n");
        return;
    }

    struct Book book;
    printf("\n%-10s %-30s %-20s %-10s %-10s\n", "ID", "Title", "Author", "Quantity", "Price");
    printf("\n");

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        printf("%-10s %-30s %-20s %-10d $%-10.2f\n", book.id, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void searchBook() {
    FILE *file = fopen("library.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    char searchTerm[100];
    printf("Enter Book ID or Title to search: ");
    scanf(" %[^\n]", searchTerm);

    struct Book book;
    int found = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (strstr(book.id, searchTerm) != NULL || strstr(book.title, searchTerm) != NULL) {
            printf("\nBook Found:\n");
            printf("ID: %s\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", book.id, book.title, book.author, book.quantity, book.price);
            found = 1;
        }
    }

    if (!found) {
        printf("No matching book found.\n");
    }

    fclose(file);
}

void deleteBook() {
    FILE *file = fopen("library.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    char deleteID[20];
    printf("Enter Book ID to delete: ");
    scanf(" %[^\n]", deleteID);

    struct Book book;
    int found = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        if (strcmp(book.id, deleteID) != 0) {
            fprintf(temp, "%s,%s,%s,%d,%.2f\n", book.id, book.title, book.author, book.quantity, book.price);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book with ID %s not found.\n", deleteID);
    }
}

void calculateInventoryValue() {
    FILE *file = fopen("library.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    struct Book book;
    float totalValue = 0;

    while (fscanf(file, "%[^,],%[^,],%[^,],%d,%f\n", book.id, book.title, book.author, &book.quantity, &book.price) != EOF) {
        totalValue += book.quantity * book.price;
    }

    printf("Total Inventory Value: $%.2f\n", totalValue);
    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Calculate Total Inventory Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                calculateInventoryValue();
                break;
            case 6:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

