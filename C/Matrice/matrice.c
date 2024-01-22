#include <stdio.h>

int main(){
	int tab[3][4]={{0,1,1,2},{0,5,0,0},{2,0,3,3}};
	int count =0,p=0;
	
	for(int i=0; i<3;i++){
		for(int j=0;j<4;j++){
			p+=tab[i][j];
			if(tab[i][j]==0 && i<3-1){
				tab[i+1][j]=0;
			}
			//if(tab[i][j]==0) count++;
		}
		printf("\n");
	}
	printf("\n tab \n");
	for(int i=0; i<3;i++){
		for(int j=0;j<4;j++){
			printf("%d\t",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n finish\ncount = %d\n\np=%d\n",count,p);

	return 0;
}
