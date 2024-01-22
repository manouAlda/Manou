#include <stdio.h>
#include <stdlib.h>

int main (){
	float y=0;
	float x=0;
	float a=2,b=10;
	int n=0; 
	
	printf("\nEntrez le nombre d'incrementation: ");
	scanf("%d",&n);
	float incr=0;
	incr = (b-a)/n;
	FILE* file;
	file = fopen ("test.csv","w+");
	fputs("x\ty\n",file);
	
	for (x=a ; x<b; x+=incr){
		y = x -1;
		fprintf(file,"%f\t%f\n",x,y);
	}
	
	fclose (file);
	
	return 0;
}
