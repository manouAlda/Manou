#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intToBinary(int n, char *binaryString) {
    int index = 0;
    while (n > 0) {
        binaryString[index++] = (n % 2) + '0';
        n /= 2;
    }
    binaryString[index] = '\0';
    
    // Reverse the binary string
    int len = strlen(binaryString);
    for (int i = 0; i < len / 2; i++) {
        char temp = binaryString[i];
        binaryString[i] = binaryString[len - i - 1];
        binaryString[len - i - 1] = temp;
    }
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Calculate the maximum size of the binary string
    int maxBinarySize = sizeof(int) * 8 + 1;
    char *binaryString = (char *)malloc(maxBinarySize);

    if (binaryString == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    intToBinary(num, binaryString);
    printf("Binary representation: %s\n", binaryString);

    // Don't forget to free the allocated memory
    free(binaryString);

    return 0;
}
