#include <stdio.h>

int main() {
    // Déclaration du tableau de 12 x 12 caractères
    char tableau[12][12];

    // Initialisation du tableau avec des 'X'
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            tableau[i][j] = 'X';
        }
    }

    // Affichage du tableau en utilisant un pointeur
    char (*pointeur)[12] = tableau; // Pointeur vers le tableau

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            printf("%c ", *(*(pointeur + i) + j));
        }
        printf("\n");
    }

    return 0;
}
