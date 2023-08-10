// Arrays are already defined with this interface:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
typedef struct arr_integer {
   int size;
   type *arr;
 } arr_integer;

arr_integer alloc_arr_integer(int len) {
   arr_integer a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
   return a;
}
*/
int solution(char* inputArray) {
    int p=1; int max=inputArray[0]*inputArray[1];
    for(int i=strlen(inputArray)-1; i>0;i--){
        p = (inputArray[i])*(inputArray[i-1]);
        printf("  %d   * %d   =  %d\n",(inputArray[i]),(inputArray[i+1]),p);
        if(max < p ){
            max = p; 
        }
        
    }
   
    return max;
}

int main(){
	char inputArray[6] = {-23, 4, -3, 8, -12};
	//char inputArray[6] = {3, 6, -2, -5, 7, 3};
	int max=0;
	max = solution (inputArray);
	
	printf("%d",max);
	
	return 0;
}

