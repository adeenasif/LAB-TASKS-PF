#include<stdio.h>
#include<stdlib.h>

int main(){
    int rows, col;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int **arr = (int **)malloc(rows * sizeof(int *));  // Allocate memory for the rows

    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(col * sizeof(int)); // Allocate memory for each column
    }

    printf("Initializing the 2D array!\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = i * col + j + 1; // Assigning a unique value based on position
        }
    }

    //Modifying a value in the array using a double pointer
    int modifyRow = 1;
    int modifyCol = 2;
    printf("\nModifying value at arr[%d][%d] to 999 .\n", modifyRow, modifyCol);
    arr[modifyRow][modifyCol] = 999;

    printf("\nArray after modification:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]); // Free each row
    }
    free(arr); 
    return 0;
}