#include <stdio.h>
#include <stdlib.h>

#define STRINGSIZE 80

int main(int argc, char * argv[]){
    char * fromfilename, * tofilename;
    FILE * fromfileptr, * tofileptr;
    char * buffer;
    int elements_read;
    long end_position;

    if (argc != 3){
        printf("Wrong number of parameters\n");
        return EXIT_FAILURE;
    }

    fromfilename = argv[1];
    tofilename = argv[2];

    fromfileptr = fopen(fromfilename, "rb");
    
    if (fromfileptr == NULL){
        printf("File %s not found!\n", fromfilename);
        return EXIT_FAILURE;
    }

    tofileptr = fopen(tofilename, "wb");

    if (tofileptr == NULL) {
        printf("Could not open file %s for writing.\n", tofilename);
        return EXIT_FAILURE;
    }
    
    // Get total size of file
    fseek(fromfileptr, 0, SEEK_END);
    end_position = ftell(fromfileptr);
    rewind(fromfileptr);
    buffer = (char *) malloc(sizeof(char) * end_position);    
    
    elements_read = fread(buffer, sizeof(char), end_position, fromfileptr);
    fwrite(buffer, sizeof(char), elements_read, tofileptr);

    printf("File copied!\n");
}
