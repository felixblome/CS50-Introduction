#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./recover FILE_NAME\n");
        return 1;
    }
        FILE *file = fopen(argv[1], "r");
        FILE *img = NULL;
        BYTE buffer[BLOCK_SIZE];
        int counter = 0;
        char filename[8];

        while(fread(buffer, BLOCK_SIZE, 1, file) == 1) {
             // check if first four bytes equal to .jpg header => if yes, all .jpg are adjacent from now on
            if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
                // close previous img unless it is not the first img (counter != 0)
                if(counter != 0) {
                    fclose(img);
                }
                // write data to each img
                sprintf(filename, "%03i.jpg", counter++);
                img = fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
            // write data to img
            else if(counter > 0) {
                fwrite(buffer, BLOCK_SIZE, 1 , img);
            }
        }
        fclose(file);
        fclose(img);
}