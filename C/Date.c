#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *jrsSemaine(int annee, int mois, int jour);

int main (){
	printf("Programmation + commande Linux.\n");
	printf("Ceci permet de determiner le jour et les processus d'une date donnee\n");
	
	int jour=0;
	int mois=-0;
	int annee=0;
///	char jrs[100];
	
	printf("Entrez l'annee: ");
	scanf("%d",&annee);
	printf("Entrez le mois:");
	scanf("%d",&mois);
	printf("Entrez le jour:");
	scanf("%d",&jour);
	
///	jrs[100] =jrsSemaine(annee, mois, jour);
	
	printf("\n%d-%02d-%02d: %s\n",annee,mois, jour,jrsSemaine(annee, mois, jour) );
	
	system("ps -eo pid,cmd,start_time,ettime ");
	
	printf("But: envoi d'un signal a un processsus\n");
	
	char k[10]="kill ";
	char s[10]=" -s";
	char  n[10];
	char  p[10];
	
	printf("\nVoici la liste de tous les signals que vous pouvez utilisez:");

	sleep(3);
	system("kill -l|cat -n");

	printf("\nEntrez le signal que vous voulez lancer:");
	scanf ("%s", n);
	
	system("ps -aux");
	sleep(10);
	
	printf("\nEntrez le pid du processus que vous voulez signaler:");
	scanf("%s", p);
	
	strcat(k,s);
	strcat(k," ");
	strcat(k,n);
	strcat(k," ");
	strcat(k,p);
		
	system(k);
	
	printf("Felicitation, processus arrete\n");

	return 0; 
}

const char *jrsSemaine(int annee, int mois, int jour){
	
//	char one[10]="Dimanche";   char two[10]"Lundi";  char three[10]="Mardi"  ; char four[10]="Mercredi" ; char five[10]="Jeudi" ; char six[10]="Vendredi" ; char seven[10]="Samedi" ;
	static const char *dayOfweek[]={"Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"} ;


	int a=0, b=0 , c=0, d =0, e=0, f =0, g =0;
	a = annee % 100;
	b = a / 4 ; 
	c = a + b;
	if (annee >= 2000){
		d = c + 1;
	}
	else if (annee < 2000){
		d = c;
	}
//	char month[13]={" ","Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
	//char nbrMonth[13]={" ","0","3","3","6","1","4","6","2","5","0","3","5"}
	
	switch (mois){
		case 01:
			if (mois % 4 ==0 ){
				e = d - 1;
			}
			else{
				e = d ;
			}
			break;
		case 02:
			if (mois % 4 ==0 ){
				e = d +2;
			}
			else{
				e = d + 3;
			}
			break;
		case 03:
			e= d +3;
			break;
		case 04:
			e = d + 6;
			break;
		case 05:
			e = d + 1;
			break;
		case 06:
			e = d +4;
			break;
		case 07:
			e = d + 6;
			break;
		case 8 :
			e = d + 2;
			break;
		case 9:
			e = d + 5;
			break;
		case 10:
			e =d ;
			break;
		case 11:
			e = d + 3;
		case 12:
			e = d+ 5;
			break;
	}
	switch (mois){
		case 01:
			f = e + 31;
			break;
		case 02:
			if (mois % 4 ==0 ){
				f = e + 29;
			}
			else{
				f = e + 28;
			}
			break;
		case 03:
			f = e + 31;
			break;
		case 04:
			f = e + 30;
			break;
		case 05:
			f = e + 31;
			break;
		case 06:
			f = e + 30;
			break;
		case 07:
			f = e + 31;
			break;
		case 8 :
			f = e +31;
			break;
		case 9:
			f = e + 30;
			break;
		case 10:
			f = e + 31;
			break;
		case 11:
			f = e + 30;
		case 12:
			f =e + 31;
			break;
	}
	g = f % 7 ;
	
	return dayOfweek[g + 2] ;
}
