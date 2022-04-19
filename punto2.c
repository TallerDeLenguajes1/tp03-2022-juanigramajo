#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char *nombres[5];
    char *buffer;

    
    buffer = (char *)malloc(sizeof(60)*sizeof(char));


    for (int i = 0; i < 5; i++){

        printf("Ingrese el nombre [%d]: ", i+1);
        gets(buffer);

        nombres[i] = (char *)malloc((strlen(buffer)+1)*sizeof(char));

        strcpy(nombres[i], buffer);
    }



    printf("\n\n------Nombres------\n");

    for (int j = 0; j < 5; j++){
        printf("\nNombre [%d]: ", j+1);
        puts(nombres[j]);
    }

    
    for (int k = 0; k < 5; k++){
        free(nombres[k]);
    }


    free(buffer);
    return 0;

}