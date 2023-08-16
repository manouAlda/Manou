#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "address.h"

int main() {
    char* ip = malloc(500);
    char* mask = malloc(50);
    char* subnet =malloc(50);
    int pow_two[8] = {128,64,32,16,8,4,2,1};
    
 /// Entree de donnees
    printf("Entrez l'adresse IP : ");
    fgets(ip, 500, stdin);
    ip[strcspn(ip, "\n")] = '\0'; 
    printf("Entrez le mask bits: ");
    fgets(mask, 50, stdin);
    mask[strcspn(mask, "\n")] = '\0';
    
  /// Test si vraiment ip  
    int test=0;
    test = testons(ip);

    if(test==0 || test==1 || test==2){
	   	 ip = asiana_point(ip);
    }
    
    else if(test==3 || test==4){
    	test = if_ip(ip);
    	if(test==1) printf("IPV4 trouve\n");
    	else if(test==0){
    		printf("erreur, ce n'est pas une adresse ip\n");
    	}
    }
    
    /// Masque de sous reseau
    int temp=0;
    temp = testons(mask);
    
	if(temp ==2)
		printf("Error, mask bits\n");
	else if(temp==3){
		strcpy(subnet,mask);
		mask = bits(subnet,pow_two);
	}
    if(temp ==0 || test ==1)
		subnet = msr(ip,mask,pow_two);
		
	/// Hosts
	printf("Hosts : %f\n",power(mask)-2);
		
  /// Adresse reseau
   char* reseau =malloc(50);
   char* first_h = malloc(50);
    reseau = search_reseau(ip,mask,pow_two);
    first_h = first(reseau);
    
   /// Adresse broadcast
   char* broadcast = search_broadcast(ip,mask,pow_two);
   char* last_h = malloc(50);
    last_h = last(broadcast);
    
    return 0;
}
