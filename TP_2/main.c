#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "inputs.h"
#define T 1000


int main()
{
    eEmployee listaDeEmpleados[T];
    int opcionMenuPrincipal;
    int retorno;
    int proximoId = 1000; //Incrementa cuando se carga un empleado.

    int hayEmpleados = 0;


    initEmployees(listaDeEmpleados,T);

    do
    {
        opcionMenuPrincipal=menu();

        switch(opcionMenuPrincipal)
        {
            case 1:
                retorno= addEmployee(listaDeEmpleados,T,proximoId);
                if(retorno==0)
                {
                    printf("Se ha realizado la carga exitosamente.\n");
                    proximoId++;
                    hayEmpleados = 1;

                } else {
                    printf("Sistema completo, no se puede cargar mas empleados.\n");
                }
                break;

            case 2:
                if(!hayEmpleados){
                    printf("No hay empleados para modificar. Debe ingresar empleados (opcion 1)\n");
                    break;
                }

                retorno= updateEmployee(listaDeEmpleados,T);
                switch(retorno)
                {
                case 0:
                    printf("Se realizo la modificacion.\n");
                    break;
                case 1:
                    printf("Empleado inexistente\n");
                    break;
                case 2:
                    printf("No se han realizado modificaciones en el empleado.\n");
                    break;

                }
                break;

            case 3:
                if(!hayEmpleados){
                    printf("No hay empleados para borrar. Debe ingresar empleados (opcion 1)\n");
                    break;
                }
                retorno = removeEmployee(listaDeEmpleados,T);
                switch(retorno)
                {
                    case 0:
                        printf("Se ha dado de baja al empleado exitosamente.\n");
                        if(isEmpty(listaDeEmpleados, T)){
                            hayEmpleados = 0;
                        }
                    break;

                    case 1:
                        printf("Se cancelo la baja al empleado.\n");
                    break;

                    case 2:
                        printf("No se ha encontrado ese ID.\n");
                    break;

                    case 3:
                        printf("Opcion no valida.\n");
                    break;
                }
                break;

            case 4:
                if(!hayEmpleados){
                    printf("No hay empleados para reportar. Debe ingresar empleados (opcion 1)\n");
                    break;
                }
                employeeReports(listaDeEmpleados,T);
                break;

            case 5:
                printf("Saliendo del ABM.\n");
                break;

            default:
                printf("Error. Ingrese una opcion valida\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcionMenuPrincipal!=5);


    return 0;
}

