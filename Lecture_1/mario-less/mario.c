#include <cs50.h>
#include <stdio.h>

int main(void) {

    int input;

    // accepts input as long as the number is not between 1 and 8
    do {
        input = get_int("Height: ");
    }
    while (input > 8 || input < 1);

    for(int i = 0; i < input; i++) { // determines the length of the operation (until i reaches input-value)
        for(int j = input; j >= 1; j--) { // decrements j each iteration, until it equals 1 => j determines the amount of hashes being printed
            if(j > i + 1) {
                printf(" ");
            }
            else{
                printf("#");
            }
        }
        printf("\n"); // after every print of j, a new line begins
    }
}