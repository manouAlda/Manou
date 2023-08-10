#include <stdio.h>
#include <string.h>

int main(){
	char n[20];
	printf("Entrez un nombre a 12 chiffres maximum : ");
	scanf("%s",n);
	int pt =3;
	
	for( int j=0,i=j; j<=strlen(n)-1 ; j++){
		for (i=j; i<j+pt && i<strlen(n) ;i++){
			printf("%c",n[i]);
		}
	}
	
	//printf("\n %s\n",n);

	return 0;
}
