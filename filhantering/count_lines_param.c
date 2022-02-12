#include <stdio.h>
#include <stdlib.h>

#define LINEBUFFERSIZE 256

int main(int argc, char * argv[]){
    char * filename;
    char buffer [LINEBUFFERSIZE];
    FILE * fileptr;
    int noflines;

    if (argc != 2){
        printf("Wrong number of parameters!\n");
        return EXIT_FAILURE;
    }

    filename = argv[1];

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

    fclose(fileptr);
}
