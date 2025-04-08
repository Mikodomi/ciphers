#ifndef MISC_FUNCTIONS_H
#define MISC_FUNCTIONS_H

int is_letter(char value);
int is_number(char value);
int is_upper(char value);
int is_lower(char value);
int is_alphanumeric(char value);

char shift(char value, int key);
int num_in_alphabet(char value); // 0-indexed

#endif
