#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	/*float prix[4]={24.42, 24.42, 24.2424, 85.23};
	char* note[] = {"13.157% higher than in-store", "13.157% lower than in-store", "Same as in-store", "19.24% higher than in-store"};
	double x = 24.24;*/
	char* toi[]={"me","aba","moi","er","ze","abb"};
	/*
	char test[10];
    double high=0;
    double pct=0, n=0;
    for(int i=0; i<4; i++){
        sscanf(note[i],"%lf%*[^ ] %[^ ]",&pct,test);
        printf(" (%d)  %lf   %s\n",i,pct,test);
        if (strcmp(test,"higher")==0){
            high = ceil (   prix[i] - (prix[i]*(pct/100)) ) ;
            printf("high = %lf\n",high);
        }
        else if (strcmp(test,"lower")==0){
            high = ceil ( prix[i] + (prix[i]*(pct/100)) );
            printf("high = %lf\n",high);
        }
        else if (pct == 0){
            high = prix[i];
            printf("high = %lf\n",high);
        }
        n += prix[i]- high;
        printf("n = %lf\n",n);
        pct=0;
        strcpy(test,"");
    }
    if(n< x){
        printf("false\n");
    }
    else if (n>=x){
        printf("true\n");
    } */
	
	int max=0,n=0;
	for(int i=0;i<6;i++){
		n= strlen (toi[i]);
		if(max<n){
			max=n;
		}
	}
	char* moi[6];
	printf("max = %d\n",max);
	for(int i=0;i<6;i++){
		n= strlen (toi[i]);
		if(n==max){
			int j=0;
			printf("%s\n",toi[i]);
			moi[j]=toi[i];
			j++;
		}
	}
	
	return 0;
}
