#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Mostrar mensajes
void mostrarMensaje(char mensaje[])
{
    puts(mensaje);
    system("pause");
    //system("pause") le permitirá al usuario leer el mensaje hasta que pulse una tecla
}

//Tomar numero del usuario
int tomarNumero(char mensaje[])
{
    int numero;

    puts(mensaje);
    scanf("%d",&numero);

    return numero;
}


//Funciones de operaciones matematicas.
int funcionSumar(int a,int b)
{
    int resultado;
    resultado=a+b;
    return resultado;
}

int funcionRestar(int a,int b)
{
    int resultado;
    resultado=a-b;
    return resultado;
}

float funcionDividir(int a, int b)  // ver como validar si es 0.
{
    float resultado;

    if(b==0)
    {
        return 0;
    } else {
        resultado= a/b;
        return resultado;
    }
}

int funcionMultiplicar(int a, int b)
{
    int resultado;
    resultado=a*b;
    return resultado;
}

long long int  funcionFactorial (int n)
{
    long long int  fact = 0;

    if(n > 20){
        return 0;
    }

    if (n >= 0)
    {
        if(n == 1 || n == 0)
        {
            fact = 1;
        } else
        {
            fact = n * funcionFactorial(n - 1);
        }
    } else {
        fact = -1;
    }

    return fact;
}

//Menu de opciones.
void mostrarMenu(int a, int b,int banderaA, int banderaB)
{
    printf("********************MENU*****************\n");
    if(banderaA)
    {
        printf("1.Ingresar 1er operando (A=%d).\n\n",a);
    } else {
        printf("1.Ingresar 1er operando (A=x).\n");
    }

    if(banderaB)
    {
        printf("2.Ingresar 1er operando (B=%d).\n",b);
    } else {
        printf("2.Ingresar 1er operando (B=y).\n");
    }

    if (banderaA && banderaB)
    {
      printf("3.Calcular todas las operaciones.\n");
      printf("  a)Calcular suma (%d + %d).\n",a,b);
      printf("  b)Calcular resta (%d - %d).\n",a,b);
      printf("  c)Calcular division (%d / %d).\n",a,b);
      printf("  d)Calcular multiplicacion (%d * %d).\n",a,b);
      printf("  e)Calcula el factorial de (%d y %d).\n",a,b);
      printf("4.Informar los resultados.\n");
    } else {
        printf("3.Calcular todas las operaciones.\n");
        printf("  a)Calcular suma (A + B).\n");
        printf("  b)Calcular resta (A - B).\n");
        printf("  c)Calcular division (A - B).\n");
        printf("  d)Calcular multiplicacion (A - B).\n");
        printf("  e)Calcula el factorial de (A y B).\n");
        printf("4.Informar los resultados.\n");
    }
    printf("5.Salir\n\n");
    printf("******************************************\n\n");

}

//Resultados de todas las operaciones.
void mostrarResultados(int a, int b,int opSuma, int opResta,float opDiv,int opMultip, long long int factorialA, long long int factorialB)
{
    printf("El resultado de %d + %d es: %d\n",a, b,opSuma);
    printf("El resultado de %d - %d es: %d\n",a, b,opResta);
    //Resultado de la division en caso de ser 0
    if(opDiv == 0)
    {
        printf("Error .No se puede dividir por 0.\n");
    }
    else
    {
        printf("El resultado de %d / %d es: %.2f\n",a, b,opDiv);
    }
    printf("El resultado de %d * %d es: %d\n",a, b,opMultip);

    //Resultado de los factoriales en caso de ser 1 o 0
     if (factorialA == -1)
    {
        printf("\ne)Error: No se puede calcular el factorial de %d porque es un numero negativo.\n" ,a);
    }
    else if (factorialA == 0){
        printf("\ne)Error: No se puede calcular el factorial de %d porque el numero ingresado es demasiado grande para este sistema. Por favor, ingrese un numero menor o igual a 20.\n", a);
    }
    else
    {
        printf("\ne)El factorial de %d es: %ld \n", a, factorialA);
    }

    if (factorialB == -1)
    {
        printf("\ne)Error: No se puede calcular el factorial de %d porque es un numero negativo.\n",b);
    }
    else if (factorialB == 0){
        printf("\ne)Error: No se puede calcular el factorial de %d porque el numero ingresado es demasiado grande para este sistema. Por favor, ingrese un numero menor o igual a 20.\n", b);
    }
    else
    {
        printf("\ne)El factorial de %d es: %ld \n",b,factorialB);
    }


}
