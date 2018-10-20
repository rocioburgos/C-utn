#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"


int main()
{
    eProgramador plantel[P];
    eCategoria categoria[C];
    eProyecto proyecto[S];

    eProyectoProgramador progPro[R];
    eDemandante popular[S];// la misma cantidad que los proyectos
    int opcion =0;
    char seguir='s';
    char numAux[25];


    cargarEstado(plantel,P);
    cargarProgramadores(plantel);
    cargarCategoria(categoria);
    cargarProyectos(proyecto);
    ppCero(progPro);
    cargarAproyectos(progPro);
    cargareDemandate(popular,proyecto,S);

    do
    {
        printf("1)Alta\n2)Modificar Datos\n3)Baja\n4)Asignar a proyecto\n5)Listar Porgramadores\n6)Listar proyectos\n7)Listar proyecto con programadores\n8)Proyecto con mas programadores\n");
        printf("9)Cuanto cobra cada programador\n10)Cuanto paga cada proyecto\n11)Salir");
        getString("\nIngrese opcion: ", numAux);
        while(!esNumerico(numAux))
        {
            getString("Error. Reingrese:", numAux);
        }
        opcion= atoi(numAux);


        switch(opcion)
        {
        case 1:
            printf("---Alta---");
            alta(plantel,P,categoria);
            break;
        case 2:
            modificacion(plantel,P,categoria);
            break;
        case 3:
            borrar(plantel,P,proyecto,progPro,categoria);
            break;
        case 4:
            asignarProyecto(plantel,P,proyecto,S,progPro,categoria);
            break;
        case 5:
            listarProgramadoresConProyecto(plantel,P,proyecto,progPro,categoria);
            break;
        case 6:
            listarAllProyectos(progPro,proyecto);
            break;
        case 7:
            seleccionarProgramador(plantel,P,progPro,proyecto,categoria);
            break;
        case 8:
            proyectoDemandante(progPro, popular,S,proyecto);
            break;
        case 9:
            totalSueldo(plantel,P,proyecto,progPro,categoria);
            break;
        case 10:
            pagoDeProyectos(plantel,proyecto,progPro,categoria);
            break;
        case 11:
            seguir='n';
            break;
        default:
            printf("Ese numero de opcion no existe.");
            break;
     }
    }
    while(seguir=='s');
    return 0;
}

