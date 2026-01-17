#include <stdio.h>
#include <string.h>

// Function to count frequency of a letter (case-insensitive)
int charFrequency(char name[100], char letter) {
    int count = 0 , i;
    for( i = 0; i < strlen(name); i++) {
        if(name[i] == letter || name[i] == letter - 32 || name[i] == letter + 32) {
            count++;
        }
    }
    return count;
}

// Function to capitalize the first letter of each word
void upperCase(char name[100]) {
     int i;
    for( i = 0; i < strlen(name); i++) {
        if(i == 0 && name[i] >= 'a' && name[i] <= 'z')
            name[i] = name[i] - 32;
        else if(name[i-1] == ' ' && name[i] >= 'a' && name[i] <= 'z')
            name[i] = name[i] - 32;
    }
}

// Function to count consonants in the string
int countConst(char name[100]) {
    int count = 0 , i;
    for(i = 0; i < strlen(name); i++) {
        // Check if alphabet
        if((name[i] >= 'A' && name[i] <= 'Z') ||
           (name[i] >= 'a' && name[i] <= 'z')) {
            // Check NOT vowel
            if(name[i] != 'a' && name[i] != 'A' &&
               name[i] != 'e' && name[i] != 'E' &&
               name[i] != 'i' && name[i] != 'I' &&
               name[i] != 'o' && name[i] != 'O' &&
               name[i] != 'u' && name[i] != 'U') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char name[100];
    char letter;
    int result;

    // Input name
    printf("Enter Name: ");
    fgets(name, 100, stdin);

    // Remove newline character added by fgets
    if(name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    // Input letter to count
    printf("Enter Letter: ");
    scanf(" %c", &letter);

    // Count frequency of letter
    result = charFrequency(name, letter);
    printf("Letter '%c' appears: %d times\n", letter, result);

    // Capitalize first letter of each word
    upperCase(name);
    printf("Capitalized Name: %s\n", name);

    // Count consonants
    result = countConst(name);
    printf("Total consonants: %d\n", result);

    return 0;
}
