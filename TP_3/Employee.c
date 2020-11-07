#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int idEmployee=2000;//Ya hay 1000 empleados.


int mainMenu()
{
    int opcion;
    system("cls");
    printf("\t**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar datos de los empleados (Modo texto)\n");
    //printf("2- Cargar datos de los empleados (Modo binario)\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de un empleado\n");
    printf("5- Baja de empleado\n");
    printf("6- Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados (Modo texto)\n");
    //printf("9- Guardar los datos de los empleados (Modo binario)\n");
    printf("10- Salir\n\n");

    printf("Indique la opcion: ");
    scanf("%d",&opcion);


    return opcion;
}

Employee* employee_new(void) //USAR SETTERS!
{
    Employee* pNuevoEmpleado = NULL;
    pNuevoEmpleado= (Employee*) malloc(sizeof(Employee));

    if(pNuevoEmpleado != NULL)
    {
        pNuevoEmpleado->id=0;
        strcpy(pNuevoEmpleado->nombre,"sin nombre");
        pNuevoEmpleado->horasTrabajadas='0';
        pNuevoEmpleado->sueldo='0';

    }
    return pNuevoEmpleado;
}

//Entender porque usa atoi??
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleadoParam = NULL;
    nuevoEmpleadoParam = employee_new();

    if(nuevoEmpleadoParam != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
    {   //Se niega todos setter en if porque si alguno devuelve 0(falla algun pasaje)-> libero memoria con employee_delete.
        if(!(employee_setId(nuevoEmpleadoParam,atoi(idStr))
             && employee_setNombre(nuevoEmpleadoParam,nombreStr)
             && employee_setHorasTrabajadas(nuevoEmpleadoParam,atoi(horasTrabajadasStr))
             && employee_setSueldo(nuevoEmpleadoParam,atoi(sueldoStr))))
        {
            employee_delete(nuevoEmpleadoParam);

        }//Si hubo falla en el pasaje,se libera memoria y retorna NULL en empleado.
    }//Si queda aca, devuelve NULL

    return nuevoEmpleadoParam;
}

void employee_delete(Employee* empleado) //LIBERA MEMORIA. Necesario ponerlo a null???
{
    if(empleado!= NULL)
    {
       empleado= NULL;
       free(empleado);
    }
}

//SETTERS.
//Se debe validar los datos antes de cargarlo a un campo de la estructura del empleado. (Darle valor a un atributo).Sirven para escribir.
//Sirven para pisar valores como por ejempleo en una MODIFICACION.
int employee_setId(Employee* this,int id) //VALIDAR NUMERO!!
{
    int todoOk=0; //Error
    if(this != NULL && id >0)//Si la estructura existe y id es valido:
    {
        //se lo pasa a la estructura
        this->id = id; //guarda en el id de this el id que se le pasa por parametros.
        todoOk = 1; //Todo ok, se cargo el id a la estructura.
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre) //VALIDAR CADENA!!
{
    int todoOk=0;

    if(this != NULL && nombre != NULL)
    {
        //Se le pasa el nombre como parametro y se pasa a la esctrura-> nombre.
        strcpy(this->nombre, nombre);
        todoOk=1;//Todo ok, se cargo el nombre en la estructura.
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas>0)
    {
    this->horasTrabajadas=horasTrabajadas;
    //printf("HorasTr en setter: %d\n",horasTrabajadas);
    todoOk=1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo= sueldo;
//printf("Sueldo en setter: %d\n",sueldo);
        todoOk=1;
    }
    return todoOk;
}

//GETTERS.
//Sirven para obtener el valor de un atributo, para leer/mostrar.Es de salida.
int employee_getId(Employee* this, int* id)
{
    int todoOk= 0;
    if(this != NULL && id != NULL)
    {
        //ID Es el valor, no la dirrecion de memoria por eso se usa *
        *id = this->id;//Guarda en el puntero a id lo que hay en this id.
        //Es una d.m y quiero pasarle a esa variable el valor.
        todoOk=1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo= this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas= this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}

//MOSTRAR EMPLEADO/S
int printAllEmployees(LinkedList* pListaEmpleados)
{
    int todoOk=0;
    int tam;

    if(pListaEmpleados != NULL)
    {
        tam= ll_len(pListaEmpleados);//Se devuelve la cantidad de empleados en la lista.
        todoOk=1;
        if(tam > 0)
        {
            printf("---------------------------------------------------\n");
            printf("|   ID   |    NOMBRE  | HORASTRABAJADAS |   SUELDO |\n");
            printf("----------------------------------------------------\n");
            for(int i=0; i < tam ;i++)
            {
                printEmployee(pListaEmpleados,i);
            }
            system("pause");

        } else
        {
            printf("-----------------------------------------------\n");
            printf("|  ID  |  NOMBRE  | HORAS TRABAJADAS | SUELDO |\n");
            printf("-----------------------------------------------\n");
            printf("No hay empleados que listar.\n");
            system("pause");
        }
    } else {
        printf("Error null.\n");
    }
    return todoOk;
}

void printEmployee(LinkedList* pListaEmpleados, int indice)
{

    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[20];
    Employee* pEmpleado= employee_new();

    if(pListaEmpleados != NULL && indice >=0)
    {
       //Get devuelve un puntero que debo castear a eEmpleado, por eso se guarda en un tipo de dato eEmpleado.
       pEmpleado= (Employee*)ll_get(pListaEmpleados,indice);

       if(pEmpleado != NULL
          && employee_getId(pEmpleado, &id)
          && employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas)
          && employee_getSueldo(pEmpleado, &sueldo)
          && employee_getNombre(pEmpleado, nombre))
       {
           printf("%4d %15s      %2d         %8d\n",id,nombre,horasTrabajadas,sueldo);
       } else {
           printf("Error al mostrar los datos.\n");
       }
    }
}


//ALTA
int addEmployee(LinkedList* pListaEmpleados)//VALIDAR INGRESO DE DATOS completo. Usar delete o free employee?
{
    int todoOk=0;
    char auxNombre[30];
    int auxId;
    int auxHorasTrabajo;
    int auxSueldo;
    Employee* pNuevoEmpleado;

    pNuevoEmpleado = (Employee*)employee_new();

    if(pListaEmpleados != NULL && pNuevoEmpleado != NULL)
    {
        system("cls");
        printf("**********Alta empleado***********\n");
        auxId=getNextId();
        printf("Ingrese nombre:");
        scanf("%s",auxNombre);
        printf("Ingrese cantidad de horas de trabajo:");
        fflush(stdin);
        scanf("%d",&auxHorasTrabajo);
        printf("Ingrese sueldo:");
        fflush(stdin);
        scanf("%d",&auxSueldo);
        //Si Salen bien las validaciones
        //Falta lo del ID autoncremental
        if(employee_setId(pNuevoEmpleado, auxId)
           && employee_setNombre(pNuevoEmpleado, auxNombre)
           && employee_setHorasTrabajadas(pNuevoEmpleado, auxHorasTrabajo)
           && employee_setSueldo(pNuevoEmpleado, auxSueldo))
          {
                ll_add(pListaEmpleados, pNuevoEmpleado);
                todoOk=1;
                system("pause");

          }else{
                employee_delete(pNuevoEmpleado);
                printf("SALIO MAL EL ALTA.\n");
                system("pause");
            }
    }

    employee_delete(pNuevoEmpleado);
    return todoOk;
}

int findEmployeeById(LinkedList* pListaEmpleados,int id)
{
    int tam;
    int indice= -1;
    int auxId; //se guarda lo que recibe de getID
    Employee* pEmpleado;
    tam = ll_len(pListaEmpleados);

    for(int i=0; i < tam; i++)
    {
        pEmpleado = (Employee*)ll_get(pListaEmpleados,i);//i es el indice.
        if(pEmpleado != NULL)
        {

            if(employee_getId(pEmpleado,&auxId)==1 && auxId == id)// Si esta cargado empleado y el id == aux es = al id
            {
                indice = i;//Si el id es igual al id del empleado muestra el indice.
                break;
            }
        }
    }
    return indice;// -1 si no encuentra el indice, o el indice encontrado.
}
//BAJA
int removeEmployee(LinkedList* pListaEmpleados) //VALIDAR ID
{
    int todoOk=0;
    int indice;
    char confirma;
    int auxId;

    if(pListaEmpleados != NULL)
    {
        system("cls");
        printf("**Baja de empleado**\n");
        printAllEmployees(pListaEmpleados);

        printf("Ingrese Id: "); //VALIDAR!!
        scanf("%d",&auxId);

        indice= findEmployeeById(pListaEmpleados,auxId);
        if(indice!= -1)
        {
            printf("ID     NOMBRE     HORAS TRABAJADAS    SUELDO\n");
            printEmployee(pListaEmpleados,indice);
            printf("Confirma la baja?(s/n)");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                ll_remove(pListaEmpleados,indice);
                todoOk=1;
                printf("Baja realizada.\n");
            } else {
                printf("Baja cancelada.\n");
                system("pause");
            }
        } else {
            printf("Ese ID nose encuentra en la lista.\n");
        }

    }
   return todoOk;
}

//MODIFICACION
int modifyEmployee(LinkedList* pListaEmpleados)//VALIDAR datos. da 1 si modifico algo unicamente.
{
    int retorno = 0;
    int opcion;
    int auxId;
    int indice;
    int seModifico=0;
    Employee* pAuxEmpleado=NULL;

    if(pListaEmpleados != NULL)
    {
        system("cls");
        printf("*****Modificar empleado****\n");
        printAllEmployees(pListaEmpleados);

        printf("Ingrese el ID del empleado a modificar: "); //VALIDAR NUMERO
        scanf("%d",&auxId);

        indice= findEmployeeById(pListaEmpleados,auxId);//Lo encuentra.
        if(indice != -1)
        {
            pAuxEmpleado= (Employee*)ll_get(pListaEmpleados,indice);//Devuelve el dato.

            if(pAuxEmpleado != NULL)
            {
                do{
                    printf("Empleado seleccionado para modificar:\n");
                    printEmployee(pListaEmpleados,indice);
                    opcion= menuModifyEmployee();
                    switch(opcion)
                    {
                    case 1: //Modificar: NOMBRE
                        if(modifyName(pListaEmpleados,indice))
                        {
                            printf("Se ha realizado el cambio de nombre.\n");
                            printEmployee(pListaEmpleados,indice);
                            seModifico=1;
                        } else {
                            printf("Error al realizar la modificacion.\n");
                        }
                        seModifico=1;
                        break;

                    case 2://Modificar: HORAS DE TRABAJO
                        if(modifyWorkedHours(pListaEmpleados,indice))
                        {
                            printf("Se ha realizado el cambio de horas de trabajo.\n");
                            printEmployee(pListaEmpleados,indice);
                            seModifico=1;
                        } else {
                            printf("Error al realizar la modificacion.\n");
                        }

                        break;

                    case 3://Modificar: SUELDO
                        if(modifySalary(pListaEmpleados,indice))
                        {
                            printf("Se ha realizado el cambio de sueldo.\n");
                            printEmployee(pListaEmpleados,indice);
                            seModifico=1;
                        } else {
                            printf("Error al realizar la modificacion.\n");
                        }

                        break;

                    case 4:
                        printf("Saliendo del menu de notificaciones.\n");
                        if(!seModifico)
                        {
                            retorno= -1;//No se modifico nada.
                        } else{
                            retorno=1;//Se modifico
                        }
                        break;
                    }
                    system("pause");
                }while(opcion !=4);
            }

        } else {
            retorno=0;//No existe el id.
      }
    }
    return retorno;
}


int menuModifyEmployee(void)
{
    int opcion;
    system("cls");
    printf("***Menu modificar empleado***\n");
    printf("1-Cambiar nombre\n");
    printf("2-Cambiar horas trabajadas\n");
    printf("3-Cambiar sueldo\n");
    printf("4-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int modifyName(LinkedList* pListaEmpleados,int  indice)
{

    int todoOk = 0;
    char newName[20];
    Employee* pAuxEmpleado;

    pAuxEmpleado = (Employee*) ll_get(pListaEmpleados, indice);

    //Validar nombre.
    if(pAuxEmpleado != NULL) // y validacion da ok...
    {
        printf("Ingrese nuevo nombre: ");
        scanf("%s",newName);

        employee_setNombre(pAuxEmpleado,newName);
        todoOk = 1;

    }

    return todoOk;
}

int modifyWorkedHours(LinkedList* pListaEmpleados,int  indice)
{

    int todoOk = 0;
    int newHours;
    Employee* pAuxEmpleado;

    pAuxEmpleado = (Employee*) ll_get(pListaEmpleados, indice);

    //Validar dato.
    if(pAuxEmpleado != NULL) // y validacion da ok...
    {
        printf("Ingrese horas de trabajo nuevas: ");
        scanf("%d",&newHours);

        employee_setHorasTrabajadas(pAuxEmpleado,newHours);
        todoOk = 1;

    }

    return todoOk;
}

int modifySalary(LinkedList* pListaEmpleados,int  indice)
{

    int todoOk = 0;
    int newSalary;
    Employee* pAuxEmpleado;

    pAuxEmpleado = (Employee*) ll_get(pListaEmpleados, indice);

    //Validar dato.
    if(pAuxEmpleado != NULL) // y validacion da ok...
    {
        printf("Ingrese nuevo salario: ");
        scanf("%d",&newSalary);

        employee_setSueldo(pAuxEmpleado,newSalary);
        todoOk = 1;

    }

    return todoOk;
}

//ORDENAMIENTO
int menuSortEmployee(void)
{
    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");
    printf("1-Ordenar por ID\n");
    printf("2-Ordenar por nombre\n");
    printf("3-Odenar por horas trabajadas\n");
    printf("4-Ordenar por sueldo\n");

    printf("5-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int sortEmployee(LinkedList* pListaEmpleados)//VALIDAR DATO!!
{
    int retorno=0;
    int opcion;
    int orden;
    int seOrdeno=0; //flag si se ordena se pone en 1.

    if(pListaEmpleados != NULL)
    {
        opcion = menuSortEmployee();
        printf("Ingrese tipo de ordenamiento (1-Ascendente, 0-Descendente): ");
        scanf("%d",&orden);

        switch(opcion)
        {
        case 1://Ordena por ID
            ll_sort(pListaEmpleados,sortById,orden);
            printf("Se han ordenado los empleados.\n");
            seOrdeno=1;
            break;
        case 2:
            //Ordena por NOMBRE
            ll_sort(pListaEmpleados,sortByName,orden);
            seOrdeno=1;
            break;
         case 3:
             //Ordena por HORAS TRABAJADAS
             ll_sort(pListaEmpleados,sortByWorkedHours,orden);
             seOrdeno=1;
            break;
        case 4:
            //Ordena por SUELDO
            ll_sort(pListaEmpleados,sortBySalary,orden);
            seOrdeno=1;
            break;
        case 5:
            if(!seOrdeno)
            {
                retorno=-1;//No se ordeno.
            }
            printf("Saliendo./n");

            break;
        }
    }//Queda aca y devuelve 0.

    return retorno;
}

int sortById(void* empleadoA, void* empleadoB)//1? -1? 0?
{
    int resultado= 0;//Por default 0, son iguales ambos.
    Employee* auxEmpleadoA;//Son punteros a empleados por eso puedo acceder a los campos.
    Employee* auxEmpleadoB;
	int idA;
	int idB;

	if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmpleadoA= (Employee*) empleadoA;
        auxEmpleadoB= (Employee*) empleadoB;

        employee_getId(auxEmpleadoA, &idA);
        employee_getId(auxEmpleadoB, &idB);

        if(idA > idB)
        {
            resultado = 1;
        }
        else if(idA < idB)
        {
            resultado = -1;
        }

    }
	return resultado;
}

int sortByWorkedHours(void* empleadoA, void* empleadoB)//1? -1? 0?
{
    int resultado= 0;//Por default 0, son iguales ambos.
    Employee* auxEmpleadoA;//Son punteros a empleados por eso puedo acceder a los campos.
    Employee* auxEmpleadoB;
	int workedHoursA;
	int workedHoursB;

	if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmpleadoA= (Employee*) empleadoA;
        auxEmpleadoB= (Employee*) empleadoB;

        employee_getHorasTrabajadas(auxEmpleadoA, &workedHoursA);
        employee_getHorasTrabajadas(auxEmpleadoB, &workedHoursB);

        if(workedHoursA > workedHoursB)
        {
            resultado = 1;
        }
        else if(workedHoursA < workedHoursB)
        {
            resultado = -1;
        }
    }
	return resultado;
}

int sortBySalary(void* empleadoA, void* empleadoB)//1? -1? 0?
{
    int resultado= 0;//Por default 0, son iguales ambos.
    Employee* auxEmpleadoA;//Son punteros a empleados por eso puedo acceder a los campos.
    Employee* auxEmpleadoB;
	int salaryA;
	int salaryB;

	if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmpleadoA= (Employee*) empleadoA;
        auxEmpleadoB= (Employee*) empleadoB;

        employee_getSueldo(auxEmpleadoA, &salaryA);
        employee_getSueldo(auxEmpleadoB, &salaryB);

        if(salaryA > salaryB)
        {
            resultado = 1;
        }
        else if(salaryA < salaryB)
        {
            resultado = -1;
        }

    }
	return resultado;
}

int sortByName(void* empleadoA, void* empleadoB)
{
    int resultado=0;//Por default 0, son iguales ambos.
    Employee* auxEmpleadoA; //Son punteros a empleados por eso puedo acceder a los campos.
    Employee* auxEmpleadoB;
    char nombreA[30];
    char nombreB[30];

    if(empleadoA != NULL && empleadoB != NULL)
    {
        auxEmpleadoA= (Employee*) empleadoA;
        auxEmpleadoB= (Employee*) empleadoB;
        employee_getNombre(auxEmpleadoA, nombreA);
        employee_getNombre(auxEmpleadoB, nombreB);
        resultado= stricmp(nombreA,nombreB);
    }
    return resultado;
}

int getNextId()
{
    idEmployee++;
    return idEmployee;
}

