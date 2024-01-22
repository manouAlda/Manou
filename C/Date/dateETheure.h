#ifndef DATEETHEURE_H
#define DATEETHEURE_H

char** alloue2DChar(int taille);
int IndiceEspace(char* heure);
char** alloue2DChar(int taille);
char** SeparerEspace(char* heure);
int* position_Slash(int j,char** espace);
char** separationSlash(int j,char** espace);
int Ascii(char slash);
int CharToInt(int j,char** slash);
float Conversion_en_jour(int j, char** espace);
char* changementDuFormat(float jour,char** espace);

#endif
