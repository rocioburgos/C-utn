#include <stdio.h>
#include <stdlib.h>
#define P 10 //para la cantidad de programadores
#define S 3 //para los proyectos
#define C 3// para las categorias
#define R P*S //para el array de la estructura pp[]

typedef struct
{
    int id;
    char nombre[20];
    char apellido[30];
    int estado;
    int idCategoria;

} eProgramador;


typedef struct
{
    int idCategoria;
    char descripcion[20];
    int pagoPorH;
} eCategoria;



typedef struct
{
    int idProyecto;
    char nombreProyecto[20];
    int estado;
} eProyecto;

typedef struct
{
    int idProgramador;
    int idProyecto;
    int horasDeTrabajo;

} eProyectoProgramador;

typedef struct
{
    int idProyecto;
    int cont;
} eDemandante;

/** \brief Permite cargar siete programadores apenas comienza el programa
 */
void cargarProgramadores(eProgramador programador[]);

/** \brief Permite cargar los datos de las tres categorias que existen
 */
void cargarCategoria(eCategoria categoria[]);

/** \brief Permite cargar tres proyectos al programa
 */
void cargarProyectos(eProyecto proyecto[]);


/** \brief Permite cargar los campos de la estructura eDemandate
     *
     *\param popular[] Es donde se van a cargar los datos
     *\param proyecto[] Es la estructura de donde se va a obtener el ID del proyecto
     *                    que se carga en popular[]
     * \param  tam Es la cantidad de proyectos
     *
     */
void cargareDemandate(eDemandante popular[],eProyecto proyecto[], int tam);



 /** \brief Busca un indice que tenga el estado cero para poder cargar los datos
 *
 * \param programador[] Es el array de la estructura donde debe buscar el estado=0
 * \param tam Es el tamaño del array
 * \return si encontro un estado=0 retorna el valor de "i" , si no encuentra ningun indice libre retorna -1
 *
 */

int indiceLibre(eProgramador programador[],int tam);

/** \brief Permite cargar todosloscampos de la estructura eProyectoProgramador
*          a cero, inicando que se encuentran eslos espacios libres
 */
void ppCero(eProyectoProgramador progPro[]);

/** \brief Permite cargar todos los estados de los programadores
*          a cero, inicando que se encuentran  los espacios libres
 */
void cargarEstado(eProgramador programador[], int tam);

/** \brief Permite asignar a proyectos los programadores precargados
 *
 */
void cargarAproyectos(eProyectoProgramador pp[]);

/** \brief Permite dar de alta un programador
 *
 * \param  programador[] Es donde se van a cargar los datos
 * \param tam Es la cantidad de programadores
 * \param cat[] Permite buscar dentro de las categorias a las que puede pertenecer el programador
 *
 */
void alta(eProgramador programador[], int tam, eCategoria cat[]);

/** \brief Permite obtener y cargar el nombre con todas las validaciones para que el programa no se cuelgue
 *         (que no se desborde el array, que sean solo letras)
 *  \param prog[] Es donde va a cargar el nombre
 *  \param  indice Es el indice en el cual se va a guardar el dato
 */
void nombre(eProgramador prog[],int indice);



/** \brief Permite obtener y cargar el apellido con todas las validaciones para que el programa no se cuelgue
 *         (que no se desborde el array, que sean solo letras)
 *
 *  \param prog[] Es donde va a cargar el apellido
 *  \param  indice Es el indice en el cual se va a guardar el dato
 */
void apellido(eProgramador prog[],int indice);



/** \brief Permite obtener y cargar el apellido con todas las validaciones para que el programa no se cuelgue
 *         (que no se desborde el array, que sean solo letras)
 * \param  programador[] Es donde se va a cargar el ID de la categoria a la cual pertenece
 * \param  cat[] Es donde se encuentran las categorias a las que pueden pertenecer los programadores
 * \param  indice Es el indice en el cual se va a guardar el dato
 */
void categoria(eProgramador programador[],eCategoria cat[],int indice);


/** \brief Permite modificar los datos del programador
 *
 * \param  programador[] Se busca que el ID existe y cambiarle los datos que se encuentran en ese indice
 * \param tam Es la cantidad de programadores entre los cuales hay que buscar
 * \param cat[] Permite buscar la categoria
 *
 */
void modificacion(eProgramador programador[], int tam, eCategoria cat[]);


/** \brief Permite asignar a un programador a un proyecto
 *
 * \param programador[] permite obtener los datos del programador
 * \param tam La cantidad de programadores
 * \param proyecto[] Se buscan dentro de los proyectos que existen
 * \param tamP Es la cantidad de proyectos
 * \param pp[] Es para guardar la cantidad de horas que trabaja , el IDproyecto y el IDprogramador
 * \param categoria[] Es para saber a que categoria pertenece y cuanto es lo que se le paga
 */
void asignarProyecto(eProgramador programador[],int tam, eProyecto proyecto[],int tamP, eProyectoProgramador pp[],eCategoria categoria[]);

/** \brief Realiza una baja logica al programador dejando ese espacio como libre para ser ocupado
 *
 */
void borrar(eProgramador programador[],int tam, eProyecto proyecto[], eProyectoProgramador pp[],eCategoria categoria[]);

/** \brief Permite mostrar todos los proyectos
 *
 * \param pp[] Permite recorrer todos los proyectos que tienen un programador
 * \param proyecto[] Permite mostrar la informacion de cada proyecto

 */
void listarAllProyectos(eProyectoProgramador pp[],eProyecto proyecto[]);

/** \brief Permite mostrar los programadores junto con sus proyectos
 *
 */
void listarProgramadoresConProyecto(eProgramador prog[],int tam,eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/** \brief Recibe un array para validar que desborde el programa
 *
 * \param validar Es el dato a validar
 * \param  max Es el maximo de caracteres que debe tener el dato que recibe
 * \return 1 si es mayor o igual al maximo    0 si no desborda el array
 *
 */
int validacionCantidadMaxima(char validar[], int maximo);

/** \brief Permite obtener un texto verificado
 *
 * \param input[] es el string que recibe
 * \param recibe un entero de cual es la cantidad maxima a verificar
 * \return 1 si no supera a la cantidad maxima, 0 si supera a la cantidad maxima
 *
 */
int cantidadMaxima(char input[], int);

/** \brief Permite mostrar un programador con todos sus datos
 *
 * \param programador[] contiene  los datos de los programdores
 * \param indice Recibe el indice del programador que debe mostrar
 * \param categoria[] Para mostrar el nombre de la categoria
 *
 */
void mostrarProgramador(eProgramador programador[], int indice,eCategoria categoria[]);

/** \brief Permite mostrar a todos los programadores recibiendo (tam) la cantidad de programadores
 *
 *
 */
void mostrarProgramadores(eProgramador programador[], int tam,eCategoria categoria[]);

/** \brief Permite mostrar un proyecto con todos sus datos
 *
 * \param pro[] contiene  los datos del  proyecto
 * \param indice Recibe el indice del proyecto que debe mostrar
 *
 */
void mostrarProyecto(eProyecto pro[], int indice);

/** \brief Permite mostrar a todos los proyectos recibiendo (tam) la cantidad de proyectos
 *
 *
 */
void mostrarProyectos(eProyecto pro[], int tam);


/** \brief Permite mostrar a todos los proyectos de un programador
 *
 */
void seleccionarProgramador(eProgramador prog[],int tam,eProyectoProgramador pp[],eProyecto proyecto[], eCategoria categoria[]);

/** \brief Permite mostrar un proyecto determinado pasandole como parametro el ID
 *
 */
void mostrarProyectoSegunID(int id, eProyecto proyecto[]);



/** \brief Permite encontrar el proyecto con mas programadores y mostrar sus datos
 *
 */
void proyectoDemandante(eProyectoProgramador pp[],eDemandante popu[],int tam,eProyecto proyecto[]);

/** \brief Muestra el pago total de cada programador
 *
 */
 void totalSueldo(eProgramador prog[],int tam,eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[]);


 /** \brief Muestra el pago total de los proyectos
  *
  */
  void pagoDeProyectos(eProgramador prog[],eProyecto proyecto[],eProyectoProgramador pp[],eCategoria categoria[]);

