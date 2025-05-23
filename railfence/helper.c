#include <stdio.h>
#include "../misc.h"
#include <string.h>
#define RAILS 6

int main() {
    char arr[RAILS][128];
    for (int i = 0; i<RAILS; i++) {
        for (int j = 0; j<128-1; j++) {
            arr[i][j] = '.';
        }
        arr[i][127] = '\0';
    }

    char input[] = "NIECHSIEDZIEJEWOLANIEBA";
    
    printf("%s\n", input);
    const int size = strlen(input);
    int vert = 0;
    int dir = 1;
    int horz = 0;
    for (int i = 0; i < size; i++) {
        if (!is_alphanumeric(input[i])) continue;
        arr[vert][horz] = input[i]; 
        horz++;
        vert += dir;
        if (vert == RAILS-1 || vert == 0) dir *= -1;
    }

    for (int i = 0; i<RAILS; i++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}
