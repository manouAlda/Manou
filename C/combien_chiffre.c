#include <stdio.h>

int main(){
	printf("Le nombre composant d'un nombre\n");
	
	long n=0,count=0;
	printf("Entrez un nombre = ");
	scanf("%ld",&n);
	while (n!=0){
		n = n / 10;
		count++;
	}
	printf("\n\nDans ce nombre, il y a %ld chiffres\n",count);

	return 0;
}
