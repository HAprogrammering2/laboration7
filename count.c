#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 80

int main(){
    char filename [BUFSIZE];
    FILE * fileptr;
    int nofbytes;

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

    // Count number of bytes
    nofbytes = 0;
    while (fgetc(fileptr) != EOF){
        nofbytes++;
    }

    // Report result
    printf("Size of %s is %d bytes.\n", filename, nofbytes); 

    fclose(fileptr);
}
