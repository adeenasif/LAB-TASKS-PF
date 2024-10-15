#include<stdio.h>
int main(){
	int Array[12];
	
	for (int i = 0, i< 12, i++){
		printf("Enter element %d", i);
		scanf("%d", &Array[i]);
	}
	
	return 0;
}
