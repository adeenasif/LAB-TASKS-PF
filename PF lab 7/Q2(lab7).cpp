#include<stdio.h>
int main(){
	int Array[10];
	for (int i = 0; i<10; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &Array[i]);
	}
	int firstElement = Array[0];
	
	for (int i=0; i<10;i++){
		Array[i] = Array[i+1];
	}
	Array[9] = firstElement;
	
	printf("After shifting 1 unit to left: ");
	for(int i=0; i<10;i++){
		printf("%d ", Array[i]);
	}
	return 0;
}

