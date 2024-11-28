#include<stdio.h>

int main(){
    FILE *filePtr, *filePtr2;
    char fileData[50];
    filePtr = fopen("q3.txt", "r");
 	if (filePtr == NULL) {
        printf("file failed to open.");
        return 1;
    }
    
	char file2Data[50];
	filePtr2 = fopen("newq3.txt", "w");
	if (filePtr2 == NULL) {
        printf("file failed to open.");
    	fclose(filePtr);
        return 1;
    }
    
    while (fgets(fileData, 50, filePtr) != NULL) {
        fputs(fileData, filePtr2);
    }
    
	fclose(filePtr2);    
	printf("Data successfully read from file\n\n");
    
	filePtr2 = fopen("newq3.txt", "r");
	if (filePtr2 == NULL) {
        printf("file failed to open.");
    	fclose(filePtr);
        return 1;
    }
    
    while (fgets(file2Data, 50, filePtr2) != NULL) {
        printf("%s", file2Data);
    }
    
    fclose(filePtr);
	fclose(filePtr2);
    return 0;
}
