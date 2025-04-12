#ifndef MISC_FUNCTIONS_H
#define MISC_FUNCTIONS_H

int is_letter(char value);
int is_number(char value);
int is_upper(char value);
int is_lower(char value);
int is_alphanumeric(char value);

int num_in_alphabet(char value); // 0-indexed
char letter_in_alphabet(int num); // 0-indexed

int polybius_coords(char value); // not 0-indexed
char polybius_letter(int coords); // not 0-indexed

char shift(char value, int key);
#endif
