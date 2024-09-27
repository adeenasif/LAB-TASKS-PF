#include<stdio.h>

int main(){
	int angle1;
	int angle2;
	int angle3;
	int Sum;
	
	printf("Enter the three angles of the triangle: ");
	scanf("%d, %d, %d", &angle1, &angle2, &angle3);
	if (angle1 > 0 && angle2 > 0 && angle3 > 0) {
		Sum = angle1 + angle2 + angle3;
		if (Sum == 180){
			printf("It is a triangle!");
		} else{
			printf("It is not a triangle!");
		}
	}else {
		printf("Invalid Values Entered!");
	}
	return 0;
	
}
