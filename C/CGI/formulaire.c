#include "formulaire.h"
#include <stdlib.h>

int hex_to_char(char* tab){
	int val=0, decimal=0;
	int len = strlen(tab)-1;
	
	for (int i=0; tab[i]!='\0'; i++){
		if(tab[i]>= '0' && tab[i]<='9'){
			val = tab[i]-48;
		}else if(tab[i]>'a' && tab[i]<'f'){
			val = tab[i]-97+10;
		}else if(tab[i]> 'A' && tab[i]<'F'){
			val = tab[i]-65+10;
		}else{
			return -1;
		}
		
		decimal += val* pow(16, len);
		len--;
	}
	
	return decimal;
}

char* withoutHex (char* tab){
	
	char* new = malloc(strlen(tab)+1);
	
	int i=0, j =0;
	char hex[4];
	char car;
	
	while(tab[i] != '\0'){
		if(tab[i]=='%' && tab[i+1] != '\0' && tab[i+2] != '\0'){
			snprintf(hex, sizeof(hex), "%c%c", tab[i+1], tab[i+2]);
			
			car = hex_to_char (hex);
			
			if(car != -1){
				new[j]=car;
				i+=3;
			} else{
				i += 3;
			}
		}
		else if(tab[i]=='%' &&  tab[i+1] != '\0' && tab[i+2] == '\0'){
			break;
		}
		else if(tab[i] == '+'){
			new[j]=' ';
			i+=1;
		}
		else{
			new[j] = tab[i];
			i++;
		}
		j++;
	}
	
	new[j]='\0';
	
	return new;
}


