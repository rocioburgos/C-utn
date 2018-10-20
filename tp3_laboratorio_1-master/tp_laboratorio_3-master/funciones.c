#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>


////////////////////////////////////////////

void agregarPelicula(eMovie movie)
{
    FILE *pelicula;

    titulo(&movie);

    getStringGenero(&movie);

    duracion(&movie);

    descripcion(&movie);

    puntaje(&movie);
    linkImagen(&movie);

    movie.estado=1;
    printf("Estado: %d",movie.estado);
    printf("-----Fin de carga-----\n");

    if ((pelicula=fopen("pelicula","rb+"))==NULL)
    {
        if ((pelicula=fopen("pelicula","wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }
    fflush(stdin);
    fseek(pelicula,0L,SEEK_END);
    if((fwrite(&movie,sizeof(movie),1,pelicula))<1)
    {
        printf("No se pudieron cargar los datos");
    }


    if((fclose(pelicula))==-1)
    {
        printf("No se pudo cerrar el archivo.");
    }
    else
    {
        printf("Se cerro el archivo exitosamente.");
    }


}
////////////////////////////////////////////////////////////////////////////////////////

void titulo(eMovie *movie)
{
    char string[100];

    printf("Ingrese el nombre de la pelicula: ");
    fflush(stdin);
    gets(string);
    strlwr(string);
    while((strlen(string))>19)
    {
        printf("Error. Reingrese titulo: ");
        gets(string);
        strlwr(string);
    }
    strcpy(movie->titulo, string);
}
////////////////////////////////////////////////////////////////////////////////////////

void puntaje(eMovie *movie)
{
    char auxPuntaje[3];
    int puntaje;
    int flag=0;

    do
    {
        flag=0;
        printf("Ingrese puntaje de la pelicula: ");
        fflush(stdin);
        gets(auxPuntaje);

    while(esNumerico(auxPuntaje)==0)
    {
        printf("Error.Ingrese el puntaje del 1 al 10: ");
        gets(auxPuntaje);
    }
    puntaje=atoi(auxPuntaje);

        if(puntaje<0||puntaje>10)
        {
            flag=1;
        }

    }
    while(flag==1);

    movie->puntaje=puntaje;

}
////////////////////////////////////////////////////////////////////////////////////////

void duracion(eMovie *movie)
{

    char auxDuracion[5];
    int dura;
    printf("Ingrese duracion de la pelicula en minutos: ");
    gets(auxDuracion);

    while(esNumerico(auxDuracion)==0)
    {
        printf("Error.Ingrese duracion de la pelicula en minutos: ");
        gets(auxDuracion);
    }
    dura= atoi(auxDuracion);



    movie->duracion=dura;
}
////////////////////////////////////////////////////////////////////////////////////////

void descripcion(eMovie *movie)
{
    char string[1050];
    do
    {
        printf("Ingrese descripcion de la pelicula: ");
        fflush(stdin);
        gets(string);

    }
    while((strlen(string))>999);
    strcpy(movie->descripcion,string);
}
////////////////////////////////////////////////////////////////////////////////////////

void linkImagen(eMovie *movie)
{
    char string[150];

    printf("Link imagen: ");
    fflush(stdin);
    gets(string);
    while((strlen(string))>149)
    {
        printf("Error. Reingrese link imagen: ");
        fflush(stdin);
        gets(string);

    }
    strcpy(movie->linkImagen,string);
}
////////////////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////

void getStringGenero(eMovie *film)
{
    int resultado;
    char auxName[50];
    int cantCaracteres;



    resultado=getStringLetras("Ingrese genero de la pelicula: ",auxName);
    cantCaracteres=strlen(auxName);
    while(resultado==0 || cantCaracteres>19)
    {
        printf("Error. ");
        resultado=getStringLetras("Por favor reingrese el genero:",auxName);
        cantCaracteres=strlen(auxName);
    }

    strcpy(film->genero,auxName);


}
////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{


    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
    strlwr(input);
}

///////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////
void borrar(eMovie movie)
{
    char auxname[20];
    int flag=0;
    int cant;
    FILE* pelicula;

    if((pelicula=fopen("pelicula","rb+"))==NULL)
    {

        if((pelicula=fopen("pelicula","wb+"))==NULL)
        {
            printf("NO se puede abrir el archivo");
            exit(1);
        }
    }

    printf("Ingrese el nombre de la pelicula a borrar: ");
    fflush(stdin);
    gets(auxname);

    rewind(pelicula);
    while(!feof(pelicula))
    {

        cant=fread(&movie,sizeof(movie),1,pelicula);
        if(cant!=1)
        {
            if(feof(pelicula))
            {
                break;
            }
            else
            {
                printf("No se puede leer el archivo");
                break;
            }
        }

        if(strcmpi(auxname,movie.titulo)==0 && movie.estado==1)
        {
            movie.estado=0;

            strcpy(movie.titulo,"\0");
            strcpy(movie.genero,"\0");
            movie.duracion=0;
            strcpy(movie.descripcion,"\0");
            movie.puntaje=0;
            strcpy(movie.linkImagen,"\0");

            fflush(stdin);
            fseek(pelicula,(-1)*sizeof(eMovie), SEEK_CUR);

            fwrite(&movie, sizeof(eMovie), 1, pelicula);

            printf("Pelicula eliminada.");
            flag=1;
            break;
        }


    }
    if(flag==0)
    {
        printf("NO SE ENOCNTRO LA PELICULA");
    }

    fclose(pelicula);
}
///////////////////////////////////////////////////

void generarPagina(eMovie movie)
{
    FILE *pagina;
    FILE *pelicula;
    int cant;
    int flag=0;
    char head[]= {"<html>\n<head>\n<body>\n"};

    if((pelicula=fopen("pelicula","rb+"))==NULL)
    {
        if((pelicula=fopen("pelicula","wb+"))==NULL)
        {
            printf("NO se puede abrir el archivo");
            exit(1);
        }
    }

    if((pagina=fopen("pagina.html","w"))==NULL)
    {
        printf("No se pudo abrir el archivo HTML");
        system("pause");
    }
    else
    {


        //los encabezado del HTML
        fprintf(pagina,"%s",head);

        rewind(pelicula);
        while(!feof(pelicula))
        {

            cant=fread(&movie,sizeof(movie),1,pelicula);
            if(cant!=1)
            {
                if(feof(pelicula))
                {
                    break;
                }
                else
                {
                    printf("No se puede leer el archivo");
                    break;
                }
            }
            ///lo que se repite para cada pelicula
            if(movie.estado==1)
            {
                fprintf(pagina,"<article class='col-md-4 article-intro'>\n");
                fprintf(pagina," <a href='#'>\n");
                fprintf(pagina,"<img src='%s' alt='' >\n",movie.linkImagen);
                fprintf(pagina,"</a>\n");
                fprintf(pagina,"<h3>\n");
                fprintf(pagina,"<a href='#'> %s </a>\n",movie.titulo);
                fprintf(pagina,"</h3>\n");
                fprintf(pagina,"<ul>");
                fprintf(pagina,"<li>Género: %s </li>\n",movie.genero);
                fprintf(pagina,"<li>Puntaje:%d</li>\n",movie.puntaje);
                fprintf(pagina,"<li>Duración:%d</li>\n",movie.duracion);
                fprintf(pagina,"<li>Descripcion: %s </li>\n",movie.descripcion);
                fprintf(pagina,"</article>\n");
                flag=1;
            }
        }

            if(flag==0)
            {
                fprintf(pagina,"No hay peliculas cargadas.");
            }
        fprintf(pagina,"</div>\n");
        fprintf(pagina,"<!-- /.row -->\n");
        fprintf(pagina,"</div>\n");
        fprintf(pagina,"<!-- /.container -->\n");
        fprintf(pagina,"<!-- jQuery -->\n");
        fprintf(pagina,"<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pagina,"<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pagina,"<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pagina,"<!-- IE10 viewport bug workaround -->\n");
        fprintf(pagina,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pagina,"<!-- Placeholder Images -->\n");
        fprintf(pagina,"<script src='js/holder.min.js'></script>\n");
        fprintf(pagina,"</body>\n");
        fprintf(pagina,"</html>");


        printf("Pagina generada\n");
        fclose(pagina);
        fclose(pelicula);

    }


}
/////////////////////////////////////////////////////

void modificacion(eMovie film)
{
    FILE * pelicula;
    int cant,flag=0;
    char auxName[20];

    if((pelicula=fopen("pelicula","rb+"))==NULL)
    {

        if((pelicula=fopen("pelicula","wb+"))==NULL)
        {
            printf("NO se puede abrir el archivo");
            exit(1);
        }

    }

    printf("Ingrese el nombre de la pelicula a modificar: ");
    fflush(stdin);
    gets(auxName);


    rewind(pelicula);

    while(!feof(pelicula))
    {
        cant=fread(&film, sizeof(eMovie),1,pelicula);

        if(cant!=1)
        {
            if(feof(pelicula))
            {
                break;
            }
            else
            {
                printf("No se puede leer el archivo");
                break;
            }
        }

        if((strcmpi(auxName,film.titulo))==0 && film.estado==1)
        {
            printf("----Modificacion----\n");
            titulo(&film);
            getStringGenero(&film);
            duracion(&film);
            descripcion(&film);
            puntaje(&film);
            linkImagen(&film);

            fflush(stdin);
            fseek(pelicula,(-1)*sizeof(eMovie),SEEK_CUR);
            fwrite(&film,sizeof(film),1,pelicula);
            printf("Pelicula modificada");
            flag=1;
            break;

        }
    }

    if(flag==0)
    {
        printf("No se encontro la pelicula");
    }
    fclose(pelicula);

}
//////////////////////////////////////////////////////////////
