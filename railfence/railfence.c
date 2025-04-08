#include "../misc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* encrypt(const char* text, int rails) {
    
}

char* decrypt(const char* text, int rails) {

}

int main (int argc, char** argv) {
   // if (argc < 2) { //TODO: EVERYWHERE COOL FLAGS
   //     printf("\tUsage: \n\t\t-e - encrypt  \n\t\t-d - decrypt\n");
   //     return 0;
   // }
    FILE* input = fopen("input.txt", "r");
    if (!input) return 1;
    char text[1024];
    char* success = fgets(text, 1024, input);
    if (success != text) {
        printf("reading from file failed.");
        fclose(input);
        return 0;
    }

    fclose(input);
    return 0;
}
