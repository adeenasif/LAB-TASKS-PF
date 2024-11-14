#include <stdio.h>

int Pattern(int n){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            printf("%d", j);
        }
        for(int j = i-1; j >=1; j--){
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}

int main(){
    int Num;
    printf("Enter number to get the pattern: ");
    scanf("%d", &Num);
    Pattern(Num);
    return 0;
}
