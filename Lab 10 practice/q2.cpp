#include <stdio.h>

void maxCut(int length, int *length3, int *length2, int *length1) {
    if (length == 0) {
        return;
    } else if (length >= 3) {
        (*length3)++;
        maxCut(length - 3, length3, length2, length1);
    } else if (length >= 2) {
        (*length2)++;
        maxCut(length - 2, length3, length2, length1);
    } else if (length >= 1) {
        (*length1)++;
        maxCut(length - 1, length3, length2, length1);
    }
}

int main() {
    int length, Sum;
    printf("Enter the length of the rope: ");
    scanf("%d", &length);
    int length1 = 0, length2 = 0, length3 = 0;

    maxCut(length, &length3, &length2, &length1);
    Sum = length1 + length2 + length3;
    printf("\nMax no. of pieces that rope can be cut into is: %d\n", Sum);
    printf("3unit length cuts: %d\n", length3);
    printf("2unit length cuts: %d\n", length2);
    printf("1unit length cuts: %d\n", length1);
    return 0;
}

