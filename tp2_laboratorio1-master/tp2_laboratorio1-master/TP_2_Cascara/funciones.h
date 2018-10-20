#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/** \brief Permite que el usuario ingrese los datos, controlando que no se ingrese un DNI repetido, que haya lugar en
 el vector, si encuentra un lugar y no se repite el DNI los datos se guardan.
 *
 * \param   personas[] contiene la estrucutura de los datos
 * \param   tam el tamaño del vector personas[]
 *
 */
void darDeAlta(EPersona personas[],int tam);


/** \brief Permite dar de baja a una persona cambiandole el estado a 0(cero) ingresando el numero de DNI
 *
 * \param  personas[] contiene la estrucutura de los datos
 * \param   tam el tamaño de la estructura personas[]
 *
 */
void darDeBaja(EPersona personas[],int tam);



/** \brief Muestra la lista de personas ordenada alfabeticamente
 *
 * \param x[] recibe una estructura de personas
 * \param tam recibe el tamaño de la estructura persona
 *
 */
void ordenaryMostrar(EPersona x[],int tam);



/** \brief Imprime el grafico de edades
 *
 * \param recibe una estructura y el tamaño de la misma
 *
 */
void grafico(EPersona persona[], int tam);

#endif // FUNCIONES_H_INCLUDED
