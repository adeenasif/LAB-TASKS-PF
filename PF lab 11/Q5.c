#include<stdio.h>
#include <stdlib.h>

void insert(int **arr, int *n, int x, int pos) {
    *arr = realloc(*arr, (*n + 1) * sizeof(int));
    for (int i = *n - 1; i >= pos; i--) {
        (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[pos] = x;
    (*n)++;
}

void delete(int **arr, int *n, int pos) {
    if (*n == 1) {
        free(*arr);
        *arr = NULL;
        (*n)--;
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = realloc(*arr, (*n - 1) * sizeof(int));
    (*n)--;
}

int main(){
    int T, N;
    // printf("Enter the number of elements to be stored in array: ");
    scanf("%d", &N);

    int *Array = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        // printf("Enter element %d: ", i + 1);
        scanf("%d", &Array[i]);
    }

    // printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        char choice;
        int position, value;
        // printf("Enter your choice (I/D): ");
        getchar(); // Clear the newline character from the input buffer
        scanf("%c", &choice);

        if (choice == 'I') {
            // printf("Enter position and value to insert: ");
            scanf("%d %d", &position, &value);
            if (position - 1 >= 0 && position - 1 <= N) { // adjust for 0-based index
                insert(&Array, &N, value, position - 1);
                // print elements after insertion
                for (int i = 0; i < N; i++) {
                    printf("%d ", Array[i]);
                }
                printf("\n");
            } else {
                printf("Invalid position for insertion!\n");
            }
        } else if (choice == 'D'){
            int position;
            scanf("%d", &position);
            if (position - 1 >= 0 && position - 1 < N ) { // Adjust for 0-based index
                delete(&Array, &N, position - 1);
                // print elements after deletion
                if (N > 0) {
                    for (int i = 0; i < N; i++) {
                        printf("%d ", Array[i]);
                    }
                } else {
                    printf("Array is empty.");
                }
                printf("\n");
            } else {
                printf("Invalid position for deletion!\n");
            }
        } else{
            printf("INVALID OPTION");
        }
    }
    free(Array);
    return 0;
}