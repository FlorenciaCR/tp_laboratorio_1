#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "funciones.h"

int main()
{
    char opcion;
    int numeroA;
    int numeroB;
    char salir = 'n';
    char confirma;

    int suma;
    int resta;
    float division;
    int multiplicacion;
    long long int factorialA;
    long long int  factorialB;
    //Banderas que indican el ingreso de numeros o de opciones.
    int ingresoNumA=0;
    int ingresoNumB=0;
    int ingresoOp3=0;
    int ingresoOp4=0;

    do
    {
        mostrarMenu(numeroA,numeroB,ingresoNumA,ingresoNumB);

        printf("\nElija una opcion: ");
        scanf("%s",&opcion);
        fflush(stdin);

        switch(opcion)
        {

        case '1':
            numeroA= tomarNumero("Ingrese primer numero: ");
            ingresoNumA=1; // Bandera que indica que ngreso el primer numero
            break;

        case '2':
            if (ingresoNumA)
            {
                numeroB= tomarNumero("Ingrese segundo numero: ");
                ingresoNumB=1;
            }
            else
            {
                printf("Error.Ingrese el primer numero.\n");
            }

            break;

        case '3':
            if(ingresoNumA && ingresoNumB)
            {
                printf("Calculando operaciones...\n");
                suma= funcionSumar(numeroA,numeroB);
                resta= funcionRestar(numeroA,numeroB);
                division= (float)funcionDividir(numeroA,numeroB);
                multiplicacion= funcionMultiplicar(numeroA,numeroB);
                factorialA= funcionFactorial(numeroA);
                factorialB= funcionFactorial(numeroB);
                ingresoOp3=1; //bandera de que se ingreso a la opcion 3 correctamente
            }
            else
            {
                printf("Error. Antes de calcular las operaciones, debe ingresar ambos numeros. (Opciones 1 y 2).\n");
            }
            break;

        case '4':
            if (ingresoOp3)
            {
                mostrarResultados(numeroA,numeroB,suma,resta,division,multiplicacion,factorialA, factorialB);
                //Reinicia las variables a su valor original
                numeroA=0;
                numeroB=0;
                ingresoNumA=0;
                ingresoNumB =0;
                ingresoOp3=0;
                ingresoOp4=1;
            }
            else
            {
                printf("Error. Antes debe calcular las operaciones. (Opcion 3).\n");
            }
            break;

        case '5':

            printf("¿Confirmar salida? Presione 's' para confirmar salida: \n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma =='s')
            {
                printf("Saliendo de la calculadora.\n\n");
                exit (-1);
            }
            else
            {
                if(ingresoOp4)
                {
                    salir='n';
                }
                else
                {    //Avisa que se mantienen los valores que estaban antes de intentar salir.
                    printf("Atencion: Se han mantenido los valores.\n\n");
                    salir='n';
                }
            }
            break;

        default:
            printf("Opcion invalida. Elija una opcion del menu.\n");

        }//fin switch
        system("pause");
        system("cls");

    }
    while(salir =='n');

    return 0;
}
