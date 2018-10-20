#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define C 20


void darDeAlta(EPersona personas[],int tam)
{
    int flag=0,i,j;
    EPersona personaAux;
    for(i=0;i<tam;i++)
    {
        if(personas[i].estado==0)
        {
            fflush(stdin);

            printf("Ingresar nombre de persona:  ");
            gets(personaAux.nombre);
            printf("Ingresar DNI:  ");
            scanf("%d",&personaAux.dni);
            while((personaAux.dni<1000000)||(personaAux.dni>99999999))
            {
                printf("DNI invalido, ingresar de nuevo");
                printf("Ingresar DNI:  ");
                scanf("%d",&personaAux.dni);
            }
            printf("Ingresar edad:  ");
            scanf("%d",&personaAux.edad);
            while((personaAux.edad<1)||(personaAux.edad>200))
            {
                printf("Edad invalida, ingresar de nuevo");

                printf("Ingresar edad:  ");
                scanf("%d",&personaAux.edad);
            }
            fflush(stdin);
            for(j=0;j<tam;j++)
            {
                if(personas[j].dni==personaAux.dni)
                {
                    printf("DNI repetido, ingreso cancelado\n");
                    system("pause");
                    break;
                }
                else
                {
                    personaAux.estado=1;
                    personas[i]=personaAux;
                    flag=1;
                    break;
                }
            }
            break;
        }
    }
    if((i==tam && flag==0))
    {
        printf("No hay espacio en el vector para ingresar a una nueva persona\n");
        system("pause");
    }
    fflush(stdin);
}




void darDeBaja(EPersona personas[],int tam)
{

    int i,flag=0,numerodni;
    char opcion;
    printf("Ingrese el DNI de la persona a eliminar: ");
    scanf("%d", &numerodni);
    fflush(stdin);
    for(i=0;i<tam;i++)
    {
        if(personas[i].dni==numerodni)
        {
            personas[i].estado=0;
            flag=1;
            printf("Persona encontrada. Desea dar de baja? S/N \n");
                opcion=tolower(getche());

                if(opcion=='s')
                    {
                        printf("\nPersona eliminada del vector\n\n");
                        break;
                    }
                else
                {
                        printf("No se eliminaron datos.\n");
                }
        }
    }
    if((i==tam) && (flag==0))
    {
        printf("El dni ingresado no corresponde a nadie en el vector\n\n");

    }
    fflush(stdin);
}



void ordenaryMostrar(EPersona x[],int tam)
{
    int i,j;
    EPersona auxX;


    for(i=0;i<tam-1;i++)
    {


        for(j=i+1;j<tam;j++)
        {
            if(strcmp( x[i].nombre,x[j].nombre)>0)
            {
               auxX= x[i];
               x[i]=x[j];
               x[j]=auxX;

            }
        }
    }



  printf("Nombre\tDNI\t\tEdad");
    for(i=0;i<tam;i++)
    {
            printf("\n%s\t%d\t%d\n",x[i].nombre, x[i].dni, x[i].edad );
    }
}



void grafico(EPersona persona[], int tam)
{

    int i,flag=0,max;
    int hasta18=0,de19a35=0,mayorDe35=0;

     for(i=0;i<tam;i++)
    {
        if(persona[i].edad<19)
            {
                hasta18++;
            }
        if(persona[i].edad>=19 && persona[i].edad<=35)
            {
                de19a35++;
            }
        if(persona[i].edad>35)
            {
                mayorDe35++;
            }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
     {
        max = hasta18;
     }
    else
        {
            if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
                {
                    max = de19a35;
                }
            else
                {
                    max = mayorDe35;
                }
        }

    for(i=max; i>0; i--)
    {
        if(i<= hasta18)
        {
            printf("   *");
        }
        if(i<= de19a35)
        {
            flag=1;
           printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }

        printf("\n");
    }
    printf("|___________________________________");
    printf("\n  |<18\t19-35\t>35");
}
