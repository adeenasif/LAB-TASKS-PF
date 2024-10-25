#include<stdio.h>
int main(){
	int Array[4][4] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("Enter marks[%d][%d]: ", i, j);
			scanf("%d", &Array[i][j]);
		}
	}
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(Array[i][j] < 0){
				Array[i][j] = 0;
			}
		}
	}
	printf("Correct Array: ");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ",Array[i][j]);
		}
	}
	return 0;
}
