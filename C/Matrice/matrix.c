#include <stdio.h>
#include <string.h>

int main(){
	int tab[3][4]={{0,1,1,2},{0,5,0,0},{2,0,3,3}};
	int count=0;

	int n=0,index=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			
			if(tab[i][j]==0){ 
				index=j;  
				count++;
			}
			if (j == index && i>=j){
				count++;
			}
			else{
				n+=tab[i][j];
			}
			
		}
		printf("\n");
	}

	printf("n = %d",n-count);

	return 0;
}
