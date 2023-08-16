#ifndef ADDRESS_H
#define ADDRESS_H

int testons (char* ip);
char* asiana_point(char* tab);
int nombre (int n);
int if_ip (char* tab);
int search(int* pow_two,int n);
char* bits(char* subnet,int* pow_two);
double power(char* mask);
char* intToBinary(int n );
char* search_reseau(char* ip,char* mask,int* pow_two);
char* search_broadcast(char* ip,char* mask,int* pow_two);
char* msr (char* ip,char* mask,int* pow_two);
char* first(char* reseau);
char* last(char* reseau);

#endif
