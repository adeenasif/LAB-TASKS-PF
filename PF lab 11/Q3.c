#include<stdio.h>
#include<stdlib.h>

void addElement(float **Array, int *size, int *initialCapacity, float num){
    if(*size >= *initialCapacity){
        *initialCapacity *= 2;
        *Array = (float *)realloc(*Array, *initialCapacity * sizeof(float));
        if (*Array == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }

    (*Array)[*size] = num;
    (*size)++;
    printf("\nAdded successfully!!\n");
    
}

void display(float *Array, int size){
    if (size == 0){
         printf("\nNo data to display\n");
    } else{
        printf("\nArray Elements:\n");
        for (int i = 0; i < size; i++){
            printf("%.2f ", Array[i]);
        }
        printf("\n");
    }
}

void removeElement(float *Array, int *size){
    if (*size <= 0){
        printf("No data left to remove!!\n");
    } else{
        (*size)--;
        printf("Data removed successdully!!\n");
    }
}

void reduceSize(float **Array, int *size, int *initialCapacity) {
    if (*size < *initialCapacity / 4) {  //reduce the memory size of array by 50% when the size is less then 25%
        *initialCapacity /= 2;
        *Array = (float *)realloc(*Array, *initialCapacity * sizeof(float));
        if (*Array == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
}


int main(){
    int choice, size = 0;
    float num;
    int initialCapacity = 4;
    float *Array = (float *)malloc(initialCapacity * sizeof(float));

    do{
        printf("\n1. Add a new number to the array\n");
        printf("2. Display all numbers in the array\n");
        printf("3. Remove the last number from the array\n");
        printf("4. Resize the Array \n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            printf("Enter the floating number to add in array: ");
            scanf("%f", &num);
            addElement(&Array, &size, &initialCapacity, num);
        } else if (choice == 2){
            display(Array, size);
        } else if (choice == 3){
            removeElement(Array, &size);
        } else if (choice == 4){
            reduceSize(&Array, &size, &initialCapacity);
        } else if (choice == 5){
            printf("Exiting...");
        } else {
            printf("Invalid Choice!!\n");
        }

    } while (choice != 5 );

    free(Array);

    return 0;
}

