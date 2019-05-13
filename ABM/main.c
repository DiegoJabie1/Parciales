
#include <stdlib.h>
#include "peliculas.h"
#include "funciones.h"
#include "string.h"
#define TAMPELICULAS 1000
#define TAMGENEROS 5
#define TAMACTORES 10



int main()
{
    int opcion;
    int opcionMostrar;
    int opcionInformes;

    ePelicula lista[TAMPELICULAS];
    eActores actores[TAMACTORES];
    eGeneros generos[TAMGENEROS];

    inicializarPeliculas(lista,TAMPELICULAS);

    hardcodearDatosPeliculas(lista,21);

    hardcodearGeneros(generos,TAMGENEROS);

    hardcodearActores(actores,TAMACTORES);


    do
    {
        opcion = menuDeOpciones("\n  DIEGOPELICULAS\n\nOpciones disponibles:\n\n1.Alta\n2.Modificar\n3.Dar de baja\n4.Listar actores/peliculas\n5.Informes\n6.Salir\n\nElija una opcion:");
        switch(opcion)
        {
        case 1:
            cargarPelicula(lista,TAMPELICULAS, generos,TAMGENEROS,actores,TAMACTORES);
            break;

        case 2:
            modificarPelicula(lista, TAMPELICULAS, generos, TAMGENEROS,actores,TAMACTORES);
            break;

        case 3:
            borrarPelicula(lista, TAMPELICULAS,generos, TAMGENEROS,actores,TAMACTORES);
            break;

        case 4:
            printf("\n1.Mostrar peliculas ordenadas por fecha.\n2.Mostrar actores ordenados por pais de origen.\n\nSu opcion:");

            scanf("%d",&opcionMostrar);

            while(opcionMostrar>2||opcionMostrar<0)
            {
                printf("\nOpcion para mostrar invalida. Intente nuevamente: ");
                scanf("%d",&opcionMostrar);
            }

            if(opcionMostrar==1)
            {
                ordenarPeliculasPorFecha(lista, TAMPELICULAS);

                mostrarListaPeliculas(lista, TAMPELICULAS, generos, TAMGENEROS, actores, TAMACTORES);
            }
            else
            {
                ordenarActoresPorPais(actores,TAMACTORES);
                mostrarActoresAux(actores,TAMACTORES);
            }

            break;

        case 5:
            printf("\n1.Mostrar todas las peliculas con genero y actor\n2.Mostrar peliculas cuyo actor sea de EEUU\n3.Mostrar cada genero con sus peliculas\n4.Mostrar cantidad de peliculas por genero\n5.El/los generos con menos peliculas\n\n");
            opcionInformes=pedirEntero("opcion que desea",1,5);
            if(opcionInformes==1)
            {
                mostrarListaPeliculas(lista,TAMPELICULAS,generos,TAMGENEROS,actores,TAMACTORES);
            }
            else if(opcionInformes==2)
            {
                mostrarPeliculasActorEEUU(lista,TAMPELICULAS,actores,TAMACTORES,generos,TAMGENEROS);
            }
            else if(opcionInformes==3)
            {
                mostrarGenerosConPeliculas(lista,TAMPELICULAS,actores,TAMACTORES,generos,TAMGENEROS);
            }
            else if(opcionInformes==4)
            {
                mostrarCantPeliculasPorGenero(lista,TAMPELICULAS,generos,TAMGENEROS);
            }
            else
            {
                buscarGeneroConMenosPeliculas(generos,TAMGENEROS,lista,TAMPELICULAS);
            }

            break;
        }
    }
    while(opcion!=6);
    return 0;
}
