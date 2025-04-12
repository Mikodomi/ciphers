#include "../misc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* encrypt(const char* text, int key) {
    const int size = strlen(text);
    char* result = malloc(size+1);
    if (!result) return NULL;

    int res_ind = 0;
    for (int i = 0; i<key; i++) {
        int text_ind = i;
        while (text_ind < size && res_ind < size) {
            result[res_ind] = text[text_ind];
            text_ind += key;
            res_ind++;
        }
    }

    result[size] = '\0';
    return result;
}

char* decrypt(const char* text, int key) {
    const int size = strlen(text);
    char* result = malloc(size+1);
    if (!result) return NULL;

    int text_ind = 0;
    for (int i = 0; i<key; i++) {
        int res_ind = i;
        while (text_ind < size && res_ind < size) {
            result[res_ind] = text[text_ind];
            res_ind += key;
            text_ind++;
        }
    }

    result[size] = '\0';
    return result;
}

// very slow and memory inefficient - use wisely
void visual_rep(const char* text, int key) {
    const int size = strlen(text);
    const int temp_size = ((size+1)*key); // size+1 for \n on every line and \0 on last line
    char* temp = malloc(temp_size); 
    if (!temp) return;
    for (int i = 0; i<temp_size; i++) {
        if (i > 0 && (i+1)%(size+1) == 0) {
            temp[i] = '\n';
            continue;
        }
        temp[i] = '.';
    }

    for (int i = 0; i<size; i++) {
        temp[(i+(i*(size+1)))%temp_size] = text[i];
    }
    temp[temp_size-1] = '\0';
    printf("%s\n", temp);
    free(temp);
}

int main() {
    visual_rep("NIECHSIEDZIEJEWOLANIEBA", 3);
    char* result = encrypt("NIECHSIEDZIEJEWOLANIEBA", 3);
    char* res2 = decrypt("NCIZJONBIHEIELIAESDEWAE", 3);

    printf("%s\n", result);
    printf("%s\n", res2);

    free(result);
    return 0;
}

