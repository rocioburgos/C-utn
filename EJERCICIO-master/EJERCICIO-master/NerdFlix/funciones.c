#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

///////////////////////
int menu()
{
    int opcion;


    printf("**Menu de opciones**\n\n");
    printf("1- Mostrar todos\n");
    printf("2- Mostrar cliente con su serie: \n");
    printf("3- Clientes que ven cada serie:\n");
    printf("4- Mostrar  clientes que ven la serie:\n");
    printf("5- Mostrar menos vista\n");
    printf("6- Todas las series que ven los Juan\n");
    printf("7- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}
///////////////////////////////
void cargarSeries(eSerie series[])
{
    int idSerie[5]= {100,101,102,103,104};
    int estado[5]= {1,1,1,1,1};
    char titulo[5][30]= {"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]= {9,7,7,6,1};
    char genero[5][30]= {"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
    for(i=0; i<5; i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};

    int i;

    for(i=0; i<10; i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];

    }

}

void cargarCliente_Serie(eClientes_Series clientesSeries[])
{

    int cliente[20] = {1,1,1,2,2,3,4,4,5,5,5,7,8,8,8,9,10,10,10,10};
    int serie[20]= {101,102,103,104,103,101,101,102,104,100,101,101,101,102,103,102,101,103,102,104};
    int i;

    for(i=0; i<20; i++)
    {
        clientesSeries[i].idCliente=cliente[i];
        clientesSeries[i].idSerie = serie[i];
    }

}
//////////////////////////////
void cargarSeriesLoser(eLoser loser[],eSerie serie[] ,int S)
{
    int i,j;
    for(i=0;i<S;i++)
    {
        loser[i].idSerie=serie[i].idSerie;
        loser[i].cont=0;
    }
}
///////////////////////////////
void mostrarClienteConSerie(eCliente cliente[],int C,eSerie serie[], int S,eClientes_Series CliSe[],int cs)
{
  int i,j,k;
  printf("\n\nID Cliente\tNombre ");
     for(i=0;i<C;i++)
     {
         printf("\n%d \t\t %s ",cliente[i].idCliente,cliente[i].nombre);
         printf("\nSerie que ve:");
        for(j=0;j<cs;j++)
         {
              if(CliSe[j].idCliente==cliente[i].idCliente)
              {
               for(k=0;k<S;k++)
                {
                    if(CliSe[j].idSerie==serie[k].idSerie)
                    {
                          printf("-%s ",serie[k].titulo);
                    }
                }
              }
        }
     }
}

/////////////////
void MostrarTodos(eCliente cliente[],int tamC,eSerie serie[],int tamS)
{
    int i;
    printf("ID serie \t Titulo \t Genero \t Temporada \t");
     for(i=0;i<tamS;i++)
     {
         printf("\n%d \t\t %s \t\t %s \t\t %d ",serie[i].idSerie,serie[i].titulo,serie[i].genero,serie[i].temporadas);
     }

     printf("\n\nID Cliente\tNombre");
     for(i=0;i<tamC;i++)
     {
         printf("\n%d \t\t %s ",cliente[i].idCliente,cliente[i].nombre);
     }
}
/////////////////////////////
void clientesPorSerie(eCliente cliente[],int C, eSerie serie[], int S, eClientes_Series cliSe[],int cs)
{

int i , j , k;
for(i=0;i<S;i++)
     {
        for(j=0;j<cs;j++)
            {
              if(cliSe[j].idSerie==serie[i].idSerie)
              {
                for(k=0;k<S;k++)
                {
                    if(cliSe[j].idCliente==cliente[k].idCliente)
                    {
                        printf("Serie :%s\t Cliente: %s\n",serie[i].titulo,cliente[k].nombre);
                    }
                }
              }
            }
      }
}



//////////////////////////
void buscarSerie(eCliente cliente[],int C, eSerie serie[], int S, eClientes_Series cliSe[],int cs)
{
    char buscar[20];
    int idAux;
    int indice;
    int i,j,k;
    printf("Ingrese el nombre de la serie:");
    fflush(stdin);
    gets(buscar);
    strupr(buscar);

    //recorro series
    for(i=0;i<S;i++)
     {
        if(strcmp(serie[i].titulo,buscar)==0)
        {
            //obrengo idserie e indice
            idAux=serie[i].idSerie;
            indice=i;
            break;
        }
     }

     printf("\nLa serie %s: ",serie[indice].titulo);

   //recorro el clienteSerie
    for(j=0;j<cs;j++)
    {
        if(cliSe[j].idSerie==serie[indice].idSerie)
            {
                 for(k=0;k<C;k++)
                    {
                        if(cliSe[j].idCliente==cliente[k].idCliente)
                        {
                                printf("Serie :%s\t Cliente: %s\n",serie[indice].titulo,cliente[k].nombre);
                        }
                     }
                  }
               }
}
//////////////////////////////////
 void menosPopular(eLoser loser[], int L, eClientes_Series cliSe[],int cs, eSerie serie[])
{
    int i,j,flag=1, maxCant, minCant,maxID,minID,indiceMax,indiceMin;

    for(i=0;i<L;i++)
    {
        for(j=0;j<cs;j++)
        {
            if(loser[i].idSerie==cliSe[j].idSerie)
                {
                    loser[i].cont++;
                }
        }
    }



    for(i=0;i<L;i++)
    {
        printf("\nI es: %d\n",i);
        if(flag==1)
        {
            minID=loser[i].idSerie;
            minCant=loser[i].cont;
            maxID=loser[i].idSerie;
            maxCant=loser[i].cont;
            indiceMin=i;
            indiceMax=i;

            flag=0;
        }
        if(loser[i].cont > maxCant)
        {
            maxID=loser[i].idSerie;
            indiceMax=i;
            maxCant=loser[i].cont;

        }

        if(loser[i].cont < minCant)
        {
            minID=loser[i].idSerie;
            indiceMin=i;
            minCant=loser[i].cont;

        }
    }


    printf("La series menos popular es: %d %s",indiceMin,serie[indiceMin].titulo);
    printf("\nLa series mas popular es: %d %s",indiceMax,serie[indiceMax].titulo);
}











