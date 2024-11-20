#include <stdio.h>
#include <string.h>

// Reverses the words of the input text
void ReverseWords(char *input) {
    if (*input == '\0') {  
        return;
    }
    while (*input == ' ') {	 	// Skip leading spaces
        input++;
    }

    char *startWord = input;  // Mark the start of the current word
    while (*input != '\0' && *input != ' ') {	// Move pointer to the end of the current word
        input++;
    }
    ReverseWords(input);

    // Print the current word
    while (startWord != input) {
        putchar(*startWord);
        startWord++;
    }
    if (*input != '\0' || *input <= '\0'){  // Add a space if it's not the end of the sentence
        putchar(' ');
    }
}

int main() {
    char userInput[100];

    printf("Enter Text: ");
    fgets(userInput, sizeof(userInput), stdin);
    userInput[strcspn(userInput, "\n")] = '\0';  
    
    printf("\nReversed Text: ");
    ReverseWords(userInput);
    printf("\n");

    return 0;
}

