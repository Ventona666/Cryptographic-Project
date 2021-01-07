//
// Created by TONY DE FREITAS on 06/01/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dh_crack.h"

void create_tab_keys(t_tab_keys *tab_keys, int key_size){
    int i;
    tab_keys->key_size = key_size;
    tab_keys->tab_keys = malloc(key_size * sizeof(byte*));
    for (i=0; i < key_size; i++) {
        tab_keys->tab_keys[i] = malloc(10 * sizeof(byte));
    }
}

void init_tab_keys(t_tab_keys *tab_keys){
    int i,j;
    byte k = 49;

    if (tab_keys->key_size > 0){
        for (i=0; i < 9; i++){
            tab_keys->tab_keys[0][i]=k;
            k ++;
        }
        tab_keys->tab_keys[0][9] = '0';
    }

    for (i=1; i < tab_keys->key_size; i++){
        k = 48;
        for (j=0; j < 10; j++){
            tab_keys->tab_keys[i][j]= k;
            k ++;
        }
    }
}

void print_tab_keys(t_tab_keys tab_keys){
    int i,j;
    for (i=0; i < tab_keys.key_size; i++){
        printf("[");
        for(j=0; j<10 && (j==0 || tab_keys.tab_keys[i][j] != '0'); j++){
            printf("%c, ", tab_keys.tab_keys[i][j]);
        }
        printf("]\n");
    }
}

void print_key_chars(t_tab_keys tab_keys){
    int i,j;
    printf("[");
    for (i=0; i < tab_keys.key_size; i++){
        for (j=)
    }
}

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
    char *file_name_in, *key, *dict, *method;
    while (i<argc){
        if (strcmp("-i", argv[i]) == 0) {
            file_name_in = argv[i+1];
        }
        else if (strcmp("-m", argv[i]) == 0){
            method = argv[i+1];
        }
        else if (strcmp("-d", argv[i]) == 0) {
            dict = argv[i+1];
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
    if (strcmp("c1", method) == 0){
        t_tab_keys T;
        int k = atoi(key);
        create_tab_keys(&T, k);
        init_tab_keys(&T);
        print_tab_keys(T);
        crack_c1(file_name_in, T, k);
        print_tab_keys(T);
    }
    return 0;
}
