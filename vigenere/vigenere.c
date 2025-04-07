#include "../misc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
char* encrypt(const char* text, const char* key) {
    const int size = strlen(text); 
    const int key_size = strlen(key);
    char* cipher = malloc(size);
    if (!cipher) return NULL;
    int key_index = 0;
    for (int i = 0; i<size; i++) {
        char value = text[i];
        if (!is_letter(text[i])) {
            cipher[i] = value;
            continue;
        }

        cipher[i] = shift(value, num_in_alphabet(key[key_index]));
        key_index = (key_index + 1) % key_size;
    }
    return cipher;
}

char* decrypt(const char* text, const char* key) {
    const int size = strlen(text); 
    const int key_size = strlen(key);
    char* cipher = malloc(size);
    if (!cipher) return NULL;
    int key_index = 0;
    for (int i = 0; i<size; i++) {
        char value = text[i];
        if (!is_letter(text[i])) {
            cipher[i] = value;
            continue;
        }
        cipher[i] = shift(value, 26-num_in_alphabet(key[key_index]));
        key_index = (key_index + 1) % key_size;
    }
    return cipher;
    return cipher;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("\tUsage: \n\t\t-e - encrypt  \n\t\t-d - decrypt\n");
        return 0;
    }
    FILE* input = fopen("input.txt", "r");
    if (!input) return 1;
    char text[1024];
    char* success = fgets(text, 1024, input);

    if (success != text) {
        printf("reading from file failed.");
        fclose(input);
        return 0;
    }

    char* res = decrypt(text, "METH");
    if (res) {
        printf("%s", res);
        free(res);
    }
    fclose(input);
    return 0;
}
