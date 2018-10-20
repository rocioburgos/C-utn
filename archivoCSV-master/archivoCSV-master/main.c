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


int main()
{

    ArrayList* listaDestinatarios=al_newArrayList();
    ArrayList* listaNegra=al_newArrayList();
    ArrayList* depurada=al_newArrayList();

    eDatos* datos;
    eDatos* auxDes;
    eDatos* auxBlack;

    FILE* destinatario;
    FILE* blackList;

    char seguir='s';
    char nameFile[60];
    char name[30];
    char eMail[50];

    int p=0;
    int opcion=0;
    int cont=0,i,j;
    int valorR=2;

    do
    {
        printf("\n1)Cargar destinatarios\n2)Cargar lista negra\n3)Depurar\n4)Listar\n5)Salir\n");
        opcion=getInt("Ingrese un numero de opcion:");

        switch(opcion)
        {
        case 1:
            printf("Ingrese el nombre del archivo de destinatarios:");
            fflush(stdin);
            gets(nameFile);
            if((strcmpi("destinatarios.csv",nameFile))==0)
            {
                destinatario= fopen("destinatarios.csv","r");

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
                        p++;


                    }
                    printf("Datos cargados del archivo destinatarios.\n");
                    printf("\nCantidad de datos cargados:%d-\n",p);
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
            if((strcmpi("black_list.csv",nameFile))==0)
              {

                blackList= fopen("black_list.csv","r");

                if(blackList==NULL)
                {
                    printf("No se pudo abrir el archivo");
                    //exit(1);
                }else
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
            printf("Depuracion de datos.\n");
            for(i=0;i<al_len(listaDestinatarios);i++)
            {
              auxDes=(eDatos*)malloc(sizeof(eDatos));
              auxDes=(eDatos*) al_get(listaDestinatarios,i);
              valorR=al_contains(listaNegra,auxDes);

             if(valorR==0)
              {
                  al_add(depurada,auxDes);
                  printf("valor R:%d\nI: %d\n",valorR,i);
                  cont++;//contador para saber cuantas veces ingresa
              }
            }
            //// codigos de prueba
            printf("Datos cargados a la nueva lista: %d\n",cont);
            auxBlack=(eDatos*)al_get(depurada,0);
            printf("En elindice cero name: %s\n",auxBlack->name);
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("Ese numero de opcion no existe.\n");
            break;
        }


    }
    while(seguir=='s');

    return 0;
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
