#include<stdio.h>
int main(){
	int Maximum, Minimum;
	int Array[30];
	for (int i= 0; i<= 30; i++){
		printf("Enter element %d : ", i+1);
		scanf("%d", &Array[i]);
	}
	Maximum = Minimum = Array[0];
	
	for(int i = 1; i< 30; i++){
		if (Array[i] > Maximum){
			Maximum = Array[i];
		}else if (Array[i] < Minimum){
			Minimum = Array[i];
		}
	}
	printf("Minimum number in the array: %d\n", Minimum);
	printf("Maximum number in the array: %d", Maximum);
	return 0;
}
