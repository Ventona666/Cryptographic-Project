//
// Created by TONY DE FREITAS on 20/11/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void cryptage(char* text_to_encode, char* text_encoded, char* key){
    FILE* text = NULL;
    FILE* text2 = NULL;
    text = fopen(text_to_encode, "r");
    text2 = fopen(text_encoded, "w");

    if (text != NULL){
        byte byte_to_encode;
        byte byte_encoded;
        int i = 0;
        byte_to_encode = fgetc(text);
        while ((char) byte_to_encode != EOF){
            if (i >= strlen(key)){
                i=0;
            }
            printf("%d ^ %d\n", byte_to_encode, key[i]);
            byte_encoded = byte_to_encode ^ (byte) key[i];
            fputc((char) byte_encoded, text2);
            i++;
            byte_to_encode = fgetc(text);
        }
        fclose(text);
        fclose(text2);
    }
    else{
        printf("Le fichier à encoder n'est pas lisible !");
    }
}

int __attribute__((weak)) main(int argc , char** argv) {
    cryptage(argv[1], argv[2], argv[3]);
    return 0;
}
