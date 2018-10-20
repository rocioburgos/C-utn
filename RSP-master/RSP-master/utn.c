#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"




/** \brief Permite leer un texto simple sin espacio
 *
 * \param mensaje Se debe indicar que mensaje mostrar al usuario
 * \param input La variable donde se va a guardar el texto ingresado
 * \return
 *
 */

void getString(char mensaje[],char input[])
{

    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    // scanf ("%s", input);

}


/** \brief Verifaca que un string contenga solo numeros
 *
 * \param str La cadena a verificar
 * \return retorna 0 si no contiene solo numeros y 1 si solo contiene numeros
 *
 */
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

/** \brief Permite ingresar un numero y realiza todas las verificaciones
 *
 * \param msj Es el mensaje a mostrar al usuario
 * \return el numero ya validado
 *
 */

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

/** \brief Verifica que la cadena de caracteres no desborde el array
 *
 * \param validar Es la cadena a validar
 * \param maximo Es el maximo que puede soportar el array
 * \return 1 si contiene mas que el maximo 0 si no lo desborda
 *
 */

int validacionCantidadMaxima(char validar[], int maximo)
{
    if((strlen(validar))>=maximo)
    {
        return 1;
    }
    return 0;

}

/** \brief Permite cargar una cadena de caracteres con solo numeros
 *
 * \param mensaje Es el mensaje a mostrar al usuario
 * \param input es donde se va a guardar el dato
 * \return 1 si contiene solo numeros y 0 si no contiene solo numeros
 *
 */
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

/** \brief Verifica que todos los caracteres de una cadena sean solo letras
 *
 * \param str Es la cadena a validar
 * \return 0 si contiene un espacio u otro caracter
 *
 */

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

/** \brief Permite cargar una cadena de caracteres con solo letras
 *
 * \param mensaje Es el mensaje a mostrar al usuario
 * \param input es donde se va a guardar el dato
 * \return 1 si contiene solo numeros y 0 si no contiene solo numeros
 *
 */
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

/** \brief Permite obtener un long int
 *
 * \param msj Es el mensaje a mostrar al usuario
 * \return el numero ya validado
 *
 */
int getLong(char msj[])
{
    char numAux[25];
    long int returnAux;

    getString(msj, numAux);
    while(!esNumerico(numAux))
    {
        getString("Reingrese:", numAux);
    }
    returnAux= atoi(numAux);
    return returnAux;
}

//
//
//
//
//char* getStringOK(char msj[])
//{
//
//    char auxName[30];
//    int retorno,retorno2;
//    char* returnAux=NULL;
//    returnAux=(char*)malloc(sizeof(char)*30);
//
//    if(returnAux!=NULL)
//    {
//        do
//        {
//            retorno = getStringLetras(msj,auxName);
//            retorno2=cantidadMaxima(auxName, 20);
//        }
//        while(retorno==0 || retorno2 ==0);
//        returnAux=auxName;
//    }
//    return returnAux;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Reserva espacio en memoria
 * \return retorna NULL si no obtiene espacio, o el una direccion de memoria
 *
 */

eNum* constructor()
{
    eNum* retorno=NULL;
    eNum* tarea=(eNum*) malloc(sizeof(eNum));

    if(tarea!=NULL)
    {

        retorno=tarea;
    }
    return retorno;
}


/** \brief Establece si un elemento con respecto al otro es mayor,menor o igual
 *
 * \param uno  dos Los punteros a los elementos
 * \return 1 si el primer dato es mayor al segundo, -1 si el primero es menor al segundo y 0 si son iguales
 *
 */

int ordenar(void* uno, void* dos)
{
    int returnAux;
    eNum* pUno = (eNum*) uno;
    eNum* pDos = (eNum*) dos;
    if(pUno->numero > pDos->numero)
    {
        returnAux =1;
    }
    else if( pUno->numero< pDos->numero)
    {
        returnAux =-1;
    }
    else
    {
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite cargar los datos desde un archivo a un arrayList
 *
 * \param tareasFile , el puntero al archivo para poder abrir el archivo
 * \param lista , es el puntero al arraylist
 * \return retorna 0 si no se pudo leer los datos y 1 si los pudo leer y cargar al arrayList
 *
 */
int cargarDesdeArchivo(ArrayList* lista)
{
    FILE* tareasFile;
    int returnAux=0,flag=0;
    char num[5],name[50],letras[70],par[3];
    eNum* leido;

    tareasFile=fopen("datos.csv","r");
    if(tareasFile!=NULL)
    {
        printf("leyendo datos\n");

        while(!feof(tareasFile))
        {
            if(flag==0)
            {
                fscanf(tareasFile,"%[^\n]\n",letras);
                flag=1;
            }
            fscanf(tareasFile,"%[^;];%[^;];%[^;];%[^;]%[^\n]\n",num,name,par,par,par);

            leido=constructor();
            if(leido!=NULL)
            {
                set_Name(leido,name);
                set_Num(leido,atoi(num));
                leido->impar=0;
                leido->par=0;
                leido->primo=0;
                lista->add(lista,leido);
                returnAux=1;
            }
        }
    }

    fclose(tareasFile);
    return returnAux;
}

void cargarNuevoNumero(ArrayList*lista)
{
    int num;
    char name[50];
    eNum* auxiliar=constructor();

    num=getInt("Ingrese el nuevo numero:");
    getStringLetras("Ingrese el nombre: ",name);

    set_Num(auxiliar,num);
    set_Name(auxiliar,name);
    auxiliar->impar=0;
    auxiliar->par=0;
    auxiliar->primo=0;

    al_add(lista,auxiliar);

}

void cambiarNum(ArrayList* lista)
{
    int newNum;
    int i;
    eNum *auxiliar;
    int flag=0,num,flag2=0;
    char input[50];


    newNum=getInt("Ingrese el numero a cambiar:");

    for(i=0; i<al_len(lista); i++)
    {
        auxiliar=(eNum*)al_get(lista,i);
        if(auxiliar->numero==newNum)
        {
            if(flag2==0)
            {
                printf("Numero encontrado: %s %d",auxiliar->nombre,auxiliar->numero);
                num=getInt("\nIngrese el nuevo numero:");
                getStringLetras("Ingrese el nuevo nombre:",input);
                flag2=1;
            }

            set_Num(auxiliar,num);
            set_Name(auxiliar,input);
            printf("Datos cambiados:%s %d\n",auxiliar->nombre,auxiliar->numero);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No se encontro el numero.\n");
    }
}

void set_Num(eNum* pnum,int num)
{
    pnum->numero=num;
}

void set_Name(eNum* pnum,char name[])
{

    strcpy(pnum->nombre,name);
}


/** \brief Permite eliminar un dato
 */
void baja(ArrayList* lista)
{
    int num,i,flag=0;
    eNum* auxiliar;
    num=getInt("Ingrese el numero a buscar:");
    for(i=0; i<al_len(lista); i++)
    {
        auxiliar=(eNum*)al_get(lista,i);
        if(auxiliar->numero==num)
        {
            printf("Numero encontrado: %s %d\n",auxiliar->nombre,auxiliar->numero);
            if(al_remove(lista,i)==0)
            {
                printf("Se borro el elemento.\n");
            }
            else
            {
                printf("No se pudo borrar\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No se encontro el dato.\n");
    }

}

/** \brief Completa del arrayList los campos par, impar, primo
 */
void completar(ArrayList* lista)
{
    int i;
    eNum* aux;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        par(aux);
        impar(aux);
        primo(aux);

    }
}

/** \brief Permite saber si un numero es par
 */
void par(eNum* pNum)
{
    if(pNum->numero%2==0)
    {
        pNum->par=1;
    }
}

/** \brief Permite saber si un numero es impar
 */
void impar(eNum *pNum)
{
    if(pNum->numero%2!=0)
    {
        pNum->impar=1;
    }
}
/** \brief Permite saber si un numero es primo
 */
void primo(eNum*  pNum)
{
    int i,cont=0;
    for(i=1; i<=pNum->numero; i++)
    {
        if(pNum->numero%i==0 )
        {
            cont++;
        }
    }
    if(cont==2)
    {
        pNum->primo=1;
    }
}

/** \brief Guarda en un arrayList los repetidos de la lista principal
 *
 */

void repetidos(ArrayList* lista,ArrayList* listaRepetidos)
{
    int i,j;
    eNum* auxUno, *auxDos;

    al_sort(lista,ordenar,0);
    for(i=0; i<al_len(lista)-1; i++)
    {
        auxUno=(eNum*)al_get(lista,i);
        for(j=i+1; j<al_len(lista); j++)
        {
            auxDos=(eNum*)al_get(lista,j);
            if(auxUno->numero==auxDos->numero)
            {
                al_add(listaRepetidos,auxDos);
                al_add(listaRepetidos,auxUno);

                al_remove(lista,i);
            }
        }
    }
    al_sort(listaRepetidos,ordenar,0);
}




/** \brief Imprime por pantalla un numero
 */

void mostrarNumero(eNum* pNum)
{
    printf("Name:%s Num:%d Par: %d Impar:%d Primo:%d\n",pNum->nombre,pNum->numero,pNum->par,pNum->impar,pNum->primo);
}
/** \brief Imprime por pantalla un arrayList de numeros
 */
void mostrarTodos(ArrayList* lista)
{
    eNum * aux;
    int i;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        mostrarNumero(aux);
    }
}

/** \brief Cuenta la cantidad de pares
 */

void cantPares(ArrayList* lista)
{
    int i;
    eNum* aux;
    int cont=0;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        if(aux->par==1)
        {
            cont++;
        }
    }
    printf("En esta lista hay %d numeros pares\n",cont);
}
/** \brief Cuenta la cantidad de impares
 */
void contImpar(ArrayList* lista)
{
    int i;
    eNum* aux;
    int cont=0;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        if(aux->impar==1)
        {
            cont++;
        }
    }
    printf("En esta lista hay %d numeros impares\n",cont);

}

/** \brief Cuenta la cantidad de primos
 */
void contPrimos(ArrayList* lista)
{
    int i;
    eNum* aux;
    int cont=0;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        if(aux->primo==1)
        {
            cont++;
        }
    }
    printf("En esta lista hay %d numeros primos\n",cont);
}

/** \brief Cuenta la cantidad de ceros
 */
void cantCeros(ArrayList* lista)
{
    int i;
    eNum* aux;
    int cont=0;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        if(aux->numero==0)
        {
            cont++;
        }
    }
    printf("En esta lista hay %d numeros ceros\n",cont);
}

int cantidadDelDato(eNum* aux, ArrayList* lista)
{
    int i;
    eNum* auxI;
    int cont=0;

    for(i=0; i<al_len(lista); i++)
    {
        auxI=(eNum*)al_get(lista,i);
        if(aux->numero== auxI->numero)
        {
            cont++;
        }
    }
    return cont;
}


void dividir(ArrayList* lista, ArrayList* repetidos, ArrayList* noRepetidos)
{
    int i,cantidad;
    eNum* aux;

    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);
        cantidad=cantidadDelDato(aux,lista);
        if(cantidad>1)
        {
            al_add(repetidos,aux);
        }
    }
    sinRepetidos(lista,noRepetidos);
}

void sinRepetidos(ArrayList* lista,ArrayList* noRepetidos)
{
    eNum* aux;
    int i;
    for(i=0; i<al_len(lista); i++)
    {
        aux=(eNum*)al_get(lista,i);

        if(contiene(aux,noRepetidos)==0)
        {
            al_add(noRepetidos,aux);
        }
    }
}


int contiene(eNum* dato, ArrayList* noRepetidos)
{
    int i;
    eNum* aux;
    for(i=0; i<al_len(noRepetidos); i++)
    {
        aux=(eNum*)al_get(noRepetidos,i);
        if(dato->numero==aux->numero)
        {
            return 1;
        }
    }
    return 0;
}
