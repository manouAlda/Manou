#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encode_character( int ch, int val );
int decode_character( int ch, int val );

int main( int argc, char *argv[]) {
    FILE *file;
    int rv = 1;
    int ch = 0;
    unsigned int count = 0; 
    int val = 7;
    char buffer[257];

    if( argc != 3 ) {
        printf("\nErreur: nombre de paramètres incorrect..." );
        printf("\n\nSyntaxe:\n"
        "%s nomfichier action", argv[0]);
        printf("\n\nOù:");
        printf("\nnomfichier = nom du fichier à coder ");
        printf("ou à décoder");
        printf("\naction = D pour décoder ou C pour coder\n\n") ;
        rv = -1;
        
    }
    else if(( argv[2][0] == 'D') || (argv[2][0] == 'd' )) /* décodage */
    {
        file = fopen(argv[1], "r");
       
        if( file <= 0 )        {
            printf( "\n\nErreur d’ouverture du fichier..." );
            rv = -2;
        }
        else    {
            ch = getc( file );
            /* lecture d’un caractère */
            while( !feof( file ) )            {
                ch = decode_character( ch, val );
                putchar(ch); /* Affichage du caractère */
                ch = getc( file);
            }
            fclose(file);
            printf( "\n\nFichier décodé et affiché.\n" );
        }
    }
    else {
        /* Codage dans un fichier. */
        file = fopen(argv[1], "w");
        if( file <= 0 )
        {
            printf( "\n\nErreur pendant la création du fichier..." );
            rv = -3; 
        }
        else    {
            printf("\n\nEntrez le texte à coder. ");
            printf("Entrez une ligne vide pour terminer.\n\n");

            while( fgets(buffer, sizeof(buffer), stdin)) {
                if((buffer[0] == 0) || (buffer[0] == '\n'))
                    break;
                for( count = 0; count < strlen(buffer); count++ ) {
                        ch = encode_character( buffer[count], val );
                        ch = fputc(ch, file); /* Ecriture du fichier */
                        printf("%c",ch);
                 }    
            }
            printf( "\n\nMessage codé et enregistré.\n" );
            fclose(file);
        }
    }

    exit((rv==1)?EXIT_SUCCESS:EXIT_FAILURE);
}

int encode_character( int ch, int val ) {
    ch = ch + val;
    return (ch);
}

int decode_character( int ch, int val ) {
    ch = ch - val;
    return (ch);
}
