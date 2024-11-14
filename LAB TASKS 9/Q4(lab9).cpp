#include<stdio.h>
#include <string.h>
int main(){
	char Names[5][25] = {"Alice", "Harry", "Charlie", "Diana", "Eve"};
	char SearchName[10];
	int found = 0;
	
	printf("Enter a name to search: ");
	scanf("%s", SearchName);
	
	for (int i = 0; i < 5; i++){
		if (strcmp(SearchName, Names[i]) == 0){
			printf("Found!");
			found = 1;
			break;
		}	
	}
	
	if(found == 0){
		printf("Not Found!");
	}	
	return 0;
}

