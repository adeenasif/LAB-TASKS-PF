#include<stdio.h>
int main(){
	int Array[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
	int sumRow[3] = {0,0,0};
	int colRow[3] = {0,0,0};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Enter value Array[%d][%d]: ", i,j);
			scanf("%d", &Array[i][j]);
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			sumRow[i] = sumRow[i] + Array[i][j];
		}
	}
	
	for(int i = 0; i < 3; i++){
		printf("Sum of Row %d: %d \n", i+1, sumRow[i]);
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			colRow[i] = colRow[i] + Array[j][i];
		}
	}
	for(int i = 0; i < 3; i++){
		printf("Sum of column %d: %d \n", i+1, colRow[i]);
	}
	
	return 0;
}

