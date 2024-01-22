/* Passer un tableau à plusieurs dimensions à une fonction
au moyen d’un pointeur */

#include <stdio.h>
#include <stdlib.h>

void printarray_1(int (*ptr)[4]);
void printarray_2(int (*ptr)[4], int n);

int main() {
    int multi[3][4] = { {1, 2, 3, 4 },
                    {5, 6, 7, 8 },
                    {9, 10, 11, 12 } };

        /* ptr est un pointeur vers un tableau de 4 int. */
    int (*ptr)[4], count;
    /* Maintenant, ptr va pointer vers le premier élément de multi. */
    ptr = multi;
    
	printf("\nHere= %p  -  %p\n",multi, &multi[0]);	///Adresse du premier element
    
    /* A chaque tour de la boucle, ptr est incrémenté pour pointer
    sur l’élément suivant (le sous-tableau de 4 éléments). */
    for (count = 0; count < 3; count++)
         printarray_1(ptr++);

    puts("\n\nAppuyez sur Entrée...");

    getchar();

    printarray_2(multi, 3);

    printf("\n");
    exit(EXIT_SUCCESS);
}
void printarray_1(int (*ptr)[4])
{
    /* Affiche les éléments d’un tableau de 4 entiers.
    p est un pointeur de type int. Il est nécessaire
    de caster p pour qu’il soit égal à l’adresse
    contenue dans ptr. */
    int *p, count;
    p = (int *)ptr;
    for (count = 0; count < 4; count++)
        printf("\n%d", *p++);
}
void printarray_2(int (*ptr)[4], int n)
{
    /* Affiche les éléments d’un tableau d’entiers
    de n groupes de 4 éléments. */
    int *p, count;
    p = (int *)ptr;
    for (count = 0; count < (4 * n); count++)
        printf("\n%d", *p++);
}
