#include "string.h"
#include "funciones.h"
#include "peliculas.h"

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);
    while (opcion>15)
    {
    system("cls");
    printf("OPCION INVALIDA, INTENTE NUEVAMENTE!!\n%s",mensaje);
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

void cargarPelicula(ePelicula lista[],int tp,eGeneros generos[], int tg, eActores actores[],int ta)
{
    int i;
    i = buscarLibre(lista, tp);

    if(i!=-1)
    {
        printf("\nIngrese titulo de la pelicula: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("\n");

        printf("\nGeneros disponibles:\n\n");
        mostrarGeneros(generos,tg);
        printf("\n");
        lista[i].idGenero=pedirEntero("genero",1,5);

        printf("\nActores disponibles:\n\n");
        mostrarActores(actores,ta);
        printf("\n");
        lista[i].idActor=pedirEntero("actor",1,10);

        printf("\n");
        lista[i].anio=pedirEntero("anio",1900,2019);

        printf("\n");
        lista[i].mes=pedirEntero("mes",1,12);

        printf("\n");
        lista[i].dia=pedirEntero("dia",1,31);

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

    char descripcionGenero[50];
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



    printf("Fecha: %d/%d/%d-- Titulo: %s -- Genero: %s -- Actor: %s -- Nacionalidad: %s -- Id: %d\n",unaPelicula.anio,unaPelicula.mes,unaPelicula.dia,unaPelicula.nombre,descripcionGenero,nombreActores,nacionalidadActores,unaPelicula.id);

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
    int opcion;
    int loEncontro = 0;
    printf("Ingrese el id de la pelicula que desea modificar: ");
    scanf("%d", &id);

    for(i=0; i<tp; i++)
    {
        if(id == lista[i].id&&lista[i].estado==OCUPADO)
        {
            printf("\n1.Modificar titulo\n2.Modificar fecha de estreno\n3.Modificar actor\n\n");
            opcion=pedirEntero("opcion",1,3);
            if(opcion==1)
            {
                pedirCadena("nuevo titulo",lista[i].nombre,50);
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::");
                printf("\nTITULO MODIFICADA CON EXITO.\n");
                printf("::::::::::::::::::::::::::::\n\n\n\n");

            }
            else if(opcion==2)
            {
                lista[i].anio=pedirEntero("nuevo anio",1900,2019);
                lista[i].mes=pedirEntero("nuevo mes",1,12);
                lista[i].dia=pedirEntero("nuevo dia",1,31);
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::");
                printf("\nFECHA MODIFICADA CON EXITO.\n");
                printf("::::::::::::::::::::::::::::\n\n\n\n");

            }
            else
            {
                printf("\nActores disponibles:\n\n");
                mostrarActores(actores,ta);
                printf("\n");
                lista[i].idActor=pedirEntero("nuevo actor",1,10);
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::");
                printf("\nACTOR MODIFICADO CON EXITO.\n");
                printf("::::::::::::::::::::::::::::\n\n\n\n");

            }


            loEncontro = 1;
            break;//modifcar
        }

    }

    if(loEncontro==0)
    {
        printf("\n\n\n\n::::::::::::::::::::::::::::");
        printf("\nNO EXISTE PELICULA CON TAL ID.\n");
        printf("::::::::::::::::::::::::::::\n\n\n\n");
    }
    system("pause");

    system("cls");


}

void borrarPelicula(ePelicula lista[], int tp, eGeneros generos[], int tg,eActores actores[], int ta)
{

    mostrarListaPeliculasAux(lista,tp,generos,tg,actores,ta);

    int i;
    int opcion;
    int id;
    int loEncontro = 0;
    printf("Ingrese el id de la pelicula a dar de baja: ");
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
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::::::::::");
                printf("\nNO EXISTE PELICULA CON TAL ID.\n");
                printf("::::::::::::::::::::::::::::::::::::\n\n\n\n");
    }
    else
    {
        printf("\nSEGURO QUE QUIERE BORRAR LA PELICULA CON EL ID %d?.\n1.SI\n2.NO\n",id);
        opcion=pedirEntero("opcion",1,2);
        if(opcion==1)
            {
                lista[i].estado = LIBRE;
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::::::::::::::::::");
                printf("\nPELICULA ID %d DADA DE BAJA CON EXITO.\n",id);
                printf("::::::::::::::::::::::::::::::::::::::::::::\n\n\n\n");
            }
        else
            {
                system("cls");
                printf("\n\n\n\n::::::::::::::::::::::::::::");
                printf("\nSE HA CANCELADO LA DADA DE BAJA.\n\n");
                printf("::::::::::::::::::::::::::::\n\n\n\n");
            }
    }
    system("pause");
    system("cls");
}

void buscarGeneroConMasPeliculas(eGeneros generos[], int tg, ePelicula peliculas[],int tp)
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
        for(j=0; j<tp; j++)
        {
            if(aux[i].idGenero==peliculas[j].idGenero)
            {
                aux[i].contador++;
            }
        }
    }
    for(i=0; i<tg; i++)
    {
        if(flag==0||aux[i].contador>maximo)
        {
            maximo=aux[i].contador;
            flag=1;
        }
    }

    for(i=0; i<tg; i++)
    {
        if(aux[i].contador==maximo)
        {
            printf("\n\nCon %d peliculas el genero que mas peliculas tiene es: %s.\n\n\n",aux[i].contador,aux[i].descripcion);
        }
    }

    system("pause");
    system("cls");
}

void buscarActorConMasPeliculas(eActores actores[], int ta, ePelicula peliculas[],int tp)
{
    eAuxiliar aux[ta];

    int i;
    int j;
    int flag=0;
    int maximo=0;

    for(i=0; i<ta; i++)
    {
        aux[i].idActor=actores[i].idActor;
        strcpy(aux[i].descripcion,actores[i].nombreActor);
        aux[i].contador=0;
    }

    for(i=0; i<ta; i++)
    {
        for(j=0; j<tp; j++)
        {
            if(aux[i].idActor==peliculas[j].idActor)
            {
                aux[i].contador++;
            }
        }
    }
    for(i=0; i<ta; i++)
    {
        if(flag==0||aux[i].contador>maximo)
        {
            maximo=aux[i].contador;
            flag=1;
        }
    }

    for(i=0; i<ta; i++)
    {
        if(aux[i].contador==maximo)
        {
            printf("\n\nCon %d peliculas el actor que mas peliculas tiene es: %s.\n\n\n",aux[i].contador,aux[i].descripcion);
        }
    }

    system("pause");
    system("cls");
}


void buscarAnioConMasPeliculas(ePelicula peliculas[],int tp)
{

    eAuxiliar aux[tp];

    int i;
    int j;
    int contadorAniosMayorCantidadPeliculas=0;
    int auxAnio=0;
    int flag=0;
    int maximo=0;

    for(i=0; i<tp; i++)
    {
        if(peliculas[i].estado==OCUPADO)
        {
            aux[i].anio=peliculas[i].anio;
            aux[i].contador=0;
        }
    }

    for(i=0; i<tp; i++)
    {
        for(j=0; j<tp; j++)
        {
            if(aux[i].anio==peliculas[j].anio&&peliculas[j].estado==OCUPADO&&peliculas[i].estado==OCUPADO)
            {
                aux[i].contador++;
            }
        }
    }

    for(i=0; i<tp; i++)
    {
        if((flag==0||aux[i].contador>maximo)&&(peliculas[i].estado==OCUPADO))
        {
            maximo=aux[i].contador;
            flag=1;
        }
    }

    for(i=0; i<tp; i++)
    {
        if(aux[i].contador==maximo&&peliculas[i].estado==OCUPADO)
        {
            if(contadorAniosMayorCantidadPeliculas==1&&!(auxAnio==aux[i].anio))
            {
                printf("\n\nY con %d peliculas el siguiente anio que mas peliculas tiene es: %d.\n\n\n",aux[i].contador,aux[i].anio);

                break;
            }
            else if(contadorAniosMayorCantidadPeliculas==0)
            {
                printf("\n\nCon %d peliculas el anio que mas peliculas tiene es: %d.\n\n",aux[i].contador,aux[i].anio);

                auxAnio=aux[i].anio;


            }
        contadorAniosMayorCantidadPeliculas++;

        }
    }

    printf("\n");
    system("pause");
    system("cls");
}

void buscarMesConMasPeliculas(ePelicula peliculas[],int tp)
{
    eAuxiliar aux[tp];

    int i;
    int j;
    int flag=0;
    int maximo=0;


    for(i=0; i<tp; i++)
        {
        if(peliculas[i].estado==OCUPADO)
            {
                aux[i].mes=peliculas[i].mes;
                aux[i].contador=0;
            }
        }

    for(i=0; i<tp; i++)
    {
        for(j=0; j<tp; j++)
        {
            if(aux[i].mes==peliculas[j].mes&&peliculas[i].estado==OCUPADO&&peliculas[j].estado==OCUPADO)
            {
                aux[i].contador++;
            }
        }
    }

    for(i=0; i<tp; i++)
    {
        if((flag==0||aux[i].contador>maximo)&&(peliculas[i].estado==OCUPADO))
        {
            maximo=aux[i].contador;
            flag=1;
        }
    }

    for(i=0; i<tp; i++)
    {
        if(aux[i].contador==maximo&&peliculas[i].estado==OCUPADO)
        {
            printf("\n\nCon %d peliculas, el que mas peliculas tiene es el mes %d.\n\n\n",aux[i].contador,aux[i].mes);

            break;
        }
    }


    system("pause");
    system("cls");
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

void ordenarPeliculasPorFecha(ePelicula peliculas[],int tp)
{
    int i;
    int j;

    ePelicula auxiliar;

    for(i=0;i<tp-1;i++)
    {
        for(j=i+1;j<tp;j++)
        {
            if(peliculas[i].anio<peliculas[j].anio)
            {
                auxiliar=peliculas[i];
                peliculas[i]=peliculas[j];
                peliculas[j]=auxiliar;

            }
        }
    }
}

void mostrarCantPeliculasPorActor(ePelicula peliculas[], int tp, eActores actores[], int ta)
{
    int contador;
    system("cls");

    for(int i=0; i<ta; i++ )
    {
        contador = 0;
        printf("Actor: %s\n", actores[i].nombreActor);

        for(int j=0; j < tp; j++)
        {
            if(actores[i].idActor == peliculas[j].idActor&&(peliculas[j].estado==OCUPADO) == 1)
            {
                contador++;
            }
        }

        printf("Cantidad de peliculas: %d\n\n", contador);
    }
    system("pause");
    system("cls");
}

void mostrarCantPeliculasPorGenero(ePelicula peliculas[], int tp, eGeneros generos[], int tg)
{
    int contador;
    system("cls");

    for(int i=0; i<tg; i++ )
    {
        contador = 0;
        printf("Generos: %s\n", generos[i].descripcion);

        for(int j=0; j < tp; j++)
        {
            if(generos[i].idGenero == peliculas[j].idGenero &&(peliculas[j].estado==OCUPADO)== 1)
            {
                contador++;
            }
        }

        printf("Cantidad de peliculas: %d\n\n", contador);
    }
    system("pause");
    system("cls");
}

void mostrarActoresConPeliculas(ePelicula peliculas[], int tp, eActores actores[], int ta,eGeneros generos[],int tg)
{

    system("cls");
    for(int i=0; i < ta; i++)
    {
        printf("Actor: %s\nPeliculas:\n", actores[i].nombreActor);
        for(int j=0; j < tp; j++)
        {
            if( (peliculas[j].idActor == actores[i].idActor) &&(peliculas[j].estado==OCUPADO)== 1)
            {
                mostrarPelicula(peliculas[j],generos,tg,actores,ta);
            }
        }

        printf("\n\n");
    }
    system("pause");
    system("cls");
}

void mostrarGenerosConPeliculas(ePelicula peliculas[], int tp, eActores actores[], int ta,eGeneros generos[],int tg)
{

    system("cls");
    for(int i=0; i < tg; i++)
    {
        printf("Genero: %s\nPeliculas:\n", generos[i].descripcion);
        for(int j=0; j < tp; j++)
        {
            if( (peliculas[j].idGenero == generos[i].idGenero) &&(peliculas[j].estado==OCUPADO)== 1)
            {
                mostrarPelicula(peliculas[j],generos,tg,actores,ta);
            }
        }

        printf("\n\n");
    }
    system("pause");
    system("cls");
}
