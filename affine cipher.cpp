#include <stdio.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; 
}

void decryptAffineCipher(int a, int b, char *ciphertext) {
    int m = 26; 
    int aInverse = modInverse(a, m);

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = ciphertext[i];
            char decryptedChar;

            if (islower(ch)) {
                decryptedChar = 'a' + (aInverse * (ch - 'a' - b + m)) % m;
            } else {
                decryptedChar = 'A' + (aInverse * (ch - 'A' - b + m)) % m;
            }

            printf("%c", decryptedChar);
        } else {
            printf("%c", ciphertext[i]); 
        }
    }
    printf("\n");
}

int main() {
   
    char mostFrequent = 'B';
    char secondMostFrequent = 'U';

   
    int m = 26; 
    int a = (mostFrequent - secondMostFrequent + m) % m;
    int b = (mostFrequent - 'A' - a * ('U' - 'A' + m)) % m;

    
    char ciphertext[] = "YourCiphertextHere";
    decryptAffineCipher(a, b, ciphertext);

    return 0;
}

