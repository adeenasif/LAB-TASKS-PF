#include<stdio.h>
int main(){
	int temp = 0, Score[4][4];
	
	for (int i = 0; i < 4; i++){ 
		for (int j = 0; j < 4; j++){ 
			printf("Enter score of team %d for round %d: ", i+1, j+1);
			scanf("%d", &Score[i][j]);
		}
	}
	printf("Before sorting: \n");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%d ", Score[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int j = 0; j < 4; j++) {  
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 3 - i; k++) {
                if (Score[k][j] > Score[k + 1][j]) {
                    temp = Score[k][j];
                    Score[k][j] = Score[k + 1][j];
                    Score[k + 1][j] = temp;
                }
            }
        }
    }
	printf("Sorted according to teams score for each round\n");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%d ", Score[i][j]);
		}
		printf("\n");
	}
	return 0;
}
