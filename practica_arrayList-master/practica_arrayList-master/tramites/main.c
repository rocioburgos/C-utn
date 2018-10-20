#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "tramite.h"
int main()
{

    char seguir='s';
    int opcion=0;
    int numTurno=0;
    eTramite* nuevoTramite;

    ArrayList* listaUrgente= al_newArrayList();
    ArrayList* listaRegular= al_newArrayList();
    ArrayList* listaAtendido= al_newArrayList();
    ArrayList* clon=al_newArrayList();

    eTramite* aux;


    int i;

    do
    {
        printf("1)Tramite urgente\n2)Tramite regular\n3)Proximo cliente\n4)Listar\n5)Informar\n6)salir\n7)Sublist\n8)Sublist\n9-Set\n10)Al-contein\n");
        printf("11)clear\n12)push\nIngrese numero de opcion: ");
        scanf("%d",&opcion);
    printf("\n\n");
        switch(opcion)
        {
        case 1:
            nuevoTramite = tramite_turnoUrgente(numTurno);
            if(nuevoTramite != NULL)
            {
                numTurno++;
                listaUrgente->add(listaUrgente,nuevoTramite);

//                aux=(eTramite*)al_get(listaUrgente,0);
//                printf("\n\nTurno: %d\n",aux->turno);
//                printf("\nTramite: %d\n\n",aux->idTramite);
            }
            else
            {
                printf("No se pudo cargar su tramite.");
            }
            break;
        case 2:
            nuevoTramite= tramite_turnoRegular(numTurno);

            if(nuevoTramite != NULL)
            {
                numTurno++;
                listaRegular->add(listaRegular,nuevoTramite);

//                aux=(eTramite*)al_get(listaRegular,0);
//                printf("\n\nTurno: %d\n",aux->turno);
//                printf("\nTramite: %d\n\n",aux->idTramite);
            }
            else
            {
                printf("No se pudo cargar su tramite.");
            }


            break;
        case 3:
            tramite_siguiente(listaUrgente,listaRegular,listaAtendido);
            break;
        case 4:
            tramite_listarPendientes(listaUrgente,listaRegular);
            break;
        case 5:
            al_sort(listaAtendido,tramite_ordenarDNI,0);

            printf("Tramites urgentes atendidos:\n");

            for(i=0; i<al_len(listaAtendido); i++)
            {
                aux=(eTramite*)al_get(listaAtendido,i);
                if(aux->idTramite==100)
                {
                    printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                }
            }

            printf("Tramites regulares atendidos:\n");

            for(i=0; i<al_len(listaAtendido); i++)
            {
                aux=(eTramite*)al_get(listaAtendido,i);
                if(aux->idTramite==102)
                {
                    printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                }
            }
            break;


        case 6:
            seguir='n';
            break;
        case 7:
            clon=al_clone(listaAtendido);

            printf("Lista clonada");
            for(i=0; i<al_len(clon); i++)
            {
                aux=(eTramite*)al_get(clon,i);
                if(aux->idTramite==100)
                {
                    printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                }
            }

            break;
        case 8:

            clon=al_subList(listaAtendido,0,2);
            printf("Lista sub");
            for(i=0; i<al_len(clon); i++)
            {
                aux=(eTramite*)al_get(clon,i);
                if(aux->idTramite==100)
                {
                    printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                }
            }
            break;

        case 9:
       nuevoTramite =(eTramite*) malloc(sizeof(eTramite));
              nuevoTramite->dni=10;
            nuevoTramite->idTramite=100;
            nuevoTramite->turno =58;
            if(al_set(listaAtendido,0,nuevoTramite))
                printf("se seteo");
            break;
        case 10:
            printf("al.contains\n");
//            nuevoTramite =(eTramite*) malloc(sizeof(eTramite));
//            nuevoTramite->dni=10;
//            nuevoTramite->idTramite=100;
//            nuevoTramite->turno =58;
//
//            listaUrgente->add(listaUrgente,nuevoTramite);

            if(!al_containsAll(listaAtendido,listaUrgente))
                printf("No lo contiene");
            else
                 printf("Lo contiene");

            break;
        case 11:
            al_clear(listaAtendido);
            printf("clear");
            break;
        case 12:
            printf("push\n");
             nuevoTramite =(eTramite*) malloc(sizeof(eTramite));
            nuevoTramite->dni=10;
            nuevoTramite->idTramite=100;
            nuevoTramite->turno =58;

            al_push(listaAtendido,0,nuevoTramite);
            break;
        case 13:
            printf("Is empty");
            if(al_isEmpty(listaAtendido))
                printf("esta vacio");
            else if(al_isEmpty(listaRegular)==0)
                printf("No esta vacio");
            else
                printf("null");
            break;
        }

    }
    while(seguir=='s');


    return 0;
}

int tramite_ordenarDNI(void* tramite1, void* tramite2)
{
    int returnAux;
    eTramite* tramiteUno = (eTramite*) tramite1;
    eTramite* tramiteDos = (eTramite*) tramite2;
    if(tramiteUno->dni > tramiteDos->dni)
    {
        returnAux =1;
    }
    else if( tramiteUno->dni < tramiteDos->dni)
    {
        returnAux =-1;
    }
    else
    {

        returnAux = 0;

    }
    return returnAux;
}
