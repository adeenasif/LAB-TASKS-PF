#include<stdio.h>
int main(){
	int Array[20];
	for (int i= 0; i<= 20; i++){
		printf("Enter element %d : ", i+1);
		scanf("%d", &Array[i]);
	}
	printf("Reverse Order: ");
	for (int i= 20; i >= 0; i--){
		printf("%d, ", Array[i]);
	}
	return 0;
}
