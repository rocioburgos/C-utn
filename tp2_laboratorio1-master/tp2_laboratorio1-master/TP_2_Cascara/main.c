#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define C 20


int main()
{
    char seguir='s';
    int opcion=0,i;
    EPersona persona[C];

    for(i=0;i<C;i++)
      {
        persona[i].estado= 0;
      }


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("Ingrese un numero de opcion, por favor: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
              darDeAlta(persona,C);
                break;
            case 2:
                darDeBaja(persona,C);
                break;
            case 3:
                ordenaryMostrar(persona, C);
                break;
            case 4:
                grafico(persona,C);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}



