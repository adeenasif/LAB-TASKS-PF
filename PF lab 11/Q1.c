#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int num, grades;
    int **Grades;

    printf("Enter the number of students: ");
	scanf("%d", &num);
	
    Grades = (int **)malloc(num * sizeof(int *));
    if (Grades == NULL) {
        printf("Memory allocation failed for students!");
        return 1;
    }
	for (int i = 0; i < num; i++){
		
		printf("Enter the number of grades for student %d: ", i+1);
		scanf("%d", &grades);
		Grades[i] = (int *)malloc(grades * sizeof(int));
        if (Grades[i] == NULL) {
            printf("Memory allocation failed for Grades!");
            return 1;
        }
		
        printf("Enter grade for student %d:\n",i+1);
		for (int j = 0; j < grades; j++){
			printf("Grade %d: ", j+1);
			scanf("%d", &Grades[i][j]);
		}
	}
	
	printf("\nEntered Grades:\n");
    for (int i = 0; i < num; i++) {
        printf("Student %d Grades: ", i + 1);
        for (int j = 0; j < grades; j++) {
            printf("%d ", Grades[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < num; i++) {
        free(Grades[i]);
    }
    free(Grades);
	
	return 0;
}