#include "funciones.h"
#include "generica.h"
#include "string.h"

void hardcodearGenerica(eGenerica genericas[],int tg)
{
    int i;
    int enteroGenerico[]={1,2,3,4,5};
    char descripcionGenerica[][50]={"Generica 1", "Generica 2","Generica 3", "Generica 4", "Generica 5"};

    for(i=0; i<tg; i++)
    {
        genericas[i].enteroGenerico=enteroGenerico[i];
        strcpy(genericas[i].cadenaGenerica,descripcionGenerica[i]);
    }
}

void mostrarGenerica(eGenerica genericas[], int tg)
{
int i;
for(i=0;i<tg;i++)
    {
        printf("%d.\t%s\n",genericas[i].enteroGenerico,genericas[i].cadenaGenerica);
    }
}
