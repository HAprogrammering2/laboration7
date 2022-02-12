#include <stdio.h>

int main (){
    char str[80];

    printf("Give me a string : ");
    scanf ("%s", str);
    printf("You wrote: \"%s\"\n", str);

    fflush(stdin);

    printf("Give me another string : ");
    scanf ("%s", str);
    printf("You wrote: \"%s\"\n", str);

}
