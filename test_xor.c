//
// Created by TONY DE FREITAS on 25/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xor.h"

typedef unsigned char byte;

int main(int argc, char** argv) {
    FILE *decrypted_text = NULL;
    FILE *encrypted_text = NULL;
    decrypted_text = fopen("texte.txt", "w+");
    fputs((const char*) argv[1], decrypted_text);
    fclose(decrypted_text);
    char* key = argv[2];
    char encrypted_sentence [200] = "";
    char decrypted_sentence [200] = "";

    cryptage("texte.txt", "crypted.txt", key); // Cryptage du message
    encrypted_text = fopen("crypted.txt", "r");
    decrypted_text = fopen("texte.txt", "r");
    fgets(encrypted_sentence, 200, encrypted_text);
    fgets(decrypted_sentence, 200, decrypted_text);
    fclose(encrypted_text);
    fclose(decrypted_text);

    printf("Texte non crypte : %s\nTexte crypte : %s\n", decrypted_sentence, encrypted_sentence);

    cryptage("crypted.txt", "texte.txt", key); // Cryptage du message une deuxième fois
    encrypted_text = fopen("crypted.txt", "r");
    decrypted_text = fopen("texte.txt", "r");
    fgets(encrypted_sentence, 200, encrypted_text);
    fgets(decrypted_sentence, 200, decrypted_text);
    fclose(encrypted_text);
    fclose(decrypted_text);

    printf("Texte crypte : %s\nTexte decrypte : %s\n", encrypted_sentence, decrypted_sentence);

    return 0;
}