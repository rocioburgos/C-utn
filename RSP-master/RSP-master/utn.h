#include "arrayList.h"

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
}eNum;

int esNumerico(char str[]);
void getString(char mensaje[],char input[]);
int getInt(char msj[]);
int validacionCantidadMaxima(char validar[], int maximo);
int getStringNumeros(char mensaje[],char input[]);
int esSoloLetras(char str[]);
int getStringLetras(char mensaje[],char input[]);
int getLong(char msj[]);
char* getStringOK(char msj[]);
int cantidadMaxima(char input[], int max);



int ordenar(void* uno, void* dos);
eNum* constructor();
//int cargarDesdeArchivo(FILE* tareasFile,ArrayList* lista);
int cargarDesdeArchivo(ArrayList* lista);
int guardarEnArchivo(FILE* archivo, char name[],ArrayList* lista);
void baja(ArrayList* lista);
void set_Name(eNum* pnum,char name[]);
void set_Num(eNum* pnum,int num);
void cambiarNum(ArrayList* lista);

void primo(eNum*  pNum);
void impar(eNum *pNum);
void par(eNum* pNum);
void completar(ArrayList* lista);
void repetidos(ArrayList* lista,ArrayList* listaRepetidos);
void mostrarNumero(eNum* pNum);
void mostrarTodos(ArrayList* lista);
void cantPares(ArrayList* lista);
void contImpar(ArrayList* lista);
void contPrimos(ArrayList* lista);
void cantCeros(ArrayList* lista);
int cantidadDelDato(eNum* aux, ArrayList* lista);
void dividir(ArrayList* lista, ArrayList* repetidos, ArrayList* noRepetidos);
void sinRepetidos(ArrayList* lista,ArrayList* noRepetidos);
int contiene(eNum* dato, ArrayList* noRepetidos);
void cargarNuevoNumero(ArrayList*lista);

