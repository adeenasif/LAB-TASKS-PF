#include<stdio.h>

int main()
{
    FILE* filePointer;
    char fileData[50];

    filePointer = fopen("sample.txt", "r");

    if (filePointer == NULL) {
        printf("sample file failed to open.");
    }
    else {
    	printf("Text written in the file: \n");
        while (fgets(fileData, 50, filePointer) != NULL) {
            printf("%s", fileData);
        }
        fclose(filePointer);
		printf("\n");
        printf("\nData successfully read from file\n");
    }
    return 0;
}
