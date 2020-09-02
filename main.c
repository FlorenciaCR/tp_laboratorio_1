#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funciones.h"

/*en el funciones.c se pone include funciones.h*/


int main()
{
    int opcion;
    int numeroA;
    int numeroB;

    int suma;
    int resta;
    float division;
    int multiplicacion;
    long long int factorialA;
    long long int  factorialB;

    int ingresoNumA=0;
    int ingresoNumB=0;
    int ingresoOp3=0;


    //ver de hacer una funcion de error que pase x parametro la opcion q debe hacer
    //hacer factorial
    //hacer opcion de confirm para salir.



    do
    {

        mostrarMenu(numeroA,numeroB,ingresoNumA,ingresoNumB);

        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {

        case 1:
            numeroA= tomarNumero("Ingrese primer numero: ");
            ingresoNumA=1;
            break;

        case 2:
            if (ingresoNumA)
            {
                numeroB= tomarNumero("Ingrese segundo numero: ");
                ingresoNumB=1;
            }else{
                printf("Error.Ingrese el primer numero.\n");
            }

            break;

        case 3:
            if(ingresoNumA && ingresoNumB)
            {
                printf("Calculando operaciones...\n");
                suma= funcionSumar(numeroA,numeroB);
                resta= funcionRestar(numeroA,numeroB);
                division= funcionDividir(numeroA,numeroB);
                multiplicacion= funcionMultiplicar(numeroA,numeroB);
                factorialA= funcionFactorial(numeroA);
                factorialB= funcionFactorial(numeroB);

                ingresoOp3=1;
            } else {
                printf("Error. Antes de calcular las operaciones, debe ingresar ambos numeros. (Opciones 1 y 2).\n");
            }

            break;

        case 4:
            if (ingresoOp3)
            {
                mostrarResultados(numeroA,numeroB,suma,resta,division,multiplicacion,factorialA, factorialB);
                //Reinicia las variables a su valor original
                numeroA=0;
                numeroB=0;
                ingresoNumA=0;
                ingresoNumB =0;
                ingresoOp3=0;
            } else {
                printf("Error. Antes debe calcular las operaciones. (Opcion 3).\n");
            }

            break;

        case 5:
            printf("Saliendo de la calculadora.\n");
            //confirmar si esta seguro de que quiere salir.
            break;

        default:
            printf("Opcion invalida. Elija una opcion del menu.\n");

        }//fin switch
        system("pause");
        system("cls");

    }while(opcion !=5);

    return 0;
}
