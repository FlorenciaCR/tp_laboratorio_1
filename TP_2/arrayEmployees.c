#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "inputs.h"


int initEmployees(eEmployee listaEmpleados[], int tam)
{
    int error=-1;
    if(listaEmpleados!=NULL && tam >0)
    {
        for(int i=0;i<tam;i++)
        {
            listaEmpleados[i].isEmpty=1; //Vacios
        }

        error=0;
    }

    return error;
}

int menu ()
{
    int opcion;
    printf("***************************************************************\n");
    printf("*                 Menu ABM E INFORMES DE EMPLEADOS           *\n");
    printf("***************************************************************\n");
    printf("     1-Alta de un empleado.\n");
    printf("     2-Modificar datos de un empleado.\n");
    printf("     3-Baja de un empleado.\n");
    printf("     4-Informar.\n");
    printf("     5-Salir.\n");

    opcion= getInt("Ingrese una opcion del menu:\n","Error.Reingrese opcion:\n",1,5);


    return opcion;
}

int menuModificarDatosEmpleado (void)
{
    int opcion;
    printf("\n\n");
    printf("****Eleccion de dato a modificar****\n");
    printf("   1-Nombre\n");
    printf("   2-Apellido\n");
    printf("   3-Salario\n");
    printf("   4-Sector\n");
    printf("   5-Salir\n");

    opcion= getInt("Ingrese dato a modificar: ", "Error. Reingrese dato a modificar: ", 1,5);

    return opcion;
}

int menuElegirId (void)
{
    int opcion;
    printf("   1-Ingresar un id\n");
    printf("   2-Volver al menu principal\n");

    opcion= getInt("Ingrese opcion: ", "Error. Ingrese una opcion valida: ", 1,2);

    return opcion;
}

int menuInformesEmpleados(void)
{
    int opcion;

    printf("\n*********Menu de Informes*********\n");
    printf("  1-Ordenar lista de empleados\n");
    printf("  2-Informar total y promedio de salarios\n");
    printf("  3-Salir\n");


    opcion=getInt("Ingrese opcion: ", "Error. Reingrese opcion: ",1,3);
    return opcion;
}

void printEmployee(eEmployee empleado)
{
    printf("\n");
    printf("%4d   %10s %10s      %10.2f     %3d\n", empleado.id,
           empleado.name,
           empleado.lastName,
           empleado.salary,
           empleado.sector);
}

void printEmployees(eEmployee listaEmpleados[], int tam)
{
    int flag=0;

    if(listaEmpleados != NULL && tam > 0)
    {
        printf("\n                 Lista de empleados                    \n");
        printf("ID          NOMBRE     APELLIDO      SALARIO     SECTOR\n");
        printf("----------------------------------------------------------\n");

        for(int i=0; i<tam; i++)
        {
            if(listaEmpleados[i].isEmpty==0)
            {
                printEmployee(listaEmpleados[i]);
                flag=1;
            }
        }
        if(!flag) //flag==0;
        {
            printf("No hay personas en la lista.\n");
        }
        else
        {
            printf("\n");
        }
    }
    printf("\n");
}

int findEmptySpace(eEmployee listaEmpleados[], int tam)
{
    int indice= -1; //Por defecto devuelve que no hay lugar

    for(int i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty == 1) // 1 es LIBRE 0 OCUPADO
        {
            indice= i;
            break;
        }
    }
    return indice;
}

int isEmpty(eEmployee listaEmpleados[], int tam)
{

    int isEmpty = 1;

    for(int i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty == 0)
        {
            isEmpty = 0;
            break;
        }
    }
    return isEmpty;
}

int findEmployeeById(eEmployee listaEmpleados[],int id, int tam)
{
    int indice= -1;


    if(listaEmpleados !=NULL && tam>0 && id >0)
    {
        for(int i=0; i < tam ; i++)
        {
            //si el legajo es =  y la persona esta cargada osea lugar ocupado.
            if (listaEmpleados[i].id == id && listaEmpleados[i].isEmpty == 0)
            {
                indice= i; //devuelve el indice donde esta ese id cargado
                printf("Empleado encontrado.\n");
                break;
            }
        }
    }
    return indice;
}

int removeEmployee(eEmployee listaEmpleados[], int tam)
{
    int indice;
    char confirmar;
    int id;
    int error= -1;
    int opcionMenuElegirId;

    if(listaEmpleados != NULL && tam >0)
    {
        system("cls");
        printf("Baja de empleado.\n\n");

        printEmployees(listaEmpleados, tam);

        opcionMenuElegirId = menuElegirId();

        if(opcionMenuElegirId == 2){
            error = 4;
            return error;
        }

        id= getInt("Ingrese el ID del empleado a dar de baja:\n", "Error. Reingrese id: \n",1000,10000);

        if(id >= 0)
        {
            indice= findEmployeeById(listaEmpleados,id, tam);//devuelve -1 o el indice encontrado

            //si no hay indice o esta vacio
            if(indice == -1 || listaEmpleados[indice].isEmpty==1)
            {
                error = 2; //No se han realizado modificaciones en el empleado.
            }
            else
            {
                printEmployee(listaEmpleados[indice]);
                confirmar= getCharSoN("¿Esta seguro que quiere continuar con la baja?(s/n)","Error.Reingrese opcion(s/n): ");

                if (confirmar == 's')
                {
                    listaEmpleados[indice].isEmpty= 1;
                    error=0;//Se ha dado de baja al empleado exitosamente

                }
                else if (confirmar == 'n')
                {
                    error=1; //Se cancelo la baja al empleado
                }
                else
                {
                    error=3; //Opcion no valida
                }
            }
        }
    }
    return error;
}

int updateEmployee(eEmployee listaEmpleados[], int tam)
{
    int error= 1;
    int modifico=0; //flag
    int indice;
    int id;
    int opcion;
    eEmployee employeeAux;
    int stringOk;
    int opcionMenuElegirId;

    printf("             ***Modificar persona.***         \n");

    if(listaEmpleados != NULL && tam >0 )
    {
        printEmployees(listaEmpleados, tam);

        opcionMenuElegirId = menuElegirId();

        if(opcionMenuElegirId == 2){
            error = 2; //No se realizo ninguna modificacion
            return error;
        }

        id= getInt("Ingrese el ID del empleado a modificar:\n", "Error. Ingrese un id valido: ", 1000, 2000);

        if(id >=0)
        {
            indice= findEmployeeById(listaEmpleados,id ,tam); //-1 error o indice persona

            if(indice == -1)
            {
                error=1; //No existe el id
            }
            else
            {
                do
                {
                    printf("Empleado seleccionado para modificar:\n");
                    printEmployee(listaEmpleados[indice]);
                    opcion= menuModificarDatosEmpleado();

                    switch(opcion)
                    {

                    case 1:
                        stringOk= getString(employeeAux.name,"\nIngrese nuevo nombre: ","Error.Reingrese nuevo nombre: ",20);
                        if(stringOk==1)
                        {
                            strcpy(listaEmpleados[indice].name, employeeAux.name);
                        }

                        modifico=1;
                        break;
                    case 2:
                        stringOk= getString(employeeAux.lastName,"\nIngrese el nuevo apellido: ","Error.Reingrese nuevo apellido: ",20);
                        if(stringOk==1)
                        {
                            strcpy(listaEmpleados[indice].lastName, employeeAux.lastName);
                        }

                        modifico=1;
                        break;
                    case 3:
                        employeeAux.salary = getFloat("Ingrese el nuevo salario: ","Error.Reingrese nuevo salario: ",0.0,100000.0);
                        listaEmpleados[indice].salary = employeeAux.salary;
                        modifico=1;
                        break;
                    case 4:
                        employeeAux.sector= getInt("Ingrese nuevo sector: ", "Error. Reingrese el nuevo sector: ",1,10);
                        listaEmpleados[indice].sector= employeeAux.sector;
                        modifico=1;
                        break;
                    case 5:
                        printf("Saliendo de modificaciones.\n");
                        break;
                    default:
                        printf("\n*Error. Ingrese una opcion valida.*\n\n");
                        system("pause");
                        break;
                    }

                    if(modifico)
                    {
                        error=0; //Se han realizado modificaciones
                    } else {
                        error=2; //No se realizo ninguna modificacion
                    }
                }
                while(opcion!=5);
            }
        }
    }
    return error;
}

void employeeReports(eEmployee listaEmpleados[], int tam)
{
    int opcionInformes;
    int ordenAoD;
    float salarioTotal;
    float salarioPromedio;
    int cantidadEsuperanPromedio;

    system("cls");
   do{
        opcionInformes= menuInformesEmpleados();
        switch(opcionInformes)
        {
        case 1:
            printf("\nOrdenar empleados por apellido y sector.\n");
            ordenAoD= getInt("Ingrese tipo de ordenamiento: (1 Ascendente o 2 Descendete): ","Error. Ingrese 1 para ascendente o 2 para descendente: ", 1,2);
            if(sortEmployee(listaEmpleados,tam,ordenAoD)==0)
            {
                printEmployees(listaEmpleados, tam);
                printf("\nSe ha realizado el ordenamiento.\n");
            } else {
                printf("\nNo se ha podido realizar el ordenamiento.\n");
            }
            break;
        case 2:
            printf("\n\nTotales, promedios y empleados.\n");
            salarioTotal = totalSalary(listaEmpleados,tam);
            salarioPromedio = averageSalary(listaEmpleados,tam);


            printf("La suma total de los salarios es: %.2f .\n", salarioTotal);
            printf("El promedio salarial total de los empleados es: %.2f .\n", salarioPromedio);
            cantidadEsuperanPromedio = employeesAboveAverageS(listaEmpleados, tam);
            printf("Los empleados que superan el promedio salarial son: %d .\n\n",cantidadEsuperanPromedio);

        default:
            break;

        }
   }while(opcionInformes!=3);

}

int sortEmployee(eEmployee listaEmpleados[], int tam, int orden)
{
    int i;
    int j;
    eEmployee employeeAux;
    int error =1;

    if(listaEmpleados != NULL && tam >0)
    {

        switch (orden)
        {
        case 1: // ASCENDENTE POR SECTOR y APELLIDO
            for(i=0; i < tam - 1; i++)
            {
                for(j= i + 1 ; j< tam ; j++)
                {
                   if(listaEmpleados[i].sector > listaEmpleados[j].sector)
                   {
                       employeeAux = listaEmpleados[i];
                       listaEmpleados[i] = listaEmpleados[j];
                       listaEmpleados[j] = employeeAux;
                   } else if ((listaEmpleados[i].sector == listaEmpleados[j].sector) && (strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName) > 0))
                    {
                        employeeAux = listaEmpleados[i];
                        listaEmpleados[i] = listaEmpleados[j];
                        listaEmpleados[j] = employeeAux;
                    }
                }
            }
            error=0; //Se ordeno
            break;
        case 2: // DESCENDENTE POR SECTOR Y APELLIDO
              for(i=0; i < tam - 1; i++)
            {
                for(j= i + 1 ; j< tam ; j++)
                {
                   if(listaEmpleados[i].sector < listaEmpleados[j].sector)
                   {
                       employeeAux = listaEmpleados[i];
                       listaEmpleados[i] = listaEmpleados[j];
                       listaEmpleados[j] = employeeAux;
                   } else if ((listaEmpleados[i].sector == listaEmpleados[j].sector)&& (strcmp(listaEmpleados[i].lastName, listaEmpleados[j].lastName) < 0))
                    {
                        employeeAux = listaEmpleados[i];
                        listaEmpleados[i] = listaEmpleados[j];
                        listaEmpleados[j] = employeeAux;
                    }//Se ordeno de forma DESCENDENTE
                }
            }
            error= 0;
            break;
        }
    }

    return error;
}

 float totalSalary(eEmployee listaEmpleados[], int tam)
 {
     int i;
     float totalS=0;

     if(listaEmpleados != NULL && tam >0)
     {
         for(i=0; i < tam; i++)
         {
             if(listaEmpleados[i].isEmpty ==0)
             {
                totalS = totalS + listaEmpleados[i].salary;
             }
         }

     }
     return totalS;
 }

 float averageSalary(eEmployee listaEmpleados[], int tam)
 {
     float averageS;
     int i;
     int contador=0;
     float totalSalaryE;

     totalSalaryE = totalSalary(listaEmpleados,tam);

     if(listaEmpleados != NULL && tam >0)
     {
         for (i=0; i < tam; i++)
         {
             if(listaEmpleados[i].isEmpty ==0)
             {
                 contador++;
             }
         }

         averageS = (float)totalSalaryE/ contador;
     }

    return averageS;
 }

 int employeesAboveAverageS(eEmployee listaEmpleados[], int tam)
 {
     int i;
     int contadorEmpleados=0;
     float averageSalaryE;

     averageSalaryE = averageSalary(listaEmpleados,tam);

     for(i=0; i < tam; i++)
     {
         if((listaEmpleados[i].salary > averageSalaryE) &&(listaEmpleados[i].isEmpty ==0))
         {
             contadorEmpleados++;
             printEmployee(listaEmpleados[i]);
         }
     }
     return contadorEmpleados;
 }

eEmployee createEmployee(int id)
{
    int stringOk;
    char auxCadena[20];
    eEmployee newEmployee;

    newEmployee.id = id;
    stringOk= getString(auxCadena,"Ingrese nombre: ", "Error. Reingrese nombre: ",20);
    if(stringOk==1)
    {
        strcpy(newEmployee.name,auxCadena);
    }

    stringOk= getString(auxCadena,"Ingrese apellido: ", "Error. Reingrese apellido: ",20);
    if(stringOk==1)
    {
        strcpy(newEmployee.lastName,auxCadena);
    }

    newEmployee.salary= getFloat("Ingrese salario: ","Error. Reingrese salario: ",0.0,100000.0);
    newEmployee.sector= getInt("Ingrese sector: ", "Error. Reingrese sector: ", 1,10);
    printf("\n");

    newEmployee.isEmpty=0;
    return newEmployee;
}

int addEmployee(eEmployee listaEmpleados[], int tam, int id)
{
    int indice;
    int error=1;

    indice= findEmptySpace(listaEmpleados,tam);
    if(indice != -1)
    {
        listaEmpleados[indice]= createEmployee(id);
        error=0;
    }
    return error;
}





