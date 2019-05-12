
#include <stdlib.h>
#include "Empleado.h"
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
        opcion = menuDeOpciones("  DIEGOPELICULAS\n\nOpciones disponibles:\n\n1.Alta\n2.Baja\n3.Modificar\n4.Listar actores/peliculas\n6.Informar genero con mas peliculas.\n10.Salir\n\nElija una opcion:");
        switch(opcion)
        {
        case 1:
            cargarPelicula(lista,TAMPELICULAS, generos,TAMGENEROS,actores,TAMACTORES);
            break;

        case 2:
            borrarPelicula(lista, TAMPELICULAS,generos, TAMGENEROS,actores,TAMACTORES);
            break;

        case 3:
            modificarPelicula(lista, TAMPELICULAS, generos, TAMGENEROS,actores,TAMACTORES);
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

            break;

        case 6:
            buscarGeneroConMasPeliculas(generos,TAMGENEROS,lista,TAMPELICULAS);
            break;

        }
    }
    while(opcion!=10);
    return 0;
}
