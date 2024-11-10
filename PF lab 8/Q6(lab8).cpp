#include<stdio.h>
int main(){
	int length;
	printf("Enter length: ");
	scanf("%d", &length);
	int midpoint = length/2;
  	
	for (int i = 0; i < length ; i++) {	
    	for (int j = 0;j < length; j++) {
        	if(i == 0 || j == length-1 || j == 0 || i == length-1) {
                printf("*");
            }else if(i == midpoint && j == midpoint){
            	printf("*");
			}else if (i == j){
                printf("*");
            }else if((i+j)==length-1){
                printf("*");
            }else{
                printf(" ");
            } 
        }printf("\n"); 	
	}
	return 0;
}


