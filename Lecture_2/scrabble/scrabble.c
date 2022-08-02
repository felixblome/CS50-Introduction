#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void) {
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 == score2) {
        printf("Tie!\n");
    }
    else if(score1 > score2) {
        printf("Player 1 wins!\n");
    }
    else {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word) {
    // TODO: Return score for string "word"
    int l = strlen(word);
    int s = 0;
    for(int i = 0; i < l; i++) {
        if(isupper(word[i])) {
            s += POINTS[word[i] - 65]; // substract 65 (position from ASCII table) from word[i] to reach the right amount of points in array
        }
        else if(islower(word[i])) {
            s += POINTS[word[i] - 97]; // substract 97 (position from ASCII table) from word[i] to reach the right amount of points in array
        }
    }
    printf("%i\n", s);
    return s;
}

