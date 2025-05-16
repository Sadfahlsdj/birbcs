#include <stdio.h>
#include <stdlib.h>

char* concat(char *s1, char *s2) { // avoid using strcat for extra credit :D
    size_t len1 = 0, len2 = 0;
    while (s1[len1])
        len1++; // instead of strlen
    while (s2[len2])
        len2++;

    char* result = malloc(len1 + len2 + 1);

    for (size_t i = 0; i < len1; i++) {
        result[i] = s1[i];
    }

    for (size_t i = 0; i < len2; i++) {
        result[len1 + i] = s2[i];
    }

    result[len1 + len2] = '\0'; // Null-terminate
    return result;
}

void strip_scuffed(char *str) {
    // input always comes with a newline, remove it
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
}

int main() {
    char loops_raw[8192], fizz[8192], buzz[8192];
    char *endptr;
    printf("loops: ");
    fgets(loops_raw, sizeof(loops_raw), stdin);
    long loops = strtol(loops_raw, &endptr, 10); // convert to numeric
    if (endptr == loops_raw) {
        printf("Non numeric input %s, exiting\n", loops_raw);
        return 1;
    }
    else if (loops < 1) {
        printf("Input must be a positive integer, exiting\n");
        return 1;
    }

    printf("fizz word: ");
    fgets(fizz, sizeof(fizz), stdin);
    printf("buzz word: ");
    fgets(buzz, sizeof(buzz), stdin);

    strip_scuffed(fizz); // strip fizz & buzz
    strip_scuffed(buzz);
    char *cc = concat(fizz, buzz); // create fizzbuzz word

    for (long i = 1; i < loops + 1; i++) {
        if (i % 15 == 0) {
            printf("%lu %s\n", i, cc);
        }
        else if (i % 5 == 0) {
            printf("%lu %s\n", i, buzz);
        }
        else if (i % 3 == 0) {
            printf("%lu %s\n", i, fizz);
        }
        else
            printf("%lu\n", i);
    }

    free(cc); // :D
}
