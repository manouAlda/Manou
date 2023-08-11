#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void moisdelAnnee(float mois,int annee,float jour);
int main(){
	float mois,jour,annee;
	/*heure=0;
	minute=0;
	seconde=0;*/
	mois=99.88;
	annee=2023;
	jour=41.198;
	moisdelAnnee(mois,annee,jour);
	
	
  return 0;
}	
	
void moisdelAnnee(float mois,int annee,float jour){	
	float heure,seconde,minute,mois_cast;
	heure=0;
	seconde=0;
	minute=0;
	while(mois>=12){
		annee+=1;
		mois-=12;
		
	}
	mois_cast=(mois-(int)mois)*30;
	jour=jour+mois_cast;
	while(jour>=30){
		mois+=1;
		jour-=30;
	}
	seconde=(jour-(int)jour)*24*60*60;
	while(seconde>=60){
		minute++;
		seconde-=60;
		while(minute>=60){
			heure ++;
			minute-=60;	
	}  
			
	}
	while(heure>=24){
		jour++;
		heure-=24;
	}
		
	
	printf("%g :%g :%d\n",heure,minute ,(int)seconde);
	printf("%d :%d :%d",(int)jour,(int)mois,(int)annee);
		
	
	
		return ;
	}	
