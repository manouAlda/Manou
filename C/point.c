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

char* decimalToBinary(int tmp) {
	int final=0,t=0;
	char* tab = malloc(15);
	int cp = tmp;
	
	while(cp!=0){
		cp/=2;
		final++;
	}
	int* tmp2 = malloc(sizeof(int)*final);
	
    for(int i=0;i<final;i++){
		t = tmp/2;
		tmp2[i]= tmp%2;
		tmp = t;	
		printf("tmp2b  %d : %d\n",i,tmp2[i]);
		
    }
    printf("tableau : %s\n",tab);
    
    return tab;
}

char* binary (char* mask){
	char* bin = malloc(10);
	int tmp=0;
	
	tmp = atoi(mask);
	printf("\ntmp = %d\n",tmp);
	
	bin = decimalToBinary(tmp);
	
	printf("\nbinary = %s\n",bin);
	
	return bin;
}
char* adresse_reseau(char* octet){
	char* adress = malloc(50);
	int two_pow[8] = {128,64,32,16,8,4,2,1};
	int reseau=0;
	
	for(int i=0;i<strlen(octet);i++){
		if(octet[i]=='1'){
			reseau += two_pow[i]; 
		}
	}
	sprintf(adress,"%d",reseau);
	strcat(adress,".");
	printf("adresse reseau : %s\n",adress);
	
	return adress;
}

int main() {
    char chaineOriginale[1000];
    char chaineModifiee[2000];  // La chaîne modifiée peut être plus longue
    
    printf("Entrez une chaîne de caractères : ");
    fgets(chaineOriginale, sizeof(chaineOriginale), stdin);
    chaineOriginale[strcspn(chaineOriginale, "\n")] = '\0';  // Supprimer le saut de ligne
    
    int test=0;
    test = testons(chaineOriginale);

    if(test==0){
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
    }
    
    else if(test>=3){
    	printf("\nipV4 trouve\n");
    }
    else{
    	printf("\n ip inexistant\n");
    }
    
    /// Adresse du resseau
    char* masque = malloc(100);
    char* octet1 = malloc(10);
    char* octet2 = malloc(10);
    char* octet3 = malloc(10);
    char* octet4 = malloc(10);
    
    printf("Entrez le masque du sous reseau : ");
    fgets(masque,100,stdin);
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
    
    char* adresse = malloc(50);
    adresse = adresse_reseau(octet1);
    
    return 0;
}
