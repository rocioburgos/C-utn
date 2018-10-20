#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
typedef struct
{
    int edad;
    char sexo;
} eDato;

int main()
{
    FILE* arch;
    ArrayList* person= al_newArrayList();
    ArrayList* person2=al_newArrayList();
    ArrayList* cargando=al_newArrayList();

    eDato uno= {1,'m'};
    eDato dos= {2,'f'};
    eDato tres= {3,'m'};
    eDato* pUno;
    eDato* pDos;
    eDato* pTres;
    eDato* aux;
    int i;

    int edad;
    char sexo;
    pUno=(eDato*)malloc(sizeof(eDato));
    pDos=(eDato*)malloc(sizeof(eDato));
    pTres=(eDato*)malloc(sizeof(eDato));
    pUno=&uno;
    pDos=&dos;
    pTres=&tres;
    if(pUno!=NULL &&pDos!= NULL)
    {

        al_add(person,pUno);
        al_add(person,pTres);
        al_push(person,0,pDos);



        person2=al_clone(person);
        if( al_containsAll(person,person2)==1)
            printf("Lo contiene\n");
        else if( al_containsAll(person,person2)==0)
            printf("no lo contiene\n");
        else
            printf("Error\n");



        printf("Lista uno:\n");
        for(i=0; i<al_len(person); i++)
        {

            aux=(eDato*)malloc(sizeof(eDato));
            aux=(eDato*)al_get(person,i);
            printf("%d- %c\n",aux->edad,aux->sexo);
        }


        printf("Lista dos:\n");
        for(i=0; i<al_len(person2); i++)
        {
            aux=(eDato*)malloc(sizeof(eDato));
            aux=(eDato*)al_get(person2,i);
            printf("%d- %c\n",aux->edad,aux->sexo);
        }



        printf("Cargando a archivo..\n");
        arch=fopen("prueba.txt","w");
        if(arch!=NULL)
        {
            for(i=0; i<al_len(person); i++)
            {
                aux=(eDato*)malloc(sizeof(eDato));
                aux=(eDato*)al_get(person,i);
                fprintf(arch,"%d-%c\n",aux->edad,aux->sexo);
            }
            printf("DATOS CARGADOS\n");
        }
        fclose(arch);




        arch=fopen("prueba.txt","r");
        if(arch!=NULL)
        {
            printf("Leyendo datos cargados antes\n");
            rewind(arch);
            while(!feof(arch))
            {
                fscanf(arch,"%d-%c",&edad,&sexo);
                if(feof(arch))
                {
                    break;
                }
                printf("%d %c\n",edad,sexo);
            }
        }
        fclose(arch);
        printf("\n\n");



        printf("Leyendo y cargando a arrayList\n");
        arch=fopen("prueba.txt","r");
        if(arch!=NULL)
        {
            rewind(arch);
            while(!feof(arch))
            {
                aux=(eDato*)malloc(sizeof(eDato));
                fscanf(arch,"%d-%c\n",&aux->edad,&aux->sexo);

                printf("%d--%c\n",aux->edad,aux->sexo);
                al_add(cargando,aux);

            }
        }
    }
    fclose(arch);


    printf("Mostrando arrayList 'cargado'\n");
    for(i=0; i<al_len(cargando); i++)
    {
        aux=(eDato*)malloc(sizeof(eDato));
        aux=(eDato*)al_get(cargando,i);
        printf("%d)%d %c\n",i,aux->edad,aux->sexo);
    }


    printf("Modificando arrayList cargando");
    al_remove(cargando,0);



    printf("\nCargando a archivo datos modificados..\n");
    arch=fopen("prueba.txt","w");
    if(arch!=NULL)
    {
        for(i=0; i<al_len(cargando); i++)
        {
            aux=(eDato*)malloc(sizeof(eDato));
            aux=(eDato*)al_get(cargando,i);
            fprintf(arch,"%d-%c\n",aux->edad,aux->sexo);
        }
        printf("DATOS CARGADOS\n");
    }
    fclose(arch);

    printf("\n\n");
    printf("Mostrando nuevamente\n");
    arch=fopen("prueba.txt","r");
    if(arch!=NULL)
    {
        rewind(arch);
        while(!feof(arch))
        {
            fscanf(arch,"%d-%c",&edad,&sexo);
            if(feof(arch))
            {
                break;
            }
            printf("%d %c\n",edad,sexo);
        }
    }
    fclose(arch);


    return 0;
}



