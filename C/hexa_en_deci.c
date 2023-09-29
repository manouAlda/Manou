#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

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
		}
		
		decimal += val* pow(16, len);
		len--;
	}
	printf("\ndecimal = %d\n",decimal);
	
	return decimal;
}

int main(int argc, char **argv)
{
	char* hex = malloc(3);
	
	scanf("%s\n",hex);
	
	int c = hex_to_char(hex);
	
	return 0;
}

