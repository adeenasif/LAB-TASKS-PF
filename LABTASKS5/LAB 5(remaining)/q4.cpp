#include<stdio.h>
int main(){
	float Amount;
	int MembershipStatus = 0;
	
	printf("Enter your total purchase amount: ");
	scanf("%f", &Amount);
	printf("Enter 1 if you have membership and 0 if you do not have membership: ");
	scanf("%d", &MembershipStatus);
	
	(Amount > 100 && MembershipStatus == 1)? printf("Eligible for discount!"): printf("Not Eligible!");
	return 0;
}

