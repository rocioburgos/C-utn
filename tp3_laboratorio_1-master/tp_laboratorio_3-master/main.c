#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>


int main()
{
    char seguir='s';
    int opcion=0;
    eMovie film;


    while(seguir=='s')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3-Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("Ingrese numero de opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarPelicula(film);
            break;
        case 2:
            borrar(film);
            break;
        case 3:
            modificacion(film);
            break;
        case 4:
            generarPagina(film);

            break;
        case 5:
            _fcloseall();
            printf("Archivos cerrados");
            seguir = 'n';
            break;
        default:
            printf("Ese numero de opcion no exsite.");
            break;
        }
    }

    return 0;
}





