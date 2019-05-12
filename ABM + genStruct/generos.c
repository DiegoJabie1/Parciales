#include "funciones.h"
#include "generos.h"
#include "string.h"

void hardcodearGeneros(eGeneros generos[],int tp)
{
    int i;
    int idgeneros[]={1,2,3,4,5};
    char descripciongeneros[][50]={"Accion", "Comedia","Drama", "Romance", "Terror"};

    for(i=0; i<tp; i++)
    {
        generos[i].idGenero=idgeneros[i];
        strcpy(generos[i].descripcion,descripciongeneros[i]);
    }
}

void mostrarGeneros(eGeneros generos[], int tg)
{
int i;
for(i=0;i<tg;i++)
    {
        printf("%d.\t%s\n",generos[i].idGenero,generos[i].descripcion);
    }
}
