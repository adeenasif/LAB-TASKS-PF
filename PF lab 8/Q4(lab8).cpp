#include<stdio.h>
int main(){
	int m, n;
	printf("Enter the m(rows): ");
	scanf("%d", &m);
	printf("Enter the n(columns): ");
	scanf("%d", &n);
	
	int matrix1[m][n], matrix2[m][n], sum[m][n];

	printf("Enter Data Of The First Matrix \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("Enter Data [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrix1[i][j]);
		}
	}
	printf("Enter Data Of The Second Matrix: \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("Enter Data [%d][%d]: ", i+1, j+1);
			scanf("%d", &matrix2[i][j]);
		}
	}	
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	printf("Resultant Matrix After Addition: \n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	return 0;
}
