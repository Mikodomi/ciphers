#include "../misc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pair_t {
    int in_alphabet;
    int in_string;
} index_pair;

// get it..? it compares PAIRS...? so it COMPAIRS???
int compair(const void* p1, const void* p2) { 
    return ((*(index_pair*)p1).in_alphabet) - ((*(index_pair*)p2).in_alphabet);
}
char* encode(char* text, char* key) {
    const int key_size = strlen(key);
    const int text_size = strlen(text);
    index_pair* indices = malloc(key_size*sizeof(index_pair));  
    if (!indices) return NULL;
    char* result = malloc(text_size); // freed by caller
    if (!result) {
        free(indices); 
        return NULL;
    }
    for (int i = 0; i<key_size; i++) {
        indices[i].in_alphabet = num_in_alphabet(key[i]);
        indices[i].in_string = i;
    }
    qsort(indices, key_size, sizeof(index_pair), &compair);

    int res_ind = 0;
    for (int i = 0; i<key_size; i++) {
        int text_ind = indices[i].in_string;
        while (text_ind < text_size && res_ind < text_size) {
            result[res_ind] = text[text_ind];
            res_ind++;
            text_ind += key_size;
        }
    }
    free(indices);
    return result;
}

// these for loops may be ugly... but for it to print nicely
// they must not look nicely themselves
void visual_rep(char* text, char* key) {
    const int size = strlen(key);
    for (int i = 0; i < size; i++) {
        printf("%3c", key[i]);
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%3d", num_in_alphabet(key[i]));
    }
    for (int i = 0; text[i] != '\0'; i++) {
        if (i % size == 0) {
            printf("\n");
        }
        printf("%3c", text[i]);
    }
    printf("\n");
}

int main() {
    visual_rep("NIECHSIEDZIEJEWOLANIEBA", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    char* res = encode("NIECHSIEDZIEJEWOLANIEBA", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    printf("%s\n", res);
    free(res);
    return 0;
}
