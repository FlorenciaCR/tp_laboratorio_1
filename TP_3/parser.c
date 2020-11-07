#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char id[150];
    char nombre[150];
    char horasTrabajadas[150];
    char sueldo[150];
    int cuantos=0;

    Employee* pEmpleado;

    if(pFile != NULL && pArrayListEmployee !=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

        while(!feof(pFile))
        {
            cuantos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre, horasTrabajadas, sueldo);
            if (cuantos == 4)
            {
                pEmpleado = employee_newParametros(id,nombre, horasTrabajadas, sueldo);

                if (pEmpleado != NULL)//Si pudo cargar.
                {
                    ll_add(pArrayListEmployee, pEmpleado);
                    todoOk = 1;
                }
            } else {
                    break;//Sale del while.
             }
        }
    } else {
        printf("Archivo inexistente.\n");
        exit(EXIT_FAILURE);
    }
    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* pEmpleado;

    if(pFile != NULL && pArrayListEmployee != NULL)//Lee archivo.
    {
        do
        {
            pEmpleado = employee_new();

            if(fread(pEmpleado, sizeof(Employee), 1, pFile) == 1) //Lee datos binarios.
            {
                ll_add(pArrayListEmployee, pEmpleado);
                todoOk = 1;
            }
        }while(!feof(pFile));//Mientras no sea el final del archivo sigue leyendo.
    } else {
        employee_delete(pEmpleado);//Libero memoria.
    }
    return todoOk;
}
