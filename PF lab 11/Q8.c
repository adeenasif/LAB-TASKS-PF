#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    float total;
    printf("Enter the total number of points in the facility: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Invalid input! The number of points must be greater than 0.\n");
        return 1;
    }

    int *Array = (int *)malloc(num *sizeof(int));
    if (Array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for(int i = 0; i < num; i++){
        printf("Enter fee for point %d: ", i+1);
        scanf("%d", &Array[i]);
        // reject negative fees
        if (Array[i] < 0) {
            printf("Fee cannot be negative!! Enter the fee for point %d again: ", i+1);
            scanf("%d", &Array[i]);
        }
    }
    for(int i = 0; i < num; i++){
        total = total + (float)Array[i];
    }

    printf("Total Profit for the facility: $%.2f",total);
    free(Array);
    return 0;
}