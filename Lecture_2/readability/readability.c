#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float countletters(string text);
float countwords(string text);
float countsentences(string text);
float calculatelevel(float l, float w, float s);

int main(void) {
    string s = get_string("Type in your text: \n");
    float letters = countletters(s);
    float words = countwords(s);
    float sentences = countsentences(s);
    float level = calculatelevel(letters, words, sentences);

    if(level >= 16) {
        printf("Grade 16+\n");
    }
    else if(level < 1) {
        printf("Grade Before Grade 1\n");
    }
    else {
        printf("Grade %.0f\n", round(level)); // ".0f" removes all decimal places
    }
}

float calculatelevel(float l, float w, float s) {
    float avrletters = l / w * 100;
    float avrsentences = s / w * 100;
    float level = 0.0588 * avrletters - 0.296 * avrsentences - 15.8;
    return level;
}

float countletters(string text) {
    int l = strlen(text);
    int count = 0;
    for(int i = 0; i < l; i++) {
        if(isalpha(text[i])) { // check if alphanumeric symbol
            count++;
        }
    }
    return count;
}

float countwords(string text) {
    int l = strlen(text);
    int count = 0;
    for(int i = 0; i <= l; i++) {
        if(isspace(text[i]) || text[i] == '\0') { // check if white space (' ') or \0 after first word
            count++;
        }
    }
    return count;
}

float countsentences(string text) {
    int l = strlen(text);
    int count = 0;
    for(int i = 0; i < l; i++) {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?') { // simply check for corresponding punctuation
            count++;
        }
    }
    return count;
}
