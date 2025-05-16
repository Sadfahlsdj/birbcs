#include <stdio.h>
#include <string.h>
#include <ctype.h>

void rev(char *start, char *end) {
    /*
     * takes in start & end pointers, reverses everything between them (inclusive)
     * intended to be used on subsets of a string which are only chars
     */
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}
int main() {
    char buf[1024];
    FILE *in = fopen("README.md", "r");
    FILE *out = fopen("out.md", "w");
    while (fgets(buf, sizeof(buf), in)) {
        size_t len = strlen(buf);
        char *start = NULL;

        for (size_t i = 0; i < len; i++) {
            if (isalpha(buf[i])) {
                if (start == NULL) {
                    start = &buf[i]; // start a word
                }
            }
            else {
                if (start != NULL) {
                    rev(start, &buf[i - 1]); // reverse alphabetic section
                    start = NULL; // reset
                }
            }
        }
        if (start != NULL) { // in case a word ends the line
            rev(start, &buf[len-1]);
        }
        printf("%s", buf);
    }
    fclose(in);
    fclose(out);
}