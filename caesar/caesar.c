#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "misc.h"

char* caesar(const char* input, int key) { // freed by caller!
    const uint32_t size = strlen(input);
    char* result = malloc(strlen(input));
    for (uint32_t i = 0; i<size; i++) {
        char value = input[i];
        if (!is_letter(value)) {
            result[i] = value;
            continue;
        }
        result[i] = shift(value, key);
    }
    return result;
}

int main() {
    char test[] = "My name is Walter Hartwell White. I live at 308 Negra Arroyo Lane, Albuquerque, New Mexico, 87104. To all law enforcement entities, this is not an admission of guilt. I am speaking to my family now. Skyler, you are the love of my life. I hope you know that. Walter Jr., you're my big man. There are going to be some things that you'll come to learn about me in the next few days. But just know that no matter how it may look, I only had you in my heart. Goodbye.";
    char* res = caesar(test, 3); 
    printf("%s", res);
    free(res);
    return 0;
}
