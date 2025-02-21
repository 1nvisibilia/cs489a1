#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char file[BUFSIZE] = "";
    strncat(file, argv[1], 256 - 9);
    
    FILE *fd = fopen(file, "r");
    if (!fd) {
        fprintf(stderr, "Can not open the file");
        return -1;
    }
    unsigned long wc = 0;
    while (fgetc(fd) != EOF) {
        wc++;
    }
    fclose(fd);
    printf("%lu\n", wc);
}
