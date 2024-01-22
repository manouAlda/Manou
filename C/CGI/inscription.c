#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	char *valiny;
    char *nom = NULL;
    char *prenom = NULL;
    char *date = NULL;
    char *lieu = NULL;
    char *address = NULL;
    char *tel = NULL;
    char *sexe = NULL;
    char *numero = NULL;
    char *serie = NULL;
    char *centre = NULL;
    char *obtention = NULL;
    
    FILE* file = NULL;
    
    // Récupération de la chaîne de requête depuis la variable d'environnement QUERY_STRING
   valiny = getenv("QUERY_STRING");
   
	if(valiny != NULL){
		
		char *token = strtok(valiny, "&");

		while (token != NULL) {
			
			if (strstr(token, "nom=") == token) {
				nom = token + 4; 
				
				nom = withoutHex (nom) ;
			} else if (strstr(token, "prenom=") == token) {
				prenom = token + 7; 
				
			    prenom = withoutHex (prenom) ;
			}else if (strstr(token, "date=") == token) {
				date = token + 5;
			
				date = withoutHex (date) ;
			} else if (strstr(token, "lieu=") == token) {
				lieu = token + 5; 
				
				lieu = withoutHex(lieu);
			}else if (strstr(token, "address=") == token) {
				address = token + 8; 
				
			    address = withoutHex (address) ;
			}else if (strstr(token, "tel=") == token) {
				tel = token + 4; 
				
			} else if (strstr(token, "sexe=") == token) {
				sexe = token + 5; 
				
			}else if (strstr(token, "numero=") == token) {
				numero = token + 7; 
			}else if (strstr(token, "serie=") == token) {
				serie = token + 6; 
				
			} else if (strstr(token, "centre=") == token) {
				centre = token + 7; 
				centre = withoutHex(centre);
			}else if (strstr(token, "obtention=") == token) {
				obtention = token + 10; 
	
			}
		  
			token = strtok(NULL, "&");
		}

		// Génération de la page HTML de réponse
		printf("Content-Type: text/html\n\n");
		
		printf("<!DOCTYPE HTML\n>");
		printf("<html>\n<head>\n<title>Réponse CGI</title>\n</head>\n<body>\n");

		printf("<h1>Valeurs récupérées via GET :</h1>\n");
		printf("<p>Nom : %s</p>\n", nom);
		printf("<p>Prenom : %s</p>\n", prenom);
		printf("<p>Date de naissance : %s</p>\n", date);
		printf("<p>Lieu de naissance : %s</p>\n", lieu);
		printf("<p>Adresse exacte : %s</p>\n", address);
		printf("<p>Tel : %s</p>\n", tel);
		printf("<p>Genre : %s</p>\n", sexe);
		printf("<p>Numero d'inscription : %s</p>\n", numero);
		printf("<p>S&eacute;rie : %s</p>\n", serie);
		printf("<p>Centre d'examen : %s</p>\n", centre);
		printf("<p>Ann&eacute;e d'obtention : %s</p>\n", obtention);
		
		/// Enregistrement des données dans un fichier
		file=fopen("inscription.csv","w+");
		
		if(file!=NULL){
			fprintf(file,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",nom,prenom,date,lieu,address,tel,sexe,numero,serie,centre,obtention);
		}
		else{
			printf("<p>Note : error of opening file</p>\n");
		}
		fclose(file);

		printf("</body>\n</html>\n");
	}
	else{
		printf("valiny = null \n");
	}

    return 0;
}
