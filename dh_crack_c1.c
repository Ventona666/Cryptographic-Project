//
// Created by TONY DE FREITAS on 02/12/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dh_crack.h"

int crack_c1(char * file_name_in, t_tab_keys tab_keys, int key_size){
    FILE* file = NULL;
    file = fopen(file_name_in, "r");
    byte encrypted_char = '0';
    byte potential_decrypted_char = '0';
    int h,i,j=0;
    if (file != NULL){
        do {
            encrypted_char = fgetc(file);
            if (j >= key_size){
                j = 0;
            }
            if ((char) encrypted_char != EOF) {
                for (i = 0; i < 10 && (i<1 || tab_keys.tab_keys[j][i] != '0'); i++) {
                    potential_decrypted_char = encrypted_char ^ tab_keys.tab_keys[j][i];
                    if (!ispunct(potential_decrypted_char) && !isalnum(potential_decrypted_char) && !isspace(potential_decrypted_char)) {
                        for (h = i; h < 9; h++) {
                            tab_keys.tab_keys[j][h] = tab_keys.tab_keys[j][h + 1];
                        }
                        tab_keys.tab_keys[j][9] = '0';
                        i--;
                    }
                }
            }
            j++;
        } while ((char) encrypted_char != EOF);
    }

    fclose(file);
    return 0;
}
