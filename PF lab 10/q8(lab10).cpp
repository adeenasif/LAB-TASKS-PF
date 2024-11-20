#include<stdio.h>

int ArrayElements(int *Array, int size){
	if(size == 0){
		return 0;
	}
	ArrayElements(Array, size-1);
	printf("%d ", Array[size-1]);
}

int main(){
	int size;
	
	printf("Enter size of the array: ");
	scanf("%d", &size);
	
	int Array[size];
	
	for (int i = 0; i < size; i++){
		printf("Enter array element[%d]: ", i+1);
		scanf("%d", &Array[i]);
	}
	
	printf("Array elements:\n");
	ArrayElements(Array, size);
	
	return 0;
}
