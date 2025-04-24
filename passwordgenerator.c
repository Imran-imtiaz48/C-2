#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a password of length N
void generateRandomPassword(int N) 
{
    // Seed the random-number generator with the current time to ensure randomness
    srand((unsigned int)(time(NULL))); 

    // Arrays containing different character sets
    char numbers[] = "0123456789";
    char lowercase[] = "abcdefghijklmnoqprstuvwyzx";
    char uppercase[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    char symbols[] = "!@#$^&*?";

    // Array to store the generated password
    char password[N];

    // Randomizer variable to choose the character set
    int randomizer;

    // Generate password characters one by one
    for (int i = 0; i < N; i++) 
    { 
        randomizer = rand() % 4; // Randomly select a character set

        switch (randomizer) 
        {
            case 0: // Numbers
                password[i] = numbers[rand() % 10];
                break;
            case 1: // Symbols
                password[i] = symbols[rand() % 8];
                break;
            case 2: // Uppercase letters
                password[i] = uppercase[rand() % 26];
                break;
            case 3: // Lowercase letters
                password[i] = lowercase[rand() % 26];
                break;
        }

        // Print the current character
        printf("%c", password[i]);
    }

    printf("\n"); // Print a newline for better output formatting
}

// Driver Code
int main() 
{
    // Length of the password to be generated
    int passwordLength = 10;

    // Generate and print the random password
    generateRandomPassword(passwordLength);

    return 0; 
}
