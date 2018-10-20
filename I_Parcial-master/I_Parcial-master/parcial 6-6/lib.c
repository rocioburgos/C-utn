#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"


void cargarProgramadores(eProgramador programador[])
{
    int id[7]= {0,1,2,3,4,5,6};
    char nombres[7][30]= {"Natalia","Camila","Lucas","Carla","Juan","Marcos","Teresa"};
    char apellidos[7][30]= {"Burgos","Villalba","Martinez","Andia","Apaza","Severo","Santander"};
    int categorias[7]= {100,101,102,102,102,100,101};
    int estado[7]= {1,1,1,1,1,1,1};

    int i;
    for(i=0; i<7; i++)
    {
        programador[i].id= id[i];
        strcpy(programador[i].nombre,nombres[i]);
        strcpy(programador[i].apellido, apellidos[i]);
        programador[i].idCategoria= categorias[i];

        programador[i].estado = estado[i];
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargarCategoria(eCategoria categoria[])
{
    int idCat[C]= {100,101,102};
    char name[C][20]= {"junior","semisenior","senior"};
    int pagoPorHora[C]= {400,700,1000};

    int i;

    for(i=0; i<C; i++)
    {
        categoria[i].idCategoria =idCat[i];
        strcpy(categoria[i].descripcion, name[i]);
        categoria[i].pagoPorH =pagoPorHora[i];
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargarProyectos(eProyecto proyecto[])//son 3 proyectos
{
    int id[S]= {200,202,204};
    char nombres[S][20]= {"Aplicacion","Pagina Web","Nuevo hardware"};
    int estado[S]= {1,1,1};
    int i;

    for(i=0; i<S; i++)
    {
        proyecto[i].estado= estado[i];
        proyecto[i].idProyecto=id[i];
        strcpy(proyecto[i].nombreProyecto, nombres[i]);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void alta(eProgramador programador[], int tam, eCategoria cat[])
{
    int indice;

    indice=indiceLibre(programador,tam);
    if(indice==-1)
    {
        printf("No hay mas espacio.");
        system("pause");
    }
    else
    {
        nombre(programador, indice);
        apellido(programador,indice);
        categoria(programador,cat,indice);

        programador[indice].id=indice;
        printf("Su ID es: %d.\n",indice);
        programador[indice].estado=1;
        printf("\nEstado: 1. \nCARGA EXITOSA.\n\n");

    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void nombre(eProgramador prog[],int indice)
{

    char auxName[256];
    int retorno,retorno2;

    do
    {
        retorno = getStringLetras("\nIngrese el nombre: ",auxName);
        retorno2=cantidadMaxima(auxName, 20);

    }
    while(retorno==0 || retorno2 ==0);


    strcpy(prog[indice].nombre,auxName);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void apellido(eProgramador prog[],int indice)
{
    char auxName[256];
    int retorno,retorno2;

    do
    {
        retorno = getStringLetras("\nIngrese el apellido: ",auxName);
        retorno2=cantidadMaxima(auxName, 20);

    }
    while(retorno==0 || retorno2 ==0);

    strcpy(prog[indice].apellido,auxName);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void categoria(eProgramador programador[],eCategoria cat[],int indice)
{
    char auxName[20];
    int i;
    int idCat;
    int flag=0;
    int retorno, retorno2;
    do
    {

        do
        {
            retorno = getStringLetras("\nIngrese el NOMBRE de la categoria: ",auxName);
            retorno2=cantidadMaxima(auxName, 20);

        }while(retorno==0 || retorno2 ==0);


        for(i=0; i<C; i++)//busco la categoria
        {
            if((strcmpi(cat[i].descripcion,auxName ))==0)
            {
                idCat=cat[i].idCategoria;
                programador[indice].idCategoria= idCat;

                flag=1;
            }
        }

    }
    while(flag==0);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cantidadMaxima(char input[], int max)
{
    int cantCaracteres;

    cantCaracteres=strlen(input);
    if(cantCaracteres>max)
    {
        return 0;
    }

    return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargarEstado(eProgramador programador[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        programador[i].estado=0;
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int indiceLibre(eProgramador programador[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(programador[i].estado ==0)
        {
            return i;
        }
    }
    return -1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int validacionCantidadMaxima(char validar[], int maximo)
{
    while((strlen(validar))>=maximo)
    {
        return 1;
    }
    return 0;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);
    strlwr(input);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void mostrarProgramadores(eProgramador programador[], int tam,eCategoria categoria[])
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(programador[i].estado==1)
        {
            mostrarProgramador(programador,i,categoria);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarProgramador(eProgramador programador[], int indice,eCategoria categoria[])
{
    int cat;
    char nameCat[25];
    int i;
    cat= programador[indice].idCategoria;

    for(i=0; i<C; i++)//busco dentro de las categorias para obtener el nombre
    {
        if(cat== categoria[i].idCategoria)
        {
            strcpy(nameCat,categoria[i].descripcion);
        }

    }
    if(programador[indice].estado==1)
    {

        printf("\n\nNombre: %s\n Apellido: %s\nID: %d\nCategoria: %s\n",programador[indice].nombre,programador[indice].apellido,programador[indice].id,nameCat);

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ppCero(eProyectoProgramador progPro[])
{
    int i;
    for(i=0; i<R; i++)
    {


        progPro[i].horasDeTrabajo=0;
        progPro[i].idProgramador=0;
        progPro[i].idProyecto=0;

    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificacion(eProgramador programador[], int tam, eCategoria cat[])
{
    int auxId;
    char numAux[25];
    int i;
    int flag=0;


    getString("Ingrese ID:", numAux);
    while(!esNumerico(numAux))
    {
        getString("Ingrese ID:", numAux);
    }
    auxId= atoi(numAux);

    for(i=0; i<tam; i++)
    {
        if(auxId==programador[i].id && programador[i].estado==1)
        {
            printf("Datos encontrados: \n");
            mostrarProgramador(programador,auxId,cat);

            printf("MODIFICACION\n");
            nombre(programador,i);
            apellido(programador,i);

            categoria(programador,cat,i);
            flag=1;
            printf("Fin de modificacion\n");
        }

    }
    if (flag==0)
    {
        printf("ID inexistente\n");

    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargarAproyectos(eProyectoProgramador pp[])
{
    int idProyecto[]= {200,202,202,204,202,200,202,204,202};
    int idProgram[]= {0,1,2,3,4,5,6,0,3};
    int horas[]= {5,4,3,5,6,8,2,6,2};
    int i;

    for(i=0; i<9; i++)
    {
        pp[i].horasDeTrabajo=horas[i];
        pp[i].idProgramador=idProgram[i];
        pp[i].idProyecto=idProyecto[i];
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarProyecto(eProyecto pro[], int i)
{
    printf("\nNombre: %s\nID: %d\n",pro[i].nombreProyecto,pro[i].idProyecto);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarProyectos(eProyecto pro[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(pro[i].estado==1)
        {
            mostrarProyecto(pro,i);
        }

    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void seleccionarProgramador(eProgramador prog[],int tam,eProyectoProgramador pp[],eProyecto proyecto[], eCategoria categoria[])
{
    char auxId[10];
    int id;
    int idProyecto,i,j;
    int flag=0;

    mostrarProgramadores(prog,tam,categoria);
    printf("Ingrese ID programador: ");
    fflush(stdin);
    gets(auxId);

    while(esNumerico(auxId)==0)
    {
        printf("Error. Ingrese ID del programador: ");
        fflush(stdin);
        gets(auxId);
    }
    id= atoi(auxId);

    for(i=0; i<tam; i++)
    {


        if(id==prog[i].id)
        {
            for(j=0; j<R; j++)
            {
                if(pp[j].idProgramador==id && pp[j].horasDeTrabajo!=0)
                {
                    idProyecto = pp[j].idProyecto;
                    mostrarProgramador(prog,id,categoria);
                    printf("\n");
                    mostrarProyectoSegunID(idProyecto, proyecto);
                    flag=1;
                }


            }

        }
    }

    if(flag==0)
    {
        printf("No tiene ningun proyecto asignado.\n");
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarProyectoSegunID(int id, eProyecto proyecto[])
{
    int i;
    for(i=0; i<S; i++)
    {
        if(proyecto[i].idProyecto==id)
        {
            printf("Nombre: %s\nID:%d ",proyecto[i].nombreProyecto,proyecto[i].idProyecto);
            printf("\n_____________________________\n");
        }
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listarProgramadoresConProyecto(eProgramador prog[],int tam,eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[])
{

    int cat,cantHs;
    int i,j,k,m,idProyecto;
    float pagoXhs,cobra;

    for(i=0; i<tam; i++) //recorre los programadores
    {
        if(prog[i].estado==1)
        {

    printf("\n____________________________________________\n");
            printf("____________________________________________\n");
            mostrarProgramador(prog,i, categoria);

            cat=prog[i].idCategoria;

            for(k=0; k<C; k++) //busco en las categorias el pago por hpra
            {
                if(cat==categoria[k].idCategoria)
                {
                    pagoXhs=categoria[k].pagoPorH;
                }
            }

            for(j=0; j<R; j++) // busco dentro de los programadorProyecto
            {
                if(i==pp[j].idProgramador && pp[j].horasDeTrabajo!=0)
                {
                    for(m=0; m<S; m++) //obtenog el indice del proyecto para dsos poder mostrarlo por pantalla
                    {
                        if(pp[j].idProyecto== proyecto[m].idProyecto)
                        {
                            idProyecto= m;
                        }
                    }

                    cantHs=pp[j].horasDeTrabajo;
                    cobra= cantHs * pagoXhs;
                    mostrarProyecto(proyecto,  idProyecto );
                    printf("Por el proyecto cobra: %.2f",cobra);
                    printf("\n________________________\n");

                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listarAllProyectos(eProyectoProgramador pp[],eProyecto proyecto[] )
{
    int p1=0,p2=0,p3=0;
    int j;

    for(j=0; j<R; j++)//busco dentro de los pp[]
    {
        if(pp[j].horasDeTrabajo!=0 && pp[j].idProyecto==200)
        {
            p1++;
        }
        else if(pp[j].horasDeTrabajo!=0 && pp[j].idProyecto==202)
        {
            p2++;
        }

        else if(pp[j].horasDeTrabajo!=0 && pp[j].idProyecto==204)
        {
            p3++;
        }

    }

    mostrarProyecto(proyecto,0);
    printf("En este proyecto trabajan: %d programadores\n",p1);


    mostrarProyecto(proyecto,1);
    printf("En este proyecto trabajan: %d programadores\n",p2);


    mostrarProyecto(proyecto,2);
    printf("En este proyecto trabajan: %d programadores\n",p3);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void borrar(eProgramador programador[],int tam, eProyecto proyecto[], eProyectoProgramador pp[],eCategoria categoria[])
{
    int i,j;
    int auxId;
    char numAux[25];
    int flag=0;
    char seguro;


    getString("Ingrese ID:", numAux);
    while(!esNumerico(numAux))
    {
        getString("Ingrese ID:", numAux);
    }
    auxId= atoi(numAux);

    for(i=0; i<tam; i++)
    {
        if(programador[i].id== auxId && programador[i].estado==1)
        {
            mostrarProgramador(programador,i,categoria);
            printf("¿Seguro de realizar la baja? s/n:");
            fflush(stdin);
            scanf("%c",&seguro);

            if(seguro=='s'||seguro=='S')
            {
                programador[i].estado=0;
                for(j=0; j<R; j++)// busco dentro de los pp[]
                {
                    if(pp[j].idProgramador==auxId)
                    {
                        pp[j].horasDeTrabajo=0;
                        pp[j].idProgramador=0;
                        pp[j].idProyecto=0;
                        printf("Programador dado de baja de proyectos.\n");
                        break;
                    }
                }
                printf("Programador dado de baja exitosamente.\n");

            }
            else
            {
                printf("Accion cancelada.");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("El ID ingresado no es valido");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void asignarProyecto(eProgramador programador[],int tam, eProyecto proyecto[],int tamP, eProyectoProgramador pp[],eCategoria categoria[])
{
    int auxID,auxProy,horas;
    int flag1=0;
    int i,j,k;
    char numAux[25];
    mostrarProgramadores(programador,tam,categoria);

    getString("Ingrese numero de ID del programador: ", numAux);
    while(!esNumerico(numAux))
    {
        getString("Error. Reingrese:", numAux);
    }
    auxID= atoi(numAux);
    for(i=0; i<tam; i++)//recorro los programadores
    {
        if(auxID== programador[i].id && programador[i].estado==1)//encuentro al programador
        {
            flag1=1;

            printf("---PROYECTOS---");
            mostrarProyectos(proyecto, tamP);


            getString("\nIngrese ID del proyecto a asignar: ", numAux);
            while(!esNumerico(numAux))
            {
                getString("Error. Reingrese:", numAux);
            }
            auxProy= atoi(numAux);

            for(j=0; j<S; j++) //recorro los proyectos
            {
                if(auxProy==proyecto[j].idProyecto)//encuentro al proyecto
                {
                    for(k=0; k<R; k++) //recorro progProy
                    {
                        if(pp[k].horasDeTrabajo!=0 && pp[k].idProyecto== auxProy && pp[k].idProgramador == auxID)// busco que no se repita el programador en un proyecto
                        {
                            printf("Ese programador ya esta en el proyecto\n");
                            break;
                        }
                        else if(pp[k].horasDeTrabajo==0)//encuentro
                        {
                            getString("\nIngrese horas de trabajo: ",numAux);
                            while(!esNumerico(numAux))
                            {
                                getString("Error. Reingrese:", numAux);
                            }
                            horas = atoi(numAux);


                            pp[k].horasDeTrabajo=horas;
                            pp[k].idProgramador=auxID;
                            pp[k].idProyecto=auxProy;
                            flag1=1;
                            printf("Programador dado asignado.\n");
                            break;
                        }
                    }
                }
            }

        }
    }
    if(flag1==0)
    {
        printf("No se pudo asignar al programador\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargareDemandate(eDemandante popular[],eProyecto proyecto[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        popular[i].cont=0;
        popular[i].idProyecto= proyecto[i].idProyecto;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void proyectoDemandante(eProyectoProgramador pp[],eDemandante popu[],int tam,eProyecto proyecto[])
{
    int i,j;
    int maxCant,indiceMax;


    int flag=0;

    for(i=0; i<R; i++)// busco dentro de los pp[]
    {
        if(pp[i].horasDeTrabajo!=0)
        {
            for(j=0; j<S; j++) //recorro los popu
            {
                if(pp[i].idProyecto == popu[j].idProyecto)
                {
                    popu[j].cont++;
                }
            }

        }
    }

    for(i=0; i<tam; i++)
    {
        if(flag==0)
        {

            maxCant= popu[i].cont;
            indiceMax=i;

            flag=1;
        }


        if(popu[i].cont > maxCant)
        {
            indiceMax=i;
            maxCant=popu[i].cont;
        }

    }

    printf("El proyecto mas demandate es: ");
    mostrarProyecto(proyecto, indiceMax);
    printf("Tabajan %d programadores.\n\n",maxCant);

}
///////////////////////////////////////////////////////////////////////////////
void totalSueldo(eProgramador prog[],int tam,eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[])
{
    int i,k,j;
    int cat,cantHs;
    float pagoXhs,cobra;
    float totalaCobrar=0;

    for(i=0; i<tam; i++) //recorre los programadores
    {
        if(prog[i].estado==1)
        {

            printf("\n____________________________________________\n");
            printf("____________________________________________\n");
            mostrarProgramador(prog,i, categoria);

            cat=prog[i].idCategoria;

            for(k=0; k<C; k++) //busco en las categorias el pago por hpra
            {
                if(cat==categoria[k].idCategoria)
                {
                    pagoXhs=categoria[k].pagoPorH;
                }
            }

            totalaCobrar=0;
            for(j=0; j<R; j++) // busco dentro de los programadorProyecto
            {

                if(i==pp[j].idProgramador && pp[j].horasDeTrabajo!=0)
                {
                    cantHs=pp[j].horasDeTrabajo;
                    cobra= cantHs * pagoXhs;
                    totalaCobrar+=cobra;
                }
            }
            printf("Por todos los proyectos cobra: %.2f",totalaCobrar);
            printf("\n________________________\n");

        }
    }
}
//////////////////////////////////////////////////////////////
void pagoDeProyectos(eProgramador prog[],eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[])
{
    int i,j,k,n;
    float paga=0,pagoXhs,cobra;
    int cat,cantHs;
    for(i=0; i<S; i++) //recorro los proyectos
    {
        paga=0;
        mostrarProyecto(proyecto,i);
        for(j=0; j<P; j++)//busco dentro de los programadores
        {
            if(prog[j].estado==1)
            {
                cat=prog[j].idCategoria;
                for(n=0; n<C; n++) //busco en las categorias el pago por hpra
                {
                    if(cat==categoria[n].idCategoria)
                    {
                        pagoXhs=categoria[n].pagoPorH;
                    }
                }

                for(k=0; k<R; k++) // busco dentro de los programadorProyecto
                {
                    if(j==pp[k].idProgramador && pp[k].horasDeTrabajo!=0 && pp[k].idProyecto==proyecto[i].idProyecto)
                    {
                        cantHs=pp[k].horasDeTrabajo;
                        cobra= cantHs*pagoXhs;
                        paga+=cobra;
                    }
                }

            }
        }
        printf("Este proyecto paga: %.2f",paga);
        printf("\n________________________\n");
    }
}
