//
// Created by TONY DE FREITAS on 28/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "dh_prime.h"

void share_protocol(long p, long g){
    printf("Initialisation :\np = %ld et g = %ld. Tout le monde est en possession de ces informations !\n", p, g);
    long a = random_long(0, 1000);
    printf("Alice choisit le nombre secret a = %ld. Eve et Bob ne connaissent pas a.\n", a);
    long A = puissance_mod_n(g, a, p);
    printf("Alice envoie à Bob la valeur A = g^a[p] = %ld^%ld[%ld] = %ld. Eve connait A.\n", g, a, p, A);
    long b = random_long(0, 1000);
    printf("Bob choisit le nombre secret b = %ld. Eve et Alice ne connaissent pas b.\n", b);
    long B = puissance_mod_n(g, b, p);
    printf("Bob envoie à Alice la valeur B = g^b[p] = %ld^%ld[%ld] = %ld. Eve connait B.\n", g, b, p, B);
    long n = puissance_mod_n(B, a, p);
    printf("Alice peut désormais calculer la clef secrète B^a[p] = %ld^%ld[%ld] = %ld. Eve ne connait pas la clef secrète.\n", B, a, p, n);
    n = puissance_mod_n(A, b, p);
    printf("Bob peut désormais calculer la clef secrète A^b[p] = %ld^%ld[%ld] = %ld. Eve ne connait pas la clef secrète.\n", A, b, p, n);

}

void dh_genkey(bool writer, char* file){

    int cpt;
    long p = genPrimeSophieGermain(1, 10000, &cpt);
    long g = seek_generator(1, p);
    if (writer){
        FILE* fichier = NULL;
        fichier = fopen(file, "w");
        if (fichier != NULL){
            fprintf(fichier, "p = %ld et g = %ld", p, g);
            fclose(fichier);
        }
    }
    share_protocol(p, g);

}
int main(int argc , char** argv) {
    srand(time(NULL));   /* seconds since 1 Jan 1970 */
    if (!(argc-1)){
        dh_genkey(false, "NULL");
    }
    else if (argv[1][1] == 111){
        dh_genkey(true, argv[2]);
    }
    else if (argv[1][1] == 104){
        printf("NAME\n");
        printf("\tdh - Diffie-Hellman\n");
        printf("SYNOPSIS\n");
        printf("\tdh [OPTION]... [FILE]...\n");
        printf("DESCRIPTION\n");
        printf("-o [fichier.txt]\n\tPour écrire les résultats dans un fichier au lieu de les afficher à l'écran.\n");
        printf("-h\n\tPour afficher ceci\n");
    }
    return 0;
}