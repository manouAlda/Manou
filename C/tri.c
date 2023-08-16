#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "triage.h"

int main(){
	int tab[7]={3, 6, 5, 8, 10, 20, 15};
	int taille = 7, n=0;
	int* tmp = malloc(sizeof(int)*taille);
	int* copie = malloc(taille*sizeof(int));
	int count=0;
	
	/*
	for(int k=0;k<taille;k++){
		copie[k]=tab[k];
	}	*/
	for(int i=0; i<taille-1;i++){
		//if(i==taille-2){
			printf("\nRECOPIE\n");
			for(int k=0;k<taille;k++){
				copie[k]=tab[k];
				printf("~ %d\n",copie[k]);
			}
		//}
		tmp = del(copie,taille,i);
		printf("  here  %d :   %d\n",i,tmp[i]);
		n = test(taille-1,tmp);
		if(n==1){
			count++;
			printf("\nCOUNT = %d\n",count);
		}
		else {
			count=0;
			continue;
		}
	}
	for(int i=0;i<taille;i++){
		printf("tab[%d] = %d\n",i,tab[i]);
	}
	if(count>0){
		printf("True");
	}
	else if (count ==0){
		printf("False");
	}
	
	return 0;
}
/*
// Arrays are already defined with this interface:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//
//
int test (int taille,int* tab){
	int n=0;
	for(int i=taille-1;i>0; i--){
		if(tab[i]>tab[i-1]){
			n=1;
		}
		else{
            n=0;
			break;
		}
	}
	return n;
}
int* del (int* tab,int taille,int pos){
	for(int j=pos;j<taille-1;j++){
		tab[j]=tab[j+1];
	}
	return tab;
}
bool solution(arr_integer sequence) {
    int* tmp = malloc(sizeof(int)*sequence.size);
	int* copie = malloc(sequence.size*sizeof(int));
	int count=0,n=0;
	
    if(sequence.size==2){
        return true;
    }	
	for(int i=0; i<=sequence.size-1;i++){
        for(int k=0;k<sequence.size;k++){
			copie[k]=sequence.arr[k];
		}
		tmp = del(copie,sequence.size,i);
		n = test(sequence.size-1,tmp);
		if(n==1){
			count++;
		}
		else {
			//count=0;
			continue;
		}
	}
	if(count>0){
		//printf("True");
        return true;
    }
	else if (count ==0){
		//printf("False");
        return false;
    }
}
*/
/*  SOLUTION JAVA*/
/*
boolean solution(int[] sequence) {
    int numErr = 0;
    for (int i = 0; i < sequence.length - 1; i++) {
        if (sequence[i] - sequence[i+1] >= 0) {
            numErr += 1;
            if (i - 1 >= 0 && i + 2 <= sequence.length - 1
               && sequence[i] - sequence[i+2] >= 0
               && sequence[i-1] - sequence[i+1] >= 0) {
                return false;
            }
        }
    }
    
    return numErr <= 1;
}
*/
/* SOLUTION C */
/*
 bool solution(arr_integer sequence) {
    int p=-1,c=0,i;
    for(i=1;i<sequence.size;i++) 
    if(sequence.arr[i-1]>=sequence.arr[i])
        {
            p=i;
            c++;
        }    
    if(c>1) return false;
    if(c==0) return true;
    if(p==sequence.size-1) return true;
    if(p==1) return true;
    if(sequence.arr[p-1]<sequence.arr[p+1]) return true;
    if(sequence.arr[p-2]<sequence.arr[p]) return true;
    return false;
}
* */
/*
 * int strikes = 0;
    
    int max = -100000;
    int secondMax = -100000;
    
    for (int i=0; i<seq.size; i++) {
        if (seq.arr[i] > max) {
            secondMax = max;
            max = seq.arr[i];
        } else if (seq.arr[i] > secondMax) {
            max = seq.arr[i];
            strikes++;
        } else {
            strikes++;
        }
    }
    if (strikes < 2)
        return true;
    return false;
  */
  /*
   bool solution(arr_integer sequence) {
    int remove =0;
    for(int i=0; i<sequence.size-2;i++)
    {
        
        int first = sequence.arr[i];
        int next = sequence.arr[i+1];
        int last  = sequence.arr[i+2];
       
        
        if(first>=next){
            
            remove++;
            sequence.arr[i]=next-1;
        
        }
        if(next>=last){
            
            remove++;{
                if(first==last){
                    sequence.arr[i+2]=next+1;
                }else{
                    sequence.arr[i+1] = first;
                }
            }
        }
            
        }
        
    
    
    if(remove>1){
        return false;
    }else{
        return true;
    }
    
}
* */
/*
 * bool solution(arr_integer sequence) 
{
    int twi = 0;
    int k = 1;
    int med;
    
    if(sequence.size == 1)
        return true;
    
    if(sequence.arr[0] >= sequence.arr[1])
        twi++;
    
    while(k < sequence.size - 2)
    {
        if( sequence.arr[k] >= sequence.arr[k+1])
        {
            if((sequence.arr[k] > sequence.arr[k-1] && sequence.arr[k] < sequence.arr[k+2])||(sequence.arr[k+1] > sequence.arr[k-1] && sequence.arr[k+1] < sequence.arr[k+2]))
            {
                if(twi != 0 )
                    return false;
                twi++;
            }
            else
                return false;
        }
        k++;
    }
    if(sequence.arr[sequence.size-1] <= sequence.arr[sequence.size-2])
        if(twi != 0 && sequence.size > 2 )
            return false;
    return true;
}*/
