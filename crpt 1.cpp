#include <stdio.h>
#include <string.h>

// Function to perform Caesar cipher encryption
void encrypt(char message[], int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        // Check if the character is a letter
        if (isalpha(message[i])) {
            // Determine whether the letter is uppercase or lowercase
            char base = (isupper(message[i])) ? 'A' : 'a';
            
            // Apply the Caesar cipher formula
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

int main() {
    char message[100];

    // Input the message to be encrypted
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Iterate through each key in the range 1 through 25
    for (int key = 1; key <= 25; key++) {
        // Make a copy of the original message for each key
        char encryptedMessage[100];
        strcpy(encryptedMessage, message);

        // Encrypt the message with the current key
        encrypt(encryptedMessage, key);

        // Display the encrypted message for the current key
        printf("Encrypted message with key %d: %s", key, encryptedMessage);
    }

    return 0;
}

