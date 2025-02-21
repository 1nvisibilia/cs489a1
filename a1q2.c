#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    
#define BUFSIZE 256

int wcWrapAroundQuote(char *newString, char *oldString, size_t size) {
    snprintf(newString, size, "wc -c < \"%s\"", oldString);
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char sized_input[BUFSIZE - 10];
    strncpy(sized_input, argv[1], BUFSIZE - 10);
    char cmd[BUFSIZE];
    wcWrapAroundQuote(cmd, sized_input, BUFSIZE);
    system(cmd);
}
