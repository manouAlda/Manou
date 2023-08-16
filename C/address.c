#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int testons (char* ip){
	int count=0;
	for(int i=0;i<strlen(ip);i++){
		if(*(ip+i)=='.'){
			count++;
		}
	}
	return count;
}

char* asiana_point(char* tab){
	char* ip_mod = malloc(50);  // La chaîne modifiée peut être plus longue
	int longueur = strlen(tab);
	int index_modifie = 0;
	
	    for (int i = 0; i < longueur; i++) {
	        ip_mod[index_modifie++] = tab[i];
	        if ((i + 1) % 3 == 0 && i != longueur - 1) {
	            ip_mod[index_modifie++] = '.';
	        }
	    }
	    ip_mod[index_modifie] = '\0';  // Terminer la chaîne modifiée
	
	    printf("Chaîne modifiée : %s\n", ip_mod);
	return ip_mod;
}

int nombre (int n){
	int s=0,count =0;
	
	while(n!=0)
	{
		s /=2;
		n =s;
		count++;
	}

	return count;
}

int if_ip (char* tab){
	int turn=1;
	int a=0,c=0,b=0,d=0;
	sscanf(tab,"%d.%d.%d.%d",&a,&c,&b,&d);
	
	printf("\n%d,%d,%d,%d\n",a,c,b,d);
	if(a>255 || c>255 || b>255 || d>255){
		turn=0;
	}
	else if(a<=255 && c<=255 && b<=255 && d<=255){
		turn=1;
	}
		
	return turn;
}

int search(int* pow_two,int n){
	int index=0;
	for(int i=0;i<8;i++){
		if(n==pow_two[i])	index=i+1;
	}
	return index;
}

char* bits(char* subnet,int* pow_two){
	char* mask=malloc(20);
	int a=0,b=0,c=0,d=0,sum=0;
	int t=0;
	
	sscanf(subnet,"%d.%d.%d.%d",&a,&b,&c,&d);
	if(a==255){
		sum+=8;
		if(b==255){
			sum+=8;
			if(c==255){
				sum+=8;
				if(d==255)	sum+=8;
				else if(d<255){
					t = 256-d;
					t = search(pow_two,t);
					sum+=t;
				}
			}
			else if(c<255){
				t=256-c;
				t=search(pow_two,t);
				sum+=t;
			}
		}
		else if(b<255){
			t=256-b;
			t=search(pow_two,t);
			sum+=t;
		}
	}
	sprintf(mask,"%d",sum);
	printf("Network Bits : %s\n",mask);
	
	return mask;
}

double power(char* mask){
	double t=0;
	t= 32-(atoi(mask));
	return t;
}

char* intToBinary(int n ) {
	char *bin =(char*)calloc(9,sizeof(char));
    int index = 0;
    int count=0;
    while (n > 0) {
        bin[index++] = (n % 2) + '0';
        n /= 2;
        count++;
    }
    if(count<8){
		for(int i=count;i<8;i++)
			bin[index++]='0';
	}
    bin[index] = '\0';
    
    /// Avadika
    int len = strlen(bin);
    for (int i = 0; i < len / 2; i++) {
        char temp = bin[i];
        bin[i] = bin[len - i - 1];
        bin[len - i - 1] = temp;
    }
    return bin;
}

char* search_reseau(char* ip,char* mask,int*pow_two){
	int adr = atoi(mask);
	char* reseau=malloc(50);
	int cal=0,r=0, a=0, b=0,c=0,d=0,sum=0;
	char* binaire = calloc(9,sizeof(char));
	char* temp=malloc(3);
	
	cal = adr/8;
	r=adr%8;
	sscanf(ip,"%d.%d.%d.%d",&a,&b,&c,&d);
	
	if(cal==1)	sprintf(reseau,"%d.",a);
	else if(cal==2)	sprintf(reseau,"%d.%d.",a,b);
	else if(cal==3)	sprintf(reseau,"%d.%d.%d.",a,b,c);
	
	if(r==0) strcat(reseau,"0");
	else if(r>0){
		if(cal==1){
			binaire = intToBinary(b);
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d.0.0",sum);
			}
		}
		else if(cal==2){
			binaire = intToBinary(c);
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d.0",sum);
			}
		}
		if(cal==3){
			binaire = intToBinary(d);
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d",sum);
			}
		}
	}
	strcat(reseau,temp);
	printf("\nNetwork adress : %s\n",reseau);
	
	return reseau;
}

char* search_broadcast(char* ip,char* mask,int* pow_two){
	int adr = atoi(mask);
	char* reseau=malloc(50);
	int cal=0,r=0, a=0, b=0,c=0,d=0,sum=0;
	char* binaire = calloc(9,sizeof(char));
	char* temp=malloc(3);
	
	cal = adr/8;
	r=adr%8;
	sscanf(ip,"%d.%d.%d.%d",&a,&b,&c,&d);
	
	if(cal==1)	sprintf(reseau,"%d.",a);
	else if(cal==2)	sprintf(reseau,"%d.%d.",a,b);
	else if(cal==3)	sprintf(reseau,"%d.%d.%d.",a,b,c);
	
	if(r==0) strcat(reseau,"255");
	else if(r>0){
		if(cal==1){
			binaire = intToBinary(b);
			for(int i=r;i<8;i++)
				binaire[i]='1';
			for(int j=0;j<8;j++){
				if(binaire[j]=='1')
					sum+=pow_two[j];
				else if(binaire[j]=='0')
					sum+=0;	
				sprintf(temp,"%d.255.255",sum);
			}
		}
		else if(cal==2){
			binaire = intToBinary(c);
			for(int i=r;i<8;i++)
				binaire[i]='1';
			for(int i=0;i<8;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d.255",sum);
			}
		}
		if(cal==3){
			binaire = intToBinary(d);
			for(int i=r;i<8;i++)
				binaire[i]='1';
			for(int i=0;i<8;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d",sum);
			}
		}
	}
	strcat(reseau,temp);
	printf("\nBroadcast : %s\n",reseau);
	
	return reseau;
}

char* msr (char* ip,char* mask,int* pow_two){
	int count = atoi(mask);
	int r=count%8;
	char* binaire = calloc(9,sizeof(char));
	int a=0, b=0,c=0,d=0,sum=0;
	char* subnet = malloc(50);
	char* temp = malloc(50);
	count = count/8;
	sscanf(ip,"%d.%d.%d.%d",&a,&b,&c,&d);
	if(count==1)
		strcpy(subnet,"255.");
	else if(count==2){
		strcpy(subnet,"255.255.");
	}
	else if(count==3){
		strcpy(subnet,"255.255.255.");
	}
	
	if(r==0) strcat(subnet,"0");
	else if(r>0){
		if(count==1){
			binaire = intToBinary(b);
			for(int i=0;i<r;i++)
				binaire[i]='1';
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d.0.0",sum);
			}
		}
		else if(count==2){
			binaire = intToBinary(c);
			for(int i=0;i<r;i++)
				binaire[i]='1';
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d.0",sum);
			}
		}
		if(count==3){
			binaire = intToBinary(d);
			for(int i=0;i<r;i++)
				binaire[i]='1';
			for(int i=0;i<r;i++){
				if(binaire[i]=='1')
					sum+=pow_two[i];
				else if(binaire[i]=='0')
					sum+=0;
				sprintf(temp,"%d",sum);
			}
		}
	}
	strcat(subnet,temp);
	printf("\nSubnet mask : %s\n",subnet);
	
	return subnet;
}

char* first(char* reseau){
	char* first = malloc(50);
	int tmp=0,a,b,c;
	sscanf(reseau,"%d.%d.%d.%d",&a,&b,&c,&tmp);
	sprintf(first,"%d.%d.%d.%d",a,b,c,tmp+1);
	printf("First host adress : %s\n",first);
	return first;
}

char* last(char* reseau){
	char* last = malloc(50);
	int tmp=0,a,b,c;
	sscanf(reseau,"%d.%d.%d.%d",&a,&b,&c,&tmp);
	sprintf(last,"%d.%d.%d.%d",a,b,c,tmp-1);
	printf("Last host adress : %s\n",last);
	return last;
}
