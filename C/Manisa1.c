///ity ny programme manisa*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ascii(char car);
char** Separer(int isa);
int CharTOInt (int ligne,char** tap);
char** alloue2DChar(int taille);
int isanJavatra(int isa);
char* Unite(int isa);
char* Dizaine(int isa);
char* Centaine(int isa);
char* Arivo(int isa);
char* Alina(int isa);
char* Hetsy(int isa);
char* Valiny(int isa);
char* Tapitrisa(int isa);

int main (){
	int isa=1109542321;
	//char* lettre=malloc(5000);
	//lettre=Valiny(isa);
	//printf(" %d = %s\n",isa,lettre);
	
	//Separer(isa);
	Tapitrisa(isa);
	return 0;
}
char* Valiny(int isa){
	int isanyNbr=0;
	char* valiny=malloc(1000);
	isanyNbr=isanJavatra(isa);
		if(isanyNbr==1)
			valiny=Unite( isa);
		else if(isanyNbr==2)
			valiny=Dizaine(isa);
		else if(isanyNbr==3)
			valiny=Centaine(isa);	
		else if(isanyNbr==4)
			valiny=Arivo(isa);
		else if(isanyNbr==5)
			valiny=Alina(isa);
		else if(isanyNbr==6)
			valiny=Hetsy(isa);
		else if(isanyNbr==1){
			valiny=Dizaine(isa);
		}
		return valiny;
}				
int isanJavatra(int isa){
	char* ind=malloc(60);
	int nbr=0;
	
	sprintf(ind,"%d",isa);
	nbr=strlen(ind);
	return nbr;
}		
char* Unite(int isa){
	char unite[11][10]={"","iray","roa","telo","efatra","dimy","enina","fito","valo","sivy"};
	char* lettre=malloc(20);
	char zero[6]="aotra";
	if(isa==0)
	sprintf(lettre,"%s",zero);
	else
	sprintf(lettre,"%s",unite[isa]);
	return lettre;
	
}	
char* Dizaine(int isa){
	char diz[11][20]={"","folo","roapolo","telopolo","efapolo","dimampolo","enimpolo","fitopolo","valopolo","sivifolo"};
	char* lettre=malloc(60);
	if(isa%10==0){
		sprintf(lettre,"%s",diz[isa/10]);
	}	
	else if(isa%10!=0){
		int tmp=(isa%10);
			if(isa>=11 && isa<=19)
			sprintf(lettre,"%s ambin' ny %s",Unite(tmp),diz[isa/10]);
			
			else	
			sprintf(lettre,"%s amby %s",Unite(tmp),diz[isa/10]);
	}		
	return lettre;
}
char* Centaine(int isa){
	char cent[10][11]={"","zato","roanjato","telonjato","efajato","dimanjato","eninjato","fitonjato","valonjato","sivinjato"};
	char* lettre=(char*)malloc(100);
	int tmp=(isa%100);
	int div=(isa/100);
		
			if(tmp==0)
				sprintf(lettre,"%s",cent[div]);
			else if(isa%100!=0){
				if(isa>=101 && isa<=199){
					if(isa>=101 && isa<=109)
					sprintf(lettre,"%s amby %s",Unite(tmp),cent[div]);
					else if(Dizaine(tmp))
					sprintf(lettre,"%s amby %s",Dizaine(tmp),cent[div]);				
					}
				else if(isa >199){
					if(tmp==1 ||tmp==2 ||tmp==3 || tmp==4 ||tmp==5 || tmp==6 ||tmp==7 || tmp==8 || tmp==9 )
					sprintf(lettre,"%s sy %s ",Unite(tmp),cent[div]);		
					else
					sprintf(lettre,"%s sy %s",Dizaine(tmp),cent[div]);			
				}
			}
			
	return lettre;
}			
char* Arivo(int isa){
	char a[5]="arivo";
	char* lettre=(char*)malloc(500);
	int tmp=(isa%1000),div=(isa/1000);
	int reste=isanJavatra(tmp);
	if(div!=1){
		if(tmp==0)
			sprintf(lettre," %s %s ",Unite(div),a);
		if(tmp==1 || tmp==2 || tmp==3 || tmp==4 || tmp==5 || tmp==6 || tmp==7 || tmp==8 ||tmp==9)
			sprintf(lettre,"%s sy %s %s ",Unite(tmp),Unite(div),a);	
		else{
			if(reste==2)
			sprintf(lettre,"%s sy %s %s",Dizaine(tmp),Unite(div),a);
			else
			sprintf(lettre,"%s sy %s %s ",Centaine(tmp),Unite(div),a);	
		}
	}
	
	///si nbre/1000=1 on dit juste arivo
	else{
			if(tmp==0)
			sprintf(lettre," %s ",a);
		if(tmp==1 || tmp==2 || tmp==3 || tmp==4 || tmp==5 || tmp==6 || tmp==7 || tmp==8 ||tmp==9)
			sprintf(lettre,"%s sy  %s ",Unite(tmp),a);	
		else{
			if(reste==2)
			sprintf(lettre,"%s sy %s ",Dizaine(tmp),a);
			else
			sprintf(lettre,"%s sy %s  ",Centaine(tmp),a);	
		}
	}
		
	return lettre;
}		
char* Alina(int isa){
		char a[6]="alina";
	char* lettre=(char*)malloc(800);
	int tmp=(isa%10000),div=(isa/10000);	
	int reste=isanJavatra(tmp);
	
		if(tmp==0)
			sprintf(lettre," %s %s ",Unite(div),a);
		if(tmp==1 || tmp==2 || tmp==3 || tmp==4 || tmp==5 || tmp==6 || tmp==7 || tmp==8 ||tmp==9)
			sprintf(lettre,"%s sy %s %s ",Unite(tmp),Unite(div),a);	
		else{
			if(reste==2)
			sprintf(lettre,"%s sy %s %s",Dizaine(tmp),Unite(div),a);
			if(reste==3)
			sprintf(lettre,"%s sy %s %s",Centaine(tmp),Unite(div),a);
			else
			sprintf(lettre,"%s sy %s %s ",Arivo(tmp),Unite(div),a);
		}
	return lettre;		
}		
char* Hetsy(int isa){
		char a[6]="hetsy";
	char* lettre=(char*)malloc(900);
	int tmp=(isa%100000),div=(isa/100000);	
	int reste=isanJavatra(tmp);
	
		if(tmp==0)
			sprintf(lettre," %s %s ",Unite(div),a);
		if(tmp==1 || tmp==2 || tmp==3 || tmp==4 || tmp==5 || tmp==6 || tmp==7 || tmp==8 ||tmp==9)
			sprintf(lettre,"%s sy %s %s ",Unite(tmp),Unite(div),a);	
		else{
			if(reste==2)
			sprintf(lettre,"%s sy %s %s",Dizaine(tmp),Unite(div),a);
			if(reste==3)
			sprintf(lettre,"%s sy %s %s",Centaine(tmp),Unite(div),a);
			if(reste==4)
			sprintf(lettre,"%s sy %s %s ",Arivo(tmp),Unite(div),a);
			if(reste==5)
			sprintf(lettre,"%s sy %s %s ",Alina(tmp),Unite(div),a);
			
		}
	return lettre;		
}
		
char* Tapitrisa(int isa){
	char** tap= alloue2DChar(2);
	tap=Separer(isa);
	int tapitra=CharTOInt (0,tap);
	int het=CharTOInt (1,tap);
	char* let=malloc(900);
	char* le=malloc(500);
	char* lettre=malloc(1500);
	sprintf(let,"%s",Hetsy(het));
	printf("\n541321=%s",let);
	
	sprintf(le,"%s",Arivo(tapitra));
	printf("\n1109=%s",le);
	
	sprintf(lettre,"%s sy %s tapitrisa",let,le);
	printf("\n%s",lettre);
	

	
	return lettre;
}

char** Separer(int isa){
	char** tap= alloue2DChar(2);
	int tmp=isa;
	char* caractere=malloc(12);
	sprintf(caractere,"%d",tmp);
	printf("%s",caractere);  //printf
	
	
	for(int i=0; i<4;i++){
		tap[0][i]=caractere[i];
	}
	printf("\n%s",tap[0]);  //printf
	for(int i=4,j=0; i<strlen(caractere);j++,i++){
		tap[1][j]=caractere[i];
	}
	printf("\n%s",tap[1]);  //printf
	return tap;
}
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}		 	
int CharTOInt (int ligne,char** tap){
	int nbre=0;
	int x=-1;
	for(int i=strlen(tap[ligne])-1; i>=0;i--){
		x++;
		nbre+=ascii(tap[ligne][i])*pow(10,x);
	}
	return nbre;
}	

int ascii(char car){
	return (car-'0');
}
