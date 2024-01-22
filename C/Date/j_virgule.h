#ifndef J_VIRGULE_H
#define J_VIRGULE_H

//int compterSlash(char* car);
int* IndiceSlash(char* car);
char** alloue2DChar(int taille);
char** SeparerSlash(char* car,int* indice);
///enlever le premier tableau d' indice 1 et separer le nombre 

int Etvirgule(char** tab);    ///pour trouver la place du virgule
char** SepareVirgule(int v,char** tab);
int charToint(char SepVir);
float Double(int v,char** SepVir);

///conversion en date
float ENseconde(float nbre);
char* convertirDate(float nbre);

char* affichageFormatDate(int* indice,char* car,char** tab);

#endif
