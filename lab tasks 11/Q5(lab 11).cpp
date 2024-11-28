#include<stdio.h>

struct Number{
	int areaCode, exchange, num;
};

int main(){
	struct Number myInfo = {212,767, 8900};
	struct Number info;
	
	printf("Enter area code: ");
	scanf("%d", &info.areaCode);
	printf("Enter exchange: ");
	scanf("%d", &info.exchange);
	printf("Enter number: ");
	scanf("%d", &info.num );
	
	printf("My number is (%d) %d-%d\n", myInfo.areaCode, myInfo.exchange, myInfo.num);
	printf("Your number is (%d) %d-%d", info.areaCode, info.exchange, info.num);
	return 0;
}
