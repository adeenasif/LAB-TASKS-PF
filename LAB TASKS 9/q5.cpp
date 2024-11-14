//code for Vigenere Cipher (encryption)

#include<stdio.h>
#include<strings.h>

int main(){
	char plainText[100], key[100];
	
	printf("Enter the text to encrypt: ");
	fgets(plainText, 100, stdin);
	printf("Enter the key: ");
	fgets(key, 100, stdin);
	
	plainText[strcspn(plainText, "\n")] = '\0';
	key[strcspn(key, "\n")] = '\0';
	
	printf("\n");
	printf("Plain Text: %s\n", plainText);
	printf("Key: %s\n", key);
	
	int keyLength = strlen(key), textLength = strlen(plainText);
	
	int asciiText[textLength], asciiKey[keyLength];
	
	for (int i = 0; i < textLength; i++) {	//converting plain text into ascii values
		if((int)plainText[i] == 32){
			asciiText[i] = 20;
		} else {
			asciiText[i] = (int)plainText[i];
		}
	}
	
	for (int i = 0; i < keyLength; i++) {	//converting key into ascii values
		if((int)key[i] == 32){
			asciiKey[i] = 20;
		} else {
			asciiKey[i] = (int)key[i];		
		}
	}	
	
	for(int i = 0; i < textLength; i++) {	//printing the ascii value of plain text
		printf("%d ", asciiText[i]);
	}
	printf("\n");
	for(int i = 0; i < keyLength; i++) {	//printing the ascii value of key
		printf("%d ", asciiKey[i]);
	}
	
	for (int i = 0; i < textLength; i++) {  //subtracting 64 from the plain text
		if(asciiText[i] != 20){
			asciiText[i] = asciiText[i] - 64;
		}
	}
		
	for (int i = 0; i < keyLength; i++) {  //subtracting 64 from key
		if(asciiKey[i] != 20){
			asciiKey[i] = asciiKey[i] - 64;
		}
	}
	
	int j = 0, sum[textLength]; //adding the values vertically
	for (int i = 0; i < textLength; i++) {
		sum[i] = asciiText[i] + asciiKey[j];
		j++;
		if(j == keyLength){
			j = 0;
		}
	}
	
	printf("\n");printf("\n");
	printf("After subracting 64 from each value & adding the values vertically:\n");
	for(int i = 0; i < textLength; i++) {
		printf("%d ", sum[i]);
	}
	
	for(int i = 0; i < textLength; i++) { //taking mod 26
		sum[i] = sum[i]%26;
	}
	
	printf("\n");printf("\n");
	printf("After taking modulo by 26: \n");
	for(int i = 0; i < textLength; i++){
		printf("%d ", sum[i]);
	}
	 
	int Cipher[textLength]; 
		
	for (int i = 0; i < textLength; i++) {  //adding 64 	
		Cipher[i] = sum[i] + 64;
	}
	
	printf("\n");printf("\n");
	printf("Final Cipher values: \n");
	
	for(int i = 0; i < textLength; i++) {
		printf("%d ", Cipher[i]);
	}
	
	char CipherText[textLength];
	for (int i = 0; i < textLength; i++) { 			
		CipherText[i] = (char)Cipher[i];	// convert ascii to string
	}
	
	printf("\n");printf("\n");
	printf("Finally, our cipher text would be:\n");
	for (int i = 0; i < textLength; i++) {			
		printf("%c ", CipherText[i]);									
	}
	return 0;	
}

