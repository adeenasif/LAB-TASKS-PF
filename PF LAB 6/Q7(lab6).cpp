#include<stdio.h>
int main(){
	int num, digit, Temp, Sum = 0;
	printf("Enter number to check if it is armstrong or not: ");
	scanf("%d", &num);
	Temp = num;

   
    while (Temp!=0){
        digit = Temp % 10;
        Sum = Sum + (digit * digit * digit);
        Temp = Temp / 10;
    }
    if (Sum == num){
        printf("It is an Armstrong Number");
    }else{
        printf("It is not an Armstrong Number");
    }
    return 0;
}

