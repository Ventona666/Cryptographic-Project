//
// Created by TONY DE FREITAS on 10/12/2020.
//

#include "xor.h"
#include <stdio.h>
#include <string.h>

void help_menu(){
    printf("NAME\n");
    printf("\tdh_crypt - Cryptage méthode XOR\n");
    printf("SYNOPSIS\n");
    printf("\tdh_crypt [OPTION]... [FILE]...\n");
    printf("DESCRIPTION\n");
    printf("-i [file.txt]\n\tFichier contenant le message à chiffrer\n");
    printf("-o [file.txt]\n\tFichier où le texte crypte va etre ecrit\n");
    printf("-k [key]\n\tClef pour crypter le texte\n");
    printf("-h\n\tPour afficher ceci\n");
}

int main(int argc, char** argv){
    int i=1;
    char *input_file, *output_file, *key;
    while (i<argc){
        if (strcmp("-i", argv[i]) == 0) {
            input_file = argv[i+1];
            }
        else if (strcmp("-o", argv[i]) == 0) {
            output_file = argv[i+1];
            }
        else if (strcmp("-k", argv[i]) == 0) {
            key = argv[i+1];
            }
        else if (strcmp("-h", argv[i]) == 0) {
            help_menu();
            }
        else {
            printf("Attention, %s n'est pas un parametre valide pour cette commande, tapez dh_crypt -h.", argv[i]);
            }
        i += 2;
    }
    cryptage(input_file, output_file, key);
    return 0;
}