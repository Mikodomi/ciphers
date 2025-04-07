#include "misc.h"

int is_upper(char value) {
    return ((value >= 'A') && (value <= 'Z'));
}

int is_lower(char value) {
    return ((value >= 'a') && (value <= 'z'));
}

int is_letter(char value) {
    return is_upper(value) || is_lower(value);
}

char shift(char value, int key) {
    char res;    
    if (is_upper(value)) {
        res = (((value - 'A') + key) % 26) + 'A';
    } else if (is_lower(value)) {
        res = (((value - 'a') + key) % 26) + 'a';
    }
    return res;
}

int num_in_alphabet(char value) {
    if (is_upper(value)) {
        return value - 'A';
    }
    if (is_lower(value)) {
        return value - 'a';
    }
    return -1;
}
