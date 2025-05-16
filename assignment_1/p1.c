#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    for(int i = 1; i < 101; i++){
        char word[9] = "        ";
        i % 15 == 0 ? strcpy(word, "fizzbuzz") : i % 5 == 0 ? strcpy(word, "buzz") : i % 3 == 0 ? strcpy(word, "fizz") : strcpy(word, "");
        printf("%d %s\n", i, word);
    }
}