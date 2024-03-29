#include <stdio.h>
#include "actores.h"
#include "generos.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char nombre[50];
    int idGenero;
    int idActor;
    int estado;

    int anio;
    int mes;
    int dia;

} ePelicula;

typedef struct
{

int idGenero;
int contador;
char descripcion[50];

}eAuxiliar;

int menuDeOpciones(char[]);

void inicializarPeliculas(ePelicula[], int);

int buscarLibre(ePelicula[], int);

void hardcodearDatosPeliculas(ePelicula[], int);

int idAutoIncremental(ePelicula[], int);

void cargarPelicula(ePelicula[], int ,eGeneros[], int, eActores[], int);

void mostrarPelicula(ePelicula, eGeneros[], int, eActores[], int);

void mostrarListaPeliculas(ePelicula[], int, eGeneros[], int, eActores[], int);

void mostrarListaPeliculasAux(ePelicula[], int, eGeneros[], int, eActores[], int);

void modificarPelicula(ePelicula[], int, eGeneros[],int,eActores[],int);

void borrarPelicula(ePelicula[], int, eGeneros[], int, eActores[], int);

void buscarGeneroConMasPeliculas(eGeneros[], int, ePelicula[],int);

void ordenarPeliculasPorFecha(ePelicula[],int);

