#include <stdio.h>
#include <stdlib.h>

struct entry {
    char fnom[20];
    char last_name[20];
    char phone[10];
};

int main() {
    struct list[4];

    /* Boucle d’enregistrement de 4 personnes. */
    for (int i = 0; i < 4; i++) {
        printf("\nEntrez le nom : ");
        scanf("%20s", list[i].fnom);
        printf("Entrez le prénom : ");
        scanf("%20s", list[i].last_name);
        printf("Entrez le numéro de téléphone (xxxxxxxx) : ");
        scanf("%10s", list[i].phone);
    }
    
    printf("\n\n");
    /* Affichage des données. */
    for (int i = 0; i < 4; i++) {
        printf("Nom : %s %s", list[i].last_name, list[i].fnom);
        printf("\t\tPhone: %s\n", list[i].phone);
    }

    return 0;
}
