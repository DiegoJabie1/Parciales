#include "actores.h"
#include "string.h"
#include "funciones.h"

void hardcodearActores(eActores actores[],int ta)
{
    int i;
    int idActores[]={1,2,3,4,5,6,7,8,9,10};
    char nacionalidadActores[][50]={"Argentina", "EEUU","Canada","EEUU","Argentina","EEUU","Canada","Argentina","EEUU","Canada"};
    char nombreActores[][50]={"Scarlett Johansson","Robert Downey Jr","Mark Ruffalo","Chris Evans","Chris Hemsworth","Samuel Jackson","Gwyneth Paltrow","Paul Rudd","Bradley Cooper","Josh Brolin"};

    for(i=0; i<ta; i++)
    {
        actores[i].idActor=idActores[i];
        strcpy(actores[i].nacionalidadActor,nacionalidadActores[i]);
        strcpy(actores[i].nombreActor,nombreActores[i]);
    }
}

void mostrarActores(eActores actores[], int ta)
{
int i;
for(i=0;i<ta;i++)
    {
        printf("%d.\t%s--%s\n",actores[i].idActor,actores[i].nombreActor,actores[i].nacionalidadActor);
    }
}

void mostrarActoresAux(eActores actores[], int ta)
{
    int i;
    for(i=0; i<ta; i++)
    {
        printf("\n%d.\t%s--%s\n",actores[i].idActor,actores[i].nombreActor,actores[i].nacionalidadActor);
    }
    system("pause");
    system("cls");
}

void ordenarActoresPorPais(eActores actores[],int ta)
{
int i;
int j;
char auxPais[50];
char auxNombre[50];
int auxIdActor;

for(i=0; i<ta-1; i++)
   {
       for(j=i+1; j<ta; j++)
       {
           if((strcmp(actores[i].nacionalidadActor,actores[j].nacionalidadActor))==1)
           {
               auxIdActor = actores[i].idActor;
               actores[i].idActor = actores[j].idActor;
               actores[j].idActor = auxIdActor;


               strcpy(auxPais,actores[i].nacionalidadActor);
               strcpy(actores[i].nacionalidadActor, actores[j].nacionalidadActor);
               strcpy(actores[j].nacionalidadActor, auxPais);

               strcpy(auxNombre,actores[i].nombreActor);
               strcpy(actores[i].nombreActor, actores[j].nombreActor);
               strcpy(actores[j].nombreActor, auxNombre);
           }
       }
   }

}
