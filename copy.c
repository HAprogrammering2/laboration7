#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    char * fromfilename, * tofilename;
    FILE * fromptr, * toptr;
    int achar;

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
        fclose (fromptr);
        return EXIT_FAILURE;
    }

    // Copy from fromptr to toptr 
    while ((achar = fgetc(fromptr)) != EOF){
        fputc(achar, toptr);
    }

    // Report result
    printf("File copied!\n"); 

    fclose(fromptr);
    fclose(toptr);
}
