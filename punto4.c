#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char **nombres;
    int cant;
    char *buffer;
    buffer = (char *)malloc(sizeof(50)*sizeof(char));


    printf("\nIndique la cantidad de nombres a ingresar: ");
    scanf("%d", &cant);
    fflush(stdin);
    
    nombres = (char **)malloc(cant*sizeof(char*));


    for (int i = 0; i < cant; i++){

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


    free(nombres);
    free(buffer);
    return 0;
}