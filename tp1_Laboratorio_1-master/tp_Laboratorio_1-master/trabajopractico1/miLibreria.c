#include <stdio.h>

float suma(float a, float b)
    {

        return a+b;
    }

float resta(float a, float b)
    {
        return a-b;
    }

float division(float a,float b)
{
    float div;
    if(b!=0)
    {
     div= a /b;
     return printf("La division es: %.2f\n\n",div);
    }
    else
    {
      return  printf("Division: Error. El segundo valor es cero.\n\n");
    }

}

float multiplicacion(float a, float b)
{
    float multi;
    multi=a*b;
    if(multi==0)
    {
        multi=0;
    }
    return multi;
}

int factorial(float a)
{

   int numero= a;
   float i;
   int fact=1;
    if(numero<0)
    {
      return printf("Error. El factorial de un negativo no existe.\n\n");
    }
   else
    {
        if(numero<=12)
        {
            for(i=numero; i>=1; i--)
            {
                fact=fact*i;
            }
            return printf("El factorial es: %d\n\n",fact);
        }
        else
        {
           return printf("Error. Solo calcula hasta el factor de 12.\n\n");
        }


    }
}




