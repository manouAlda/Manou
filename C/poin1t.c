#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int testons (char* ip){
	int count=0;
	for(int i=0;i<strlen(ip);i++){
		if(*(ip+i)=='.'){
			count++;
		}
	}
	return count;
}
int nombre (int n){
	int s=0,count =0;
	
	while(n!=0)
	{
		s /=2;
		n =s;
		count++;
	}

	return count;
}

int* decimalToBinary(int n) {
	int i=0;
	int* tab = malloc(15);
    if (n > 0) {
    	int tmp = n/2;
        tab[i++]= n%2;
        n=tmp;
        printf("%d  = %d\n",i,tab[i]);
    }
    return tab;
}	

int if_ip (char* tab){
	int turn=1;
	int a=0,c=0,b=0,d=0;
	sscanf(tab,"%d.%d.%d.%d",&a,&c,&b,&d);
	
	printf("\n%d,%d,%d,%d\n",a,c,b,d);
	int t=0;
	if(a>255 || c>255 || b>255 || d>255){
		turn=0;
	}
	else if(a<=255 && c<=255 && b<=255 && d<=255){
		turn=1;
	}
		
	return turn;
}

char* binary (char* mask){
	char* bin = malloc(10);
	int tmp=0;
	
	tmp = atoi(mask);
	printf("\ntmp = %d\n",tmp);
	
	//bin = decimalToBinary(tmp);
	
	return bin;
}

int main() {
    char chaineOriginale[1000];
    char chaineModifiee[2000];  // La chaîne modifiée peut être plus longue
    char* mask = malloc(50);
    
    printf("Entrez l'adresse IP : ");
    fgets(chaineOriginale, sizeof(chaineOriginale), stdin);
    chaineOriginale[strcspn(chaineOriginale, "\n")] = '\0';  // Supprimer le saut de ligne
    printf("Entrez le mask bits: ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = '\0';
    
    int test=0;
    test = testons(chaineOriginale);

    if(test==0 || test==1 || test==2){
	   	 int longueur = strlen(chaineOriginale);
	    int index_modifie = 0;
	
	    for (int i = 0; i < longueur; i++) {
	        chaineModifiee[index_modifie++] = chaineOriginale[i];
	        if ((i + 1) % 3 == 0 && i != longueur - 1) {
	            chaineModifiee[index_modifie++] = '.';
	        }
	    }
	    chaineModifiee[index_modifie] = '\0';  // Terminer la chaîne modifiée
	
	    printf("Chaîne modifiée : %s\n", chaineModifiee);
	    strcpy(chaineOriginale,chaineModifiee);
    }
    
    else if(test==3 || test==4){
    	test = if_ip(chaineOriginale);
    	if(test==1) printf("IPV4 trouve\n");
    	else if(test==0){
    		printf("erreur, ce n'est pas une adresse ip\n");
    	}
    }
    /*
    else{
    	printf("\n ip inexistant\n");
    }
    
    /// Adresse du resseau
    char* masque = malloc(100);
    char* octet1 = malloc(10);
    char* octet2 = malloc(10);
    char* octet3 = malloc(10);
    char* octet4 = malloc(10);
    
    fgets(masque,100,stdin);
    printf("Entrez le masque du sous reseau : ");
    masque[strlen(masque)-1]='\0';
    
    printf("\n Masque du SR : %s\n",masque);
    
    sscanf(masque,"%[^.].%[^.].%[^.].%[^\n]",octet1,octet2,octet3,octet4);
    
    printf("\n1 = %s\n",octet1);
    printf("\n2 = %s\n",octet2);
    printf("\n3 = %s\n",octet3);
    printf("\n4 = %s\n",octet4);

    octet1 = binary(octet1);
    octet2 = binary(octet2);
    octet3 = binary(octet3);
    octet4 = binary(octet4);
    /*
    char* sr = malloc(50);
    for(int i=0;i<strlen(octet1);i++){
    	if
    }*/
    
    return 0;
}
