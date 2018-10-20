#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "utn.h"

int main()
{
    ArrayList* lista=al_newArrayList();
    ArrayList* listaRepetidos=al_newArrayList();
    ArrayList* noRepetidos=al_newArrayList();


    char segui='s';
    int opcion=0;
    int flag=0,flag2=0,flag3=0,flag4=0;
    char yes;

    do
    {
        printf("1)Altas\n2)Modificar\n3)Baja\n4)Completar\n5)Generar y listar\n6)Informar\n7)Salir\n");
        opcion=getInt("Ingrese numero de opcion:");
        switch(opcion)
        {
        case 1:
            if(flag4==0)
            {
                if(cargarDesdeArchivo(lista))
                {
                    printf("Se cargaron los archivos\n");
                }
                else
                {
                    printf("No se pudieron cargar\n");
                }
                flag4=1;
            }

            printf("Desea cargar un nuevo numero? s/n ");
            scanf("%c",&yes);
            if(yes=='s')
            {
                cargarNuevoNumero(lista);
            }


            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                cambiarNum(lista);
            }
            else
            {
                printf("No se cargaron datos.\n");
            }
            break;
        case 3:
            if(flag==1)
            {
                baja(lista);
            }
            else
            {
                printf("No se cargaron datos.\n");
            }
            break;
        case 4:
            if(flag==1)
            {
                completar(lista);
                flag2=1;
                printf("Se completaron los datos.\n");
            }
            else
            {
                printf("No se cargaron datos.\n");
            }
            break;
        case 5:
            if(flag==1 && flag2==1)
            {
                al_sort(lista,ordenar,1);
                dividir(lista,listaRepetidos,noRepetidos);
                sinRepetidos(lista,noRepetidos);
                al_clear(lista);

                printf("Lista de repetidos:\n");
                al_sort(listaRepetidos,ordenar,0);
                mostrarTodos(listaRepetidos);

                printf("Lista de no repetidos:\n");
                al_sort(noRepetidos,ordenar,1);
                mostrarTodos(noRepetidos);

                flag3=1;

            }
            else
            {
                printf("No se cargaron datos o no completo todos los campos\n");
            }
            break;
        case 6:
            if(flag3==1)
            {
                cantPares(listaRepetidos);
                contImpar(listaRepetidos);
                contPrimos(listaRepetidos);
                cantCeros(listaRepetidos);
                printf("\n");
            }
            else
            {
                printf("No se puede realizar porque faltan puntos por realizar.\n");
            }
            break;
        case 7:
            segui='n';
            break;
        default:
            printf("Ese numero de opcion no existe.\n");
            break;
        }

    }
    while(segui=='s');
    return 0;
}
