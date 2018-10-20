#include <stdio.h>
#include <stdlib.h>
#include "miLibreria.h"


int main()
{
    float a=0;
    float b=0;
    int opcion=0;
    int seguir=1;


    while(seguir==1)
    {

        printf("1- Ingresar 1er operando: (A= %.2f) \n",a);
        printf("2- Ingresar 2do operando: (B=%.2f) \n",b);
        printf("3- Calcular la suma (%.2f+%.2f)\n",a,b);
        printf("4- Calcular la resta (%.2f-%.2f)\n",a,b);
        printf("5- Calcular la division (%.2f/%.2f)\n",a,b);
        printf("6- Calcular la multiplicacion (%.2f*%.2f)\n",a,b);
        printf("7- Calcular el factorial (%.2f!)\n",a);
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        printf("Ingrese numero de opcion: ");
        scanf("%d",&opcion);


        printf("\n");


        switch(opcion)
        {
            case 1:
                printf("Ingrese un numero: ");
                scanf("%f",&a);
                printf("\n");
                break;
            case 2:
                printf("Ingrese un numero: ");
                scanf("%f",&b);
                printf("\n");
                break;
            case 3:
                printf("La suma es: %.2f\n\n",suma(a, b));
                printf("\n");
                break;
            case 4:
                printf("La resta es: %.2f\n\n",resta(a, b));
                printf("\n");
                break;
            case 5:
                division(a,b);
                printf("\n");
                break;
            case 6:
                printf("La multiplicacion es: %.2f\n\n",multiplicacion(a,b));
                printf("\n");
                break;
            case 7:
                factorial(a);
                printf("\n");
                break;
            case 8:
              printf("La suma es: %.2f\n\n",suma(a, b));
              printf("La resta es: %.2f\n\n",resta(a,b));
              division(a,b);
              printf("La multiplicacion es: %.2f\n\n",multiplicacion(a,b));
              factorial(a);
              printf("\n");
              break;
            case 9:
                seguir=0;
                break;
            default:
                printf("Ese numero de opcion no existe.\n\n");
                break;
        }
    }

system("Pause");
    return 0;
}




