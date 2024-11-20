#include<stdio.h>

void BubbleSort(int *Array, int size){
	if(size == 0){  
		return ;
	}
	for (int i = 0; i < size; i++){
		if(Array[i] > Array[i+1]){  
			int temp = Array[i];
			Array[i]= Array[i+1];
			Array[i+1] = temp;
		}
	}
	BubbleSort(Array, size-1);	
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
	
	printf("Sorted array:\n");
	BubbleSort(Array, size);
	return 0;
}
