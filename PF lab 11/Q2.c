#include<stdio.h>
#include<stdlib.h>

void evenArray(int *Array, int num){
    printf("The even elements of array:\n");
    for (int i = 0; i < num; i++){
        printf("%d\n", Array[i]);
    }
    free(Array);
}

int main(){
    int num;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);

    int *Array = (int *)malloc(num *sizeof(int));

    for (int i = 0; i < num; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &Array[i]);
    }
    for (int i = 0; i < num; i++){
        if (Array[i]%2 != 0){
            Array[i] -=1;    
        }
    }   
    evenArray(Array, num);
    free(Array);

    return 0;
}