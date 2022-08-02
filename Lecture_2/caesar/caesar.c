#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool onlydigits(string s);
char encrypt(char c, int key);

int main(int argc, string argv[]) {
    string plaintext;
    char ciphertext;
    if(argc == 2) {
        bool valid = onlydigits(argv[1]);
        int key = atoi(argv[1]);
        if(valid) {
            plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for(int i = 0, n = strlen(plaintext); i < n; i++) {
                ciphertext = encrypt(plaintext[i], key);
                printf("%c", ciphertext);
        }
        printf("\n");
        return 0;
        }
        else {
            return 1;
        }

    }
    else {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool onlydigits(string s) {
    bool valid;
    for(int i = 0, l = strlen(s); i < l; i++) {
        if(isdigit(s[i])) {
            valid = true;
        }
        else {
            valid = false;
        }
    }
    return valid;
}

char encrypt(char c, int key) {
    if(isupper(c)) {
        c -= 65;
        c = (c + key) % 26;
        c += 65;
    }
    else if(islower(c)) {
        c -= 97;
        c = (c + key) % 26;
        c += 97;
    }
    else {
        return c;
    }
    return c;
}

