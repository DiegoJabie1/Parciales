#include "string.h"
#include "Empleado.h"
#include "funciones.h"

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    while (opcion>10)
    {
    system("cls");
    printf("Opcion invalida, intente nuevamente!!%s",mensaje);
    scanf("%d",&opcion);
    }

    return opcion;
}

void inicializarPeliculas(ePelicula lista[], int tp)
{
    int i;
    for(i=0; i<tp; i++)
    {
        lista[i].estado = LIBRE;
    }
}

int buscarLibre(ePelicula lista[], int tp)
{
    int i;
    int index=-1;
    for(i=0; i<tp; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void hardcodearDatosPeliculas(ePelicula lista[], int tp)
{
    int i;

    int ids[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    char nombres[][50]= {"Avengers EndGame", "Thor", "Cellular", "Men in Black 4", "IronMan", "13 Going on 30", "Lucy", "Nace una estrella","¿Dime con cuantos?", "Guardianes de la galaxia", "A perfect murder", "La isla", "Que paso ayer", "Home Alone 3", "Deadpool", "Sherlock Holmes", "Men in Black 3", "Avengers infinity War", "Grandes esperanzas", "SWAT" ,"XxX"};
    int genero[]={1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int actores[]={2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};

    int anios[]={2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int meses[]={4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int dias[]={20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};

    for(i=0; i<tp; i++)
    {
        lista[i].id = ids[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].estado = OCUPADO;
        lista[i].idGenero = genero[i];
        lista[i].idActor=actores[i];
        lista[i].anio=anios[i];
        lista[i].mes=meses[i];
        lista[i].dia=dias[i];
    }

}

void hardcodearGeneros(eGeneros generos[],int tp)
{
    int i;
    int idgeneros[]={1,2,3,4,5};
    char descripciongeneros[][20]={"Accion", "Comedia","Drama", "Romance", "Terror"};

    for(i=0; i<tp; i++)
    {
        generos[i].idGenero=idgeneros[i];
        strcpy(generos[i].descripcion,descripciongeneros[i]);
    }
}

void hardcodearActores(eActores actores[],int ta)
{
    int i;
    int idActores[]={1,2,3,4,5,6,7,8,9,10};
    char nacionalidadActores[][50]={"Argentina", "EEUU","Canada", "EEUU","Argentina", "EEUU","Canada","Argentina","EEUU","Canada"};
    char nombreActores[][50]={"Scarlett Johansson", "Robert Downey Jr", "Mark Ruffalo","Chris Evans","Chris Hemsworth","Samuel Jackson","Gwyneth Paltrow","Paul Rudd","Bradley Cooper","Josh Brolin"};

    for(i=0; i<ta; i++)
    {
        actores[i].idActor=idActores[i];
        strcpy(actores[i].nacionalidadActor,nacionalidadActores[i]);
        strcpy(actores[i].nombreActor,nombreActores[i]);
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

void cargarPelicula(ePelicula lista[],int tp,eGeneros generos[], int tg, eActores actores[],int ta)
{
    int i;
    i = buscarLibre(lista, tp);

    if(i!=-1)
    {
        printf("\nIngrese nombre de la pelicula: ");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("\n");
        mostrarGeneros(generos,tg);
        printf("\nIngrese genero: ");
        scanf("%d",&lista[i].idGenero);
        while(lista[i].idGenero>5||lista[i].idGenero<0)
            {
                printf("\nGenero no valido. Reingrese genero: ");
                scanf("%d",&lista[i].idGenero);
            }


        printf("\n");
        mostrarActores(actores,ta);
        printf("\nIngrese actor: ");
        scanf("%d",&lista[i].idActor);
        while(lista[i].idActor>10||lista[i].idActor<0)
            {
                printf("\nActor no valido. Reingrese actor: ");
                scanf("%d",&lista[i].idActor);
            }

        printf("\n");

        lista[i].anio=(pedirEntero("anio",1900,2019));

        printf("\n");

        lista[i].mes=(pedirEntero("mes",1,12));

        printf("\n");

        lista[i].dia=(pedirEntero("dia",1,31));

        lista[i].id=idAutoIncremental(lista,tp);

        lista[i].estado = OCUPADO;

        printf("\n");

        system("cls");
        printf("\n\n\n\n::::::::::::::::::::::::::::");
        printf("\nPELICULA CARGADA CON EXITO.\n");
        printf("::::::::::::::::::::::::::::\n\n\n\n");
        system("pause");
        system("cls");


    }

    else
    {
        printf("No hay espacio");
    }


}

void mostrarPelicula(ePelicula unaPelicula, eGeneros generos[], int tg, eActores actores[], int ta)
{

    char descripcionGenero[20];
    char nombreActores[50];
    char nacionalidadActores[50];

    int i;

    for(i=0; i<tg; i++)
    {
        if(unaPelicula.idGenero==generos[i].idGenero)
        {
            strcpy(descripcionGenero, generos[i].descripcion);

            break;
        }
    }

    for(i=0; i<tg; i++)
    {
        if(unaPelicula.idActor==actores[i].idActor)
        {
            strcpy(nombreActores, actores[i].nombreActor);
            strcpy(nacionalidadActores, actores[i].nacionalidadActor);

            break;
        }
    }



    printf("Fecha: %d/%d/%d-- Nombre: %s -- Genero: %s -- Actor: %s -- Nacionalidad: %s -- Id: %d\n",unaPelicula.anio,unaPelicula.mes,unaPelicula.dia,unaPelicula.nombre,descripcionGenero,nombreActores,nacionalidadActores,unaPelicula.id);

}

void mostrarListaPeliculas(ePelicula lista[], int tp, eGeneros generos[], int tg,eActores actores[], int ta)
{
    int i;

    printf("\n");

    for(i=0; i<tp; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelicula(lista[i], generos, tg, actores, ta);
        }

    }
    printf("\n");
    system("pause");
    system("cls");
}

void mostrarListaPeliculasAux(ePelicula lista[], int tp, eGeneros generos[], int tg,eActores actores[], int ta)
{
    int i;

    printf("\n");

    for(i=0; i<tp; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarPelicula(lista[i], generos, tg, actores, ta);
        }

    }
    printf("\n");
}

void modificarPelicula(ePelicula lista[], int tp, eGeneros generos[],int tg,eActores actores[],int ta)
{
    mostrarListaPeliculasAux(lista, tp, generos, tg,actores,ta);

    int i;
    int id;
    int loEncontro = 0;

    printf("Ingrese el id de la pelicula que desea modificar: ");
    scanf("%d", &id);

    for(i=0; i<tp; i++)
    {
        if(id == lista[i].id)
        {

            loEncontro = 1;
            break;//modifcar
        }

    }

    if(loEncontro==0)
    {
        printf("\nNO EXISTE PELICULA CON TAL ID.\n\n");
    }
    system("pause");

    system("cls");


}

void borrarPelicula(ePelicula lista[], int tp, eGeneros generos[], int tg,eActores actores[], int ta)
{

    mostrarListaPeliculasAux(lista,tp,generos,tg,actores,ta);

    int i;
    int id;
    int loEncontro = 0;
    printf("Ingrese el id de la pelicula a dar de baja: ");
    scanf("%d", &id);

    for(i=0; i<tp; i++)
    {
        if(id == lista[i].id)
        {

            lista[i].estado = LIBRE;


            loEncontro = 1;
            break;//modifcar
        }

    }

    if(loEncontro==0)
    {
        printf("\nNO EXISTE PELICULA CON TAL ID.\n\n");
    }
    else
    {
        printf("\nPELICULA DADA DE BAJA CON EXITO.\n\n");
    }
    system("pause");
    system("cls");
}

void buscarGeneroConMasPeliculas(eGeneros generos[], int tg, ePelicula peliculas[],int te)
{
    eAuxiliar aux[tg];

    int i;
    int j;
    int flag=0;
    int maximo=0;

    for(i=0; i<tg; i++)
    {
        aux[i].idGenero=generos[i].idGenero;
        strcpy(aux[i].descripcion,generos[i].descripcion);
        aux[i].contador=0;
    }

    for(i=0; i<tg; i++)
    {
        for(j=0; j<te; j++)
        {
            if(aux[i].idGenero==peliculas[j].idGenero)
            {
                aux[i].contador++;
            }
        }
    }
    for(i=0;i<tg;i++)
        {
        if(flag==0||aux[i].contador>maximo)
            {
                maximo=aux[i].contador;
                flag=1;
            }
        }

    for(i=0;i<tg;i++)
        {
            if(aux[i].contador==maximo)
                {
                    printf("Genero %s\n",aux[i].descripcion);
                }
        }
}

int idAutoIncremental(ePelicula lista[], int tp)
{
    int retorno = 0;
    int i;
    if(tp > 0 && lista != NULL)
    {
        for(i=0; i<tp; i++)
        {
            if(lista[i].estado == 1)
            {
                if(lista[i].id > retorno)
                {
                    retorno = lista[i].id;
                }
            }
        }
    }
    return retorno+1;
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

void ordenarPeliculasPorFecha(ePelicula peliculas[],int tp)
{
    int i;
    int j;

    ePelicula auxiliar;

    for(i=0;i<tp-1;i++)
    {
        for(j=i+1;j<tp;j++)
        {
            if(peliculas[i].anio>peliculas[j].anio)
            {
                auxiliar=peliculas[i];
                peliculas[i]=peliculas[j];
                peliculas[j]=auxiliar;

            }
        }
    }
}


