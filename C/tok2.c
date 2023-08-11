#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "manou:L1:mit:/bin/bash:/home/Manou";
    const char delim[] = ":";

    char *token;
    char *next_token = str;

    while ((token = strtok(next_token, delim)) != NULL) {
        printf("%s\n", token);
        next_token = NULL; // Pour les appels suivants, utiliser le pointeur interne
    }

    return 0;
}
