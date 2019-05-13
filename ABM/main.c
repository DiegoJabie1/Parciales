
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

    ePelicula lista[TAMPELICULAS];
    eActores actores[TAMACTORES];
    eGeneros generos[TAMGENEROS];

    inicializarPeliculas(lista,TAMPELICULAS);

    hardcodearDatosPeliculas(lista,21);

    hardcodearGeneros(generos,TAMGENEROS);

    hardcodearActores(actores,TAMACTORES);


    do
    {
        opcion = menuDeOpciones("\n  DIEGOPELICULAS\n\nOpciones disponibles:\n\n1.Alta\n2.Modificar\n3.Dar de baja\n4.Listar actores/peliculas\n5.Informar actor con mas peliculas\n6.Informar genero con mas peliculas\n7.Informar anio con mas peliculas\n8.Informar mes con mas peliculas\n9.Mostrar cantidad de peliculas por actor\n10.Mostrar cantidad de peliculas por genero\n11.Mostrar actores con peliculas\n12.Mostrar generos con peliculas\n15.Salir\n\nElija una opcion:");
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
            buscarActorConMasPeliculas(actores,TAMACTORES,lista,TAMPELICULAS);
            break;

        case 6:
            buscarGeneroConMasPeliculas(generos,TAMGENEROS,lista,TAMPELICULAS);
            break;

        case 7:
            buscarAnioConMasPeliculas(lista,TAMPELICULAS);
            break;

        case 8:
            buscarMesConMasPeliculas(lista,TAMPELICULAS);
            break;

        case 9:
            mostrarCantPeliculasPorActor(lista,TAMPELICULAS,actores,TAMACTORES);
            break;

        case 10:
            mostrarCantPeliculasPorGenero(lista,TAMPELICULAS,generos,TAMGENEROS);
            break;
        case 11:
            mostrarActoresConPeliculas(lista,TAMPELICULAS,actores,TAMACTORES,generos,TAMGENEROS);
            break;
        case 12:
            mostrarGenerosConPeliculas(lista,TAMPELICULAS,actores,TAMACTORES,generos,TAMGENEROS);
            break;
        }
    }
    while(opcion!=15);
    return 0;
}
