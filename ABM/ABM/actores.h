#include <stdio.h>

typedef struct
{
    int idActor;
    char nombreActor[50];
    char nacionalidadActor[50];

} eActores;

void hardcodearActores(eActores[],int);

void mostrarActores(eActores[],int);

void mostrarActoresAux(eActores[],int);

void ordenarActoresPorPais(eActores[],int);
