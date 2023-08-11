#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>

typedef struct Student{
	char nom[100];
	char prenom[100];
	char tel[50];
	char email[20];
	char adresse[50];
	char naissance[10];
	char lieu[100];
	char bacc[10];
	char genre[10];
	char cin[20];
	char url[20];
}student;

typedef struct Pc{
	char mac[20];
	char etiquette[20];
	char marque[10];
}pc;

char** allouer2D(int ligne,int colonne);
int nombre_pc ();
FILE* infos_pc (int nbr,pc* etudiant,char* filename);
FILE* trier_pc (FILE* file,char* filename);
int end_file(FILE* file,char* filename);
pc* recupere_3_object (FILE* file,char* filename);
pc* compare_2_thing (pc* copie,int n);
FILE* add_3_thing_file (int n,pc* copie);
int choose ();
FILE* infos_stud (int number,student *etudiant,char* filename);
char** in_tab (FILE* file,char* filename,int n);
char** compare_tab (char** tab,int n);
FILE* sort (FILE*file,char* filename);
FILE* add_url(FILE* file, char* filename) ;

#endif 
