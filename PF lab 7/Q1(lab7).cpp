#include<stdio.h>
int main(){
	int Array[] = {1,1,1,1,1,1,5,1,1,1,1,1};
	int Num, Numfound = 0;
	printf("Enter integer to search: ");
	scanf("%d", &Num);
	
	for(int i = 0; i< 12 ;i++){
		if (Array[i] == Num){
			printf("%d found at index %d", Num, i+1);
			Numfound = 1;
			break;
		}else{
			Numfound = 0;
		}
	}
	if (Numfound != 1){
		printf("Number not found!");
	}
	return 0;
}
