#include<stdio.h>
#include<stdlib.h>

int main(){
    int num;
    printf("Enter the total number of elements(1-100): ");
    scanf("%d", &num);
    if (num < 1 || num > 100) {
        printf("Please enter a number between 1 and 100!!");
        return 1;
    }

    int *Array = (int*)malloc(num * sizeof(int));
    if (Array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < num; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &Array[i]);
    }
    
    int max;
    for (int i = 0; i < num; i++){
        max = Array[i];
        for (int j = 0; j < num; j++){
            if(Array[j] > max){
                max = Array[j];
            }
        }
    }
    printf("Largest element in the array: %d", max);
    free(Array);
    return 0;
}