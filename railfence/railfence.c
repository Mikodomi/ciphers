#include "../misc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* encrypt(const char* text, int rails) {
    const int size = strlen(text);
    char* cipher = malloc(size);       
    int cipher_ind = 0;
    int jump = 2*(rails-1);
    for (int i = 0; i<rails; i++) {
        int index = i;
        while (index < size && cipher_ind < size) {
            cipher[cipher_ind] = text[index];
            index += jump;
            cipher_ind++;
            if (text[index] == '\n') break;
            if (i > 0 && i < rails-1 && index < size && cipher_ind < size) {
                cipher[cipher_ind] = text[index]; 
                index += (2*(rails-1) - jump);
                cipher_ind++;
                if (text[index] == '\n') break;
            }
        }
        jump -= 2;
        if (jump == 0) {
            jump = 2*(rails-1);
        }
    }
    return cipher;
}

char* decrypt(const char* text, int rails) {
    const int size = strlen(text);
    char* cipher = malloc(size);       
    int index = 0;
    int jump = 2*(rails-1);
    for (int i = 0; i<rails; i++) {
        int cipher_ind = i;
        while (index < size && cipher_ind < size) {
            cipher[cipher_ind] = text[index];
            cipher_ind += jump;
            index++;
            if (text[index] == '\n') break;
            if (i > 0 && i < rails-1 && index < size && cipher_ind < size) {
                cipher[cipher_ind] = text[index]; 
                cipher_ind += (2*(rails-1) - jump);
                index++;
                if (text[index] == '\n') break;
            }
        }
        jump -= 2;
        if (jump == 0) {
            jump = 2*(rails-1);
        }
    }
    return cipher;
}

int main (int argc, char** argv) {
   // if (argc < 2) { //TODO: EVERYWHERE COOL FLAGS
   //     printf("\tUsage: \n\t\t-e - encrypt  \n\t\t-d - decrypt\n");
   //     return 0;
   // }
    FILE* input = fopen("res3", "r");
    if (!input) return 1;
    char text[1024];
    char* success = fgets(text, 1024, input);
    if (success != text) {
        printf("reading from file failed.");
        fclose(input);
        return 0;
    }
    char* res = decrypt(text, 3);
    printf("%s", res);
    free(res);
    fclose(input);
    return 0;
}
