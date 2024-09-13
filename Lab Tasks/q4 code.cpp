#include<stdio.h>
int main(){
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	
	switch(n) {
		case 1:
			printf("The number %d is one.", n);
			break;
		case 2:
			printf("The number %d is two.", n);
			break;
		case 3:
			printf("The number %d is three.", n);
			break;
		case 4:
			printf("The number %d is four.", n);
			break;
		case 5:
			printf("The number %d is five.", n);
			break;
		case 6:
			printf("The number %d is six.", n);
			break;
		case 7:
			printf("The number %d is seven.", n);
			break;
		case 8:
			printf("The number %d is eight.", n);
			break;
		case 9:
			printf("The number %d is nine.", n);
			break;
		case 10:
			printf("The number %d is ten.", n);
			break;
		case 11:
			printf("The number %d is eleven.", n);
			break;
		case 12:
			printf("The number %d is twelve.", n);
			break;
		case 13:
			printf("The number %d is thirteen.", n);
			break;
		case 14:
			printf("The number %d is fouteen.", n);
			break;
		case 15:
			printf("The number %d is fiveteen.", n);
			break;
		case 16:
			printf("The number %d is sixteen", n);
			break;
		case 17:
			printf("The number %d is seventeen.", n);
			break;
		case 18:
			printf("The number %d is eighteen.", n);
			break;
		case 19:
			printf("The number %d is nineteen.", n);
			break;
		case 20:
			printf("The number %d is twenty.", n);
			break;
		default:
			printf("Number is greater than 20");
	}
	return 0;
}
