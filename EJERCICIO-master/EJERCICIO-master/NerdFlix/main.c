#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

/*
1- mostrar cada uno
2- mostrar clientes con sus series
3- por cada serie los clientes que la estan viendo
4- todos los clientes que ven una serie en particular (El usuario ingresa el titulo)
5- La serie menos popular
6- Todas las series que ven los clientes de nombre "Juan"
*/
void seriesDeJuan(eCliente cliente[],int C,eSerie serie[],int S,eClientes_Series cliSe[],int cs);

int main()
{
    eSerie serie[5];
    eCliente cliente[10];
    eClientes_Series serieCliente[20];
    eLoser loser[5];
    char seguir ='s';


    cargarClientes(cliente);
    cargarSeries(serie);
    cargarCliente_Serie(serieCliente);
    cargarSeriesLoser(loser,serie,5);

    do
    {
        switch(menu())
        {
        case 1:
              MostrarTodos(cliente,10,serie,5);
            break;
        case 2:
            mostrarClienteConSerie(cliente,10,serie,5,serieCliente,20);
            break;
        case 3:
            clientesPorSerie(cliente,10,serie,5,serieCliente,20);
            break;
        case 4:
            buscarSerie(cliente,10,serie,5,serieCliente,20);
            break;
        case 5:
            menosPopular(loser,5,serieCliente,20,serie);
            break;
        case 6:
            seriesDeJuan(cliente,10,serie,5,serieCliente,20);
            break;


        }

    }while(seguir=='s');

    return 0;
}

void seriesDeJuan(eCliente cliente[],int C,eSerie serie[],int S,eClientes_Series cliSe[],int cs)
{
    int i,j,k,indiceJuan;

    for(i=0;i<C;i++)
    {
        if(strcmp(cliente[i].nombre,"Juan")==1)
        {
            indiceJuan=i;
            break;
        }
    }

    printf("Juan ve las series: ");

    for(j=0;j<cs;j++)
    {
        if(cliente[indiceJuan].idCliente==cliSe[j].idCliente)
        {
            for(k=0;k=S;k++)
            {
                if(cliSe[j].idSerie == serie[k].idSerie)
                {
                    printf("%s \n",serie[k].titulo);
                }
            }
        }
    }
}
