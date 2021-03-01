#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 100

void copy_byte_by_byte(FILE * fromptr, FILE * toptr){
    char achar;
    // Read one byte at a time
    while (fread(&achar, sizeof(char), 1, fromptr) == 1) {
        fwrite(&achar, sizeof(char), 1, toptr);
    }

}

void copy_chunk (FILE * fromptr, FILE * toptr){
    char buffer [BUFFERSIZE];
    int elem_read;

    // Read one chunk of bytes at a time    
    while (!feof(fromptr)) {
        elem_read = fread(buffer, sizeof(char), BUFFERSIZE, fromptr);
        fwrite(buffer, sizeof(char), elem_read, toptr);
    }

}

int main(int argc, char * argv[]){
    char * fromfilename, * tofilename;
    FILE * fromptr, * toptr;
    char * buffer;
    long size_of_file;
    int elem_read;

    if (argc != 3){
        printf("Wrong number of parameters!\n");
        return EXIT_FAILURE;
    }

    fromfilename = argv[1];
    tofilename = argv[2];

    // Open file fromfilename for reading
    fromptr = fopen(fromfilename, "r");

    if (fromptr == NULL){
        printf("File %s not found!\n", fromfilename);
        return EXIT_FAILURE;
    }

    // Open file tofilename for writing
    toptr = fopen(tofilename, "w");

    if (toptr == NULL){
        printf("File %s could not be opened for writing!\n", tofilename);
        return EXIT_FAILURE;
    }

    // Get the last position in the file, which is the total number of bytes in the file
    fseek(fromptr, 0, SEEK_END);
    size_of_file = ftell(fromptr);
    rewind(fromptr);

    buffer = (char *) malloc (sizeof(char) * size_of_file);

    // Read entire file as one chunk   
    elem_read = fread(buffer, sizeof(char), size_of_file, fromptr);
    fwrite(buffer, sizeof(char), elem_read, toptr);
 
    // Report result
    printf("File copied!\n"); 

    fclose(fromptr);
    fclose(toptr);
}
