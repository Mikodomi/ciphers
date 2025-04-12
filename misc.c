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

int is_number(char value) {
    return ((value >= '0') && (value <= '9'));
}

int is_alphanumeric(char value) {
    return is_number(value) || is_letter(value);
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

char letter_in_alphabet(int num) {
    if (num > 25 || num < 0) {
        return '.';
    }
    return (char)(num+'A'); 
}

int polybius_coords(char value) {
    int num = num_in_alphabet(value);
    if (num >= num_in_alphabet('j')) num--; //i and j are the same in polybius square
    return ((num/5)+1)*10 + (num%5) + 1;
}

char polybius_letter(int coords) {
    int in_alpha = (coords % 10) + ((coords/10)-1)*5 - 1;

    if (in_alpha >= num_in_alphabet('j')) in_alpha++;

    return letter_in_alphabet(in_alpha);
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
