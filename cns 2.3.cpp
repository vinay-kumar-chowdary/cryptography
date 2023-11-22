#include <stdio.h>


int areCoprime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}


void findAllowedValuesForA() {
    int m = 26; 

    printf("Allowed values for 'a': ");
    for (int a = 1; a < m; a++) {
        if (areCoprime(a, m)) {
            printf("%d ", a);
        }
    }
    printf("\n");
}

int main() {
   
    findAllowedValuesForA();

    return 0;
}

