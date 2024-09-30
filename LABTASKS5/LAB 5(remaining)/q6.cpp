#include<stdio.h>

int main() {
	int number;
	int n = 0;
	
	printf("Enter the number: ");
	scanf("%d", &number);
	if (number < 256){
		if (number & 1){
			n +=1;
		}
		if (number & 2){
			n+=1;
		}
		if (number & 4){
			n+=1;
		}
		 if (number & 8) {
	        n += 1;  
	    }
	    if (number & 16) {
	        n += 1;  
	    }
	    if (number & 32) {
	        n += 1;  
	    }
	    if (number & 64){
			n+=1;
	}
	    if (number & 128) {
	        n += 1; 
	    }
		printf("Number %d conatins %d ones in the binary representation. ", number, n);
	}else{
		printf("The program only works for 8bit binary system, please enter a number less than 256!");
	}
	return 0;
}

