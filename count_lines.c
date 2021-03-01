#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 80
#define LINEBUFFERSIZE 256

int main(){
    char filename [BUFSIZE];
    char buffer [LINEBUFFERSIZE];
    FILE * fileptr;
    int noflines;

    printf ("Give filename: ");

    // Read filename from stdin
    if (fgets(filename, BUFSIZE, stdin) == NULL){
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }

    // Remove newline character at end of filename
    for (int i = 0; i < BUFSIZE; i++){
        if (filename[i] == '\n'){
            filename[i] = '\0';
        }
    }

    // Open file filename for reading
    fileptr = fopen(filename, "r");

    if (fileptr == NULL){
        printf("File %s not found!\n", filename);
        return EXIT_FAILURE;
    }

    // Count number of lines
    noflines = 0;
    while (!feof(fileptr)){
        fgets(buffer, LINEBUFFERSIZE, fileptr);
        noflines++;
    }

    // Report result
    printf("%s contains %d lines.\n", filename, noflines); 

}
