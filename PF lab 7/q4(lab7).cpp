#include<stdio.h>
int main(){
	int sizeArray, sum;
	int Array[15];
	for (int i= 0; i< 15; i++){
		printf("Enter element %d : ", i+1);
		scanf("%d", &Array[i]);
	}
	sizeArray = sizeof(Array)/sizeof(Array[0]);
	for(int i =0; i<= sizeArray; i++){
		sum = sum + Array[i];
	}
	printf("Sum of all the elements are %d.", sum);
	return 0;
}

