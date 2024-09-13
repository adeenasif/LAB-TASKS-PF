#include<stdio.h>
int main(){
	int score;
	
	printf("Enter score: ");
	scanf("%d", &score);
	
	if (score >= 90 && score <= 100) {
		printf("A Grade");
	}else if (score >= 80 && score <= 89) {
		printf("B Grade");
	}else if (score >= 70 && score <= 79) {
		printf("C Grade");
	}else if (score >= 60 && score <= 69) {
		printf("D Grade");
	}else if (score < 60) {
		printf("F Grade");
	}
	return 0;
}
