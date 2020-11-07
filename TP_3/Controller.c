#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

    int todoOk= -1;
    FILE* pMiArchivo;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pMiArchivo=fopen(path,"r");

        if(pMiArchivo != NULL)
        {
            if(parser_EmployeeFromText(pMiArchivo,pArrayListEmployee))
            {
                printf("Se cargaron los datos.\n");
                system("pause");
                todoOk=1;
            }
            fclose(pMiArchivo);//Cierro archivo.
        } else {
               printf("No se pudo abrir el archivo\n");
               exit(EXIT_FAILURE);
           }
    } else {
        printf("Error./n");
    }
    return todoOk;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    if(pArrayListEmployee != NULL)
    {
        todoOk=1;
        if(addEmployee(pArrayListEmployee))
        {
            printf("Alta exitosa.\n");
        } else {
            printf("No se pudo dar de alta.\n");
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int retorno=0;

    if(pArrayListEmployee != NULL)
    {
        todoOk=1;

        retorno = modifyEmployee(pArrayListEmployee);
        if(retorno==-1)
        {
            printf("No se han realizado cambios.\n");
        }else if (retorno==1){
            printf("Se ha guardado la modificacion.\n");
        }else{
            printf("Id inexistente.\n");//0
        }
    }
    return todoOk;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    int todoOk=0;

    if(pArrayListEmployee != NULL)
    {
        todoOk=1;
        if(removeEmployee(pArrayListEmployee))
        {
            printf("Se dio de baja al empleado.\n");
        } else {
            printf("No se dio de baja al empleado.\n");
        }
    }

    return todoOk;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk;
    if(pArrayListEmployee != NULL)
    {
        if(printAllEmployees(pArrayListEmployee))
        {
            todoOk=1;
        }
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk;
    int retorno=0;

    if(pArrayListEmployee != NULL)
    {
        todoOk=1;
        retorno= sortEmployee(pArrayListEmployee);
        if(retorno==-1)
        {
            printf("No se ha realizado ordenamiento./n");
        }else if (retorno==1){
            printf("Se ha realizado el ordenamiento./n");
        }else{
            printf("Id inexistente./n");//0
        }
    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    FILE* pFile;
	int auxId;
	char auxNombre[50];
	int auxHoras;
	int auxSueldo;
	int tam;
	Employee* auxEmployee;
    tam= ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && path != NULL)
	{
        pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 1;
			fprintf(pFile, "id,nombre,horas trabajadas,sueldo\n");
			for(int i =0; i < tam ; i++)
			{
				auxEmployee = ll_get(pArrayListEmployee, i);

				if(employee_getId(auxEmployee, &auxId) &&
				   employee_getNombre(auxEmployee, auxNombre) &&
				   employee_getHorasTrabajadas(auxEmployee, &auxHoras) &&
				   employee_getSueldo(auxEmployee, &auxSueldo))
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo data.csv\n");
            system("pause");
		}
	}
    return todoOk;
}


