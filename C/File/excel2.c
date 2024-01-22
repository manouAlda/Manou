#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define PI 3.14159265358979323846

int main(){
	float rad =0;
	float x ,y,z,a;
	int p=0, q=45, r= 90;
	FILE* file;
	file = fopen ("trigo.csv","w+");
	if (file == NULL){
		printf("Erreur d'ouverture du fichier\n");
		sleep(5);   exit(1);
	}
	fputs("Degré\tSinus\tTangentes\tCotangentes\tCosinus\t\n",file);
	for (int i=p;i<=q;i++){
		rad = ((PI * i)/ 180) ;
		x = sin(rad);
		y = cos (rad);
		z = tan (rad);
		a = 1 / z ;
		fprintf(file,"%d\t%.3f\t%.3f\t%.3f\t%.3f\t%d\n",i,x,z,a,y,r-i);
	}
	fputs("\tCosinus\tCotangentes\tTangentes\tSinus\tDegré\n",file);
	
	fclose(file);
	
	return 0;
}
