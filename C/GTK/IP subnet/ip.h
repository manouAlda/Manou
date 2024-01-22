#ifndef IP_H
#define IP_H

int testons (const char* ip);
const char* asiana_point(const char* tab);
int nombre (int n);
int if_ip (const char* tab);
int search(int* pow_two,int n);
const char* bits(const char* subnet,int* pow_two);
double power(const char* mask);
char* intToBinary(int n );
const char* search_reseau(const char* ip,const char* mask,int* pow_two);
const char* search_broadcast(const char* ip,const char* mask,int* pow_two);
const char* msr (const char* ip,const char* mask,int* pow_two);
const char* first(const char* reseau);
const char* last(const char* reseau);
const char* finish(const char* tab);

#endif
