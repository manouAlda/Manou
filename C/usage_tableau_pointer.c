#include <stdio.h>
#include <stdlib.h>

#define N 10

// Fonction de comparaison utilisée par qsort
int comparaison_pointeurs(const void *a, const void *b) {
/// Comparer les pointeurs et non les valeurs 
    const double *double_a = *(const double**)a;
    const double *double_b = *(const double**)b;

    if (*double_a < *double_b) return -1;
    if (*double_a > *double_b) return 1;
    return 0;
}


int main() {
    double *pointeurs[N]; // Tableau de pointeurs vers des variables de type double
    double nombres[N];    // Tableau pour stocker les nombres

    // Saisie des nombres par l'utilisateur
    printf("Entrez dix nombres :\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &nombres[i]);
        pointeurs[i] = &nombres[i]; // Affectation des adresses des nombres aux pointeurs
    }

    // Tri des pointeurs en utilisant qsort
    qsort(pointeurs, N, sizeof(double*), comparaison_pointeurs);

    // Affichage des nombres triés
    printf("\nNombres triés :\n");
    for (int i = 0; i < N; i++) {
        printf("%lf\n", *pointeurs[i]);
    }

    return 0;
}
