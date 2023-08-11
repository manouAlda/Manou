#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include <unistd.h> 
#include <sys/select.h> 
#include <ncurses.h> 
 
void option_play(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void option_list(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void option_search(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void Option(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void play(char **titre, char *logeMusiques, char *logePlay, char* numero); 
void play_l(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void play_o(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge); 
void get_titre(char **titre, char *logePlay, char *choix, char *logeChoice); 
void get_chemin(char **titre, char *logePlay, char *logeChoice,char* loge,char* route); 
void lister(char *logePlay,char *logeMusiques); 
 
void pictureL(){ 
        printf("\n\n\n"); 
        printf("   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"); 
        printf("   0                           0\n"); 
        printf("   0                           0\n"); 
        printf("   0         *************     0\n"); 
        printf("   0         *           *     0                 NEXT  ==  (q + entrée)\n"); 
        printf("   0         *           *     0                 QUIT  ==  (q + entrée) + entrée\n"); 
        printf("   0         *           *     0                PAUSE  ==  (pause + entrée)\n"); 
        printf("   0         *           *     0               RESUME  ==  (play + entrée)\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0                           0\n"); 
        printf("   0                           0\n"); 
        printf("   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  \n\n"); 
 
} 
 
void pictureO(){ 
        printf("\n\n\n"); 
        printf("   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"); 
        printf("   0                           0\n"); 
        printf("   0                           0\n"); 
        printf("   0         *************     0\n"); 
        printf("   0         *           *     0 \n"); 
        printf("   0         *           *     0                 QUIT  ==  (q + entrée) + entrée\n"); 
        printf("   0         *           *     0                PAUSE  ==  (pause + entrée)\n"); 
        printf("   0         *           *     0               RESUME  ==  (play + entrée)\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0     *****       *****     0\n"); 
        printf("   0                           0\n"); 
        printf("   0                           0\n"); 
        printf("   0 0 0 0 0 0 0 0 0 0 0 0 0 0 0  \n\n"); 
 
} 
 
void delay(char *logeChoice, char *logeChemin,char *logePlay,char *logeMusiques,char **titre,int nb_musique,char* route,char* loge){ 
         // Configuration du timer 
    struct timeval timer; 
    timer.tv_sec = 2; 
    timer.tv_usec = 0; 
 
    // Configuration des descripteurs de fichiers 
    fd_set ensemble_lecteur; 
    FD_ZERO(&ensemble_lecteur); 
    FD_SET(STDIN_FILENO, &ensemble_lecteur); 
 
