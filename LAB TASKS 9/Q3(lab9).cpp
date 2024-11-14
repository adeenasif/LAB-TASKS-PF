#include<stdio.h>
#include<string.h>
int main(){
	char username[] = {"admin"}, password[] = {"1234"};
	char user[5], pass[5];
	
	printf("Enter username: ");
	scanf("%s", user);
	
	printf("Enter password: ");
	scanf("%s", pass);
	
	if((strcmp(username, user) == 0) && ((strcmp(password, pass) == 0))){
		printf("Access Granted!");
	} else{
		printf("Access Denied!");
	}
	return 0;
}

