#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[1000];
    int puntaje;
    char linkImagen[100];
    int estado;
}eMovie;


/** \brief Permite hacer un borrar del archivo una pelicula
 *
 * \param movie Es donde se cargaran los datos que se leen desde el archivo
 */
void borrar(eMovie movie);




/** \brief Permite modificar los datos de una pelicula del archivo
 *
 * \param film Es donde se cargaran los datos que se leen desde el archivo
 */
void modificacion(eMovie film);



/** \brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 *  \param movie Es donde se cargaran los datos que se leen desde el archivo para pasarlos al HTML
 */
void generarPagina(eMovie movie);





/** \brief Permite agregar todos los datos de la estructura eMovie a el archivo binario
 *
 * \param movie Es donde se cargan los datos para despues pasarlos al archivo
 *
 */
void agregarPelicula(eMovie movie);




/** \brief Carga el titulo a la estructura
 *
 * \param *movie Es un puntero a la estructura que se esta cargando
 */
void titulo(eMovie *movie);




/** \brief Carga el genero a la estructura
 *
 * \param *film Es un puntero a la estructura que se esta cargando
 *
 */
void getStringGenero(eMovie *film);





/** \brief Carga la duracion a la estructura
 *
 * \param  *movie Es un puntero a la estructura que se esta cargando
 *
 */
void duracion(eMovie *movie);




/** \brief Carga la descripcion a la estructura
 *
 * \param  *movie Es un puntero a la estructura que se esta cargando
 *
 */
void descripcion(eMovie *movie);




/** \brief Carga el puntaje a la estructura
 *
 * \param  *movie Es un puntero a la estructura que se esta cargando
 *
 */
void puntaje(eMovie* movie);





/** \brief Carga el link de la imagen a la estructura
 *
 * \param  *movie Es un puntero a la estructura que se esta cargando
 *
 */
void linkImagen(eMovie *movie);






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
 * \param input Array donde se cargar· el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);




/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);


/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);
#endif // FUNCIONES_H_INCLUDED
