#include<stdio.h>

struct Rectangle{
	float length, width;
};

int check(struct Rectangle info){
	if ((info.length >= 0.0 && info.length <= 20.0) && 
		((info.width >= 0.0 && info.width <= 20.0))){
		return 1;
	} else {
		return 0;
	}
}

void Parameter(struct Rectangle info){
	float parameter = ((2*(info.length))+(2*(info.width)));
	printf("Parameter of the rectangle: %.2f\n", parameter) ;
}

void Area(struct Rectangle info){
	float area = (info.length * info.width);
	printf("Area of the rectangle: %.2f", area) ;
}

int main(){
	struct Rectangle info;
	
	printf("Enter length: ");
	scanf("%f", &info.length);
	printf("Enter width: ");
	scanf("%f", &info.width);
	
	if(check(info)){
		Parameter(info);
		Area(info);
	} else {
		printf("Invalid!!");
	}
	return 0;
}


