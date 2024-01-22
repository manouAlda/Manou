#include <stdio.h>
#include <stdlib.h>

struct coord{
    int x;
    int y;
};

struct rectangle{
    struct coord hautgauche;
    struct coord basdroit;
} maboite;

int main() {
    int longueur, largeur;
    long aire;

    printf("\nEntrez la coordonnée x du coin supérieur gauche : ");
    scanf("%d", &maboite.hautgauche.x);
    printf("\nEntrez la coordonnée y du coin supérieur gauche : ");
    scanf("%d", &maboite.hautgauche.y);
    printf("\nEntrez la coordonnée x du coin inférieur droit : ");
    scanf("%d", &maboite.basdroit.x);
    printf("\nEntrez la coordonnée y du coin inférieur droit : ");
    scanf("%d", &maboite.basdroit.y);

    /* Calcul de la longueur et de la largeur */
    largeur = maboite.basdroit.x - maboite.hautgauche.x;
    longueur = maboite.basdroit.y - maboite.hautgauche.y;

    /* Calcul et affichage de l’aire */
    aire = largeur * longueur;
    printf("\nL’aire du rectangle est de %ld unités.\n", aire);

    exit(EXIT_SUCCESS);
}
