#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* nbr (char* a){
	int* io = malloc(sizeof(int)*2);
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='(') io[0]=i;
		if(a[i]==')'){ io[1]=i;  break;}
	}
	return io;
}
char* first (char* a,int n){
	char* tab = malloc(20);
	for(int i=0;i<n;i++){
		tab[i]=a[i];
	}
	return tab;
}
char* reverse(char* a,int n,int m){
	char car;
	int j=0;
	char* b=malloc(20);
	for(int i=n+1;i<m;i++){
		b[j++]=a[i];
	}
	printf("sans reverse : %s\n",b);
	
	for(int i=0;i<strlen(b)/2;i++){
		car = b[i];
		b[i] = b[strlen(b)-1-i];
		b[strlen(b)-1-i]= car;
	}
	return b;
}
char* concat (char* tab,char* b){
	strcat(tab,b);
	return tab;
}
char* complete(char* tab,char* a,int m){
	int len = strlen(tab);
	for(int i=m+1;i<strlen(a);i++){
		tab[len++]=a[i];
	}
	return tab;
}
int manisa (char* a){
	int n=0;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='(')	n++;
	}
	return n;
}
char* copy(char* tab){
	char* a = malloc(20);
	strcpy(a,tab);
	return a;
}

int main(){
	char* a= malloc(20);
	strcpy(a,"foo(bar)baz");
	int count=0;
	char* b=malloc(20);
	char* tab = malloc(20);
	int n=0,m=0;
	int* isa =malloc(sizeof(int)*2);
	
	count = manisa(a);
	printf("count = %d\n",count);
	for(int i=0;i<count;i++){
		/// est ()
		isa= nbr(a);
		n= isa[0];
		m=isa[1]; 
		printf("n = %d  m=%d\n",n,m);
		
		/// 1ere partie
		tab = first(a,n);
		printf("Tab = %s\n",tab);
		/// traitement
		b = reverse(a,n,m);
		printf("avec reverse = %s\n",b);
		/// complement
		tab =concat(tab,b);
		printf("Tab inter = %s\n",tab);
		
		/// traitement
		tab = complete(tab,a,m);
		printf("Tab complete = %s\n",tab);
		
		a= copy(tab);
	}

	return 0;
}
