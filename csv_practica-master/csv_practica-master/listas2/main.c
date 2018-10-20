#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

typedef struct
{
    char name[30];
    char eMail[60];

} eDatos;
int getInt(char msj[]);
void getString(char mensaje[],char input[]);
int esNumerico(char str[]);
int compare(void* dato1, void *dato2);


int main()
{

    ArrayList* listaDestinatarios=al_newArrayList();
    ArrayList* listaNegra=al_newArrayList();


    eDatos* datos=NULL;
    eDatos* auxDes=NULL;
    eDatos* auxBlack=NULL;
    eDatos* auxJ=NULL;

    eDatos jk= {"Rocio","rb@hotmail.com"};

    FILE* destinatario=NULL;
    FILE* blackList=NULL;

    char seguir='s';
    char nameFile[60];
    char name[30];
    char eMail[50];

    int p=0,x=0;
    int opcion=0;
    int i,j;
    int cont=0;
    int flagD=0;

    auxJ=(eDatos*)malloc(sizeof(eDatos));
    if(auxJ!=NULL)
    {
        auxJ=&jk;
    }


    do
    {
        printf("\n1)Cargar destinatarios\n2)Cargar lista negra\n3)Depurar\n4)Listar\n5)Salir\n");
        printf("6)datos de BLACK LISTA aarray)\n7)datos de la destitanatios(arraylis)\n");
        opcion=getInt("Ingrese un numero de opcion:");

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre del archivo de destinatarios:");
            fflush(stdin);
            gets(nameFile);
            if((strcmpi("des.csv",nameFile))==0)
            {
                destinatario= fopen("des.csv","r");

                if(destinatario==NULL)
                {
                    printf("No se pudo abrir el archivo");
                    exit(1);
                }


                printf("Leyendo datos.\n");
                while(!feof(destinatario))
                {
                    datos=(eDatos*)malloc(sizeof(eDatos));
                    fscanf(destinatario,"%[^,],%[^\n]\n",name,eMail);
                    strcpy(datos->name,name);
                    strcpy(datos->eMail,eMail);

                    al_add(listaDestinatarios,datos);
                    x++;
                }
                printf("Datos cargados del archivo destinatarios.\n");
                printf("\nCantidad de datos cargados:%d-\n",x);
                fclose(destinatario);


            }
            else
            {
                printf("Ese no es el nombre del archivo.\n");
            }

            break;
        case 2:
            printf("Ingrese el nombre del archivo de lista negra: ");
            fflush(stdin);
            gets(nameFile);
            if((strcmpi("black.csv",nameFile))==0)
            {
                blackList= fopen("black.csv","r");

                if(blackList==NULL)
                {
                    printf("No se pudo abrir el archivo");
                    //exit(1);
                }
                else
                {
                    printf("Leyendo datos.\n");
                    p=0;
                    while(!feof(blackList))
                    {
                        datos=(eDatos*)malloc(sizeof(eDatos));
                        fscanf(blackList,"%[^,],%[^\n]\n",name,eMail);
                        strcpy(datos->name,name);
                        strcpy(datos->eMail,eMail);

                        al_add(listaNegra,datos);
                        p++;
                    }
                    printf("Datos cargados de lista negra cargados.\n");
                    printf("\nCantidad de datos cargados:%d-\n",p);
                    fclose(blackList);
                }


            }
            else
            {
                printf("Ese no es el nombre del archivo.\n");
            }


            break;
        case 3:

            for(i=0; i<listaDestinatarios->size; i++)
            {
                auxDes=(eDatos*)al_get(listaDestinatarios,i);
                for(j=0; j<listaNegra->size; j++)
                {
                    auxBlack=(eDatos*)al_get(listaNegra,j);
                    if(compare(auxDes,auxBlack)==0)
                    {
                        al_remove(listaDestinatarios,i);
                        cont++;
                    }
                }
            }


            p=0;
            for(i=0; i<listaDestinatarios->size-1; i++)
            {
                auxDes=(eDatos*)al_get(listaDestinatarios,i);
                for(j=i+1; j<listaDestinatarios->size; j++)
                {
                    auxBlack=(eDatos*)al_get(listaDestinatarios,j);

                    if(compare(auxDes,auxBlack)==0)
                    {
                        al_remove(listaDestinatarios,i);
                        p++;

                    }
                }
            }
            al_sort(listaDestinatarios,compare,1);
            flagD=1;
            printf("Datos removidos:%d\nDatos repetidos:%d\n",cont,p);
            break;
        case 4:
            if(flagD==1)
            {
                printf("Se mandara el correo a estas personas:\n");

            al_push(listaDestinatarios,14,auxJ);//PUSH DE PRUBA

                for(i=0; i<al_len(listaDestinatarios); i++)
                {
                    auxDes=(eDatos*)malloc(sizeof(eDatos));
                    auxDes=al_get(listaDestinatarios,i);
                    printf("%d)Name: %s - eMail: %s\n",i,auxDes->name,auxDes->eMail);
                }
            }
            else
            {
                printf("Primero debe depurar las listas.\n");
            }



            break;
        case 5:

            seguir='n';
            break;
        case 6:
            if(listaNegra!=NULL)
                printf("%d\n",listaNegra->size);
            else
                printf("No existe");
            break;
        case 7:
            printf("%d\n",al_len(listaDestinatarios));
            break;
        default:
            printf("Ese numero de opcion no existe.\n");
            break;
        }


    }
    while(seguir=='s');

    return 0;
}














int compare(void* dato1, void *dato2)
{
    eDatos* datoUno= (eDatos*)dato1;
    eDatos* datoDos=(eDatos*) dato2;
    int valorReturn;

    if((strcmpi(datoUno->name,datoDos->name))==0 || (strcmpi(datoUno->eMail,datoDos->eMail)==0))
    {
        valorReturn=0;
    }
    else if((strcmpi(datoUno->name,datoDos->name))>0  || (strcmpi(datoUno->eMail,datoDos->eMail)>0))
    {
        valorReturn=1;
    }
    else
    {
        valorReturn=-1;
    }

    return valorReturn;



}



int getInt(char msj[])
{
    char numAux[25];
    int returnAux;

    getString(msj, numAux);
    while(!esNumerico(numAux))
    {
        getString("Reingrese:", numAux);
    }
    returnAux= atoi(numAux);
    return returnAux;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%49s", input);
    strlwr(input);
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' )
            return 0;
        i++;
    }
    return 1;
}
