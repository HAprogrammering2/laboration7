#include <stdio.h>

void clear_buffer(){

    while (getchar()!='\n'){
    }
}

// Alternativ med fflush, inte garanterat att funka på stdin
// void clear_buffer(){
//     fflush(stdin);
// }

int main (){
    int day, month, year, fields_read;

    do {
        printf("Give me a date : ");

        // Uppgift 4-5
        // fields_read = scanf ("%d.%d.%d", &day, &month, &year);

        // Uppgift 6
        fields_read = scanf ("%d%*[-./]%d%*[-/.]%d", &day, &month, &year);

        if (fields_read == 3){
            printf("You wrote: %d.%d.%d\n", day, month, year);
        }
        else {
            printf("You did not input the correct number of digits\n");
            clear_buffer();
        }
    } while (fields_read != 3);
}
