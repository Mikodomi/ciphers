#include "misc.h"
#include <stdio.h>

int main() {
    char value = 'j';
    printf("%d\n", num_in_alphabet(value));
    printf("%c\n\n", letter_in_alphabet(25));

    printf("%d\n", polybius_coords(value));
    printf("%c\n", polybius_letter(25));

    return 0;
}
