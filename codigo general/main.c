#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20
#define TAMV 4

typedef struct{
    int id;
    char nombre[20];
    char tipo;
    float efectividad;
}eVacuna;

eVacuna lista[TAMV] = {
    {1, "nombre1", 'a', 23.00},
    {2, "nombre2", 'b', 45.00},
    {3, "nombre3", 'c', 34.00},
    {4, "nombre4", 'a', 25.00}
};

float aplicarAumento(float precio);
int reemplazarCaracteres(char cadena[], char primerCaracter, char segundoCaracter);
int ordenarArray(eVacuna vec[], int len);

int main(){
    float precio = 100;
    float precioCAumento;
    int cantReemplazos = 0;


    printf("Ingrese precio del producto: ");
    scanf("%f", &precio);

    precioCAumento = aplicarAumento(precio);

    printf("\nEl precio final del producto es %.2f", precioCAumento);


    char cadena[TAM] = {"cazar"};
    char primerC = 'c';
    char segundoC = 'a';

    printf("\nIngrese cadena");
    fflush(stdin);
    scanf("%c", &cadena[TAM]);
    cantReemplazos = reemplazarCaracteres(cadena, primerC, segundoC);

    printf("\n\nLa cantidad de veces que se reemplazo: %d", cantReemplazos);

    ordenarArray(lista, TAMV);

    printf("");

    return 0;
}

int ordenarArray(eVacuna vec[], int len){
    int todoOk = 0;
    eVacuna auxVacuna;

    if(vec != NULL && len > 0)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i + 1; j < len; j++)
            {
                if((strcmp(vec[i].tipo, vec[j].tipo) > 0))
                {
                    auxVacuna = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxVacuna;
                }
            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int reemplazarCaracteres(char cadena[], char primerCaracter, char segundoCaracter){
    int longitud = strlen(cadena);
    int cantVeces = 0;


    for(int i = 0; i < longitud; i++){
        if((primerCaracter == cadena[i]) || (segundoCaracter == cadena[i])){
            cantVeces++;
        }
    }

    return cantVeces;
}


float aplicarAumento(float precio){
    float precioConAumento;
    float aumento;

    aumento = (precio * 5) / 100;

    precioConAumento = precio + aumento;

    return precioConAumento;
}
