#include<stdio.h>

int Percentage(int value, int i) {
	if (i > 100) {  
        return 0;
    }
    
    float Percent = value * (i / 100.0);
    printf("%d Percent = %.2f\n", i, Percent);
	
	Percentage(value, i + 1);
}

int main(){
	int value;
	printf("Enter a value to split in percentage: ");
	scanf("%d", &value);
	Percentage(value, 1);
	return 0;	
}


