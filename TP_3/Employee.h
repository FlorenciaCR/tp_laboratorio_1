#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


#endif // employee_H_INCLUDED
int mainMenu(void);
/** \brief Asigna espacio en memoria dinamica para un empleado sin datos.
 *
 * \return puntero a empleado.
 *
 */

Employee* employee_new(void);


/** \brief Crea puntero a Empleado, llama a los setters cargando los datos y asigna espacio en memoria dinamica.
 *
 * \param char* id
 * \param char* nombre
 * \param char* horasTrabajadas
 * \param char* sueldo
 * \return puntero a empleado.
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Libera espacio en memoria.
 *
 * \param Puntero empleado
 *
 *
 */

void employee_delete(Employee* employee);


/** \brief Carga el id de un empleado en el puntero que se le pase por parametro.
 *
 * \param this puntero a empleado
 * \param id a cargar
 * \return 1 exito, 0 error.
 *
 */

int employee_setId(Employee* this,int id);


/** \brief Obtiene el id de un empleado y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a empleado
 * \param id puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int employee_getId(Employee* this,int* id);


/** \brief Carga el nombre de un empleado en el puntero que se le pase.
 *
 * \param this puntero a empleado
 * \param nombre a cargar
 * \return 1 exito, 0 error.
 *
 */

int employee_setNombre(Employee* this,char* nombre);


/** \brief Obtiene el nombre de un empleado y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a empleado
 * \param nombre puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int employee_getNombre(Employee* this,char* nombre);


/** \brief Carga horas de trabjo de un empleado en el puntero que se le pase.
 *
 * \param this puntero a empleado
 * \param horas de trabajo a cargar
 * \return 1 exito, 0 error.
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene las horas de trabjo de un empleado y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a empleado
 * \param horasTrabajadas puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Carga el sueldo de un empleado en el puntero que se le pase.
 *
 * \param this puntero a empleado
 * \param sueldo a cargar
 * \return 1 exito, 0 error.
 *
 */

int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a empleado
 * \param sueldo puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Da de alta a un  empleado y lo carga a la lista linkeada.
 *
 * \param pListaEmpleados puntero a la lista linkeada
 * \param
 * \return exito 1, 0 error.
 *
 */

int addEmployee(LinkedList* pListaEmpleados);


/** \brief Muentra a un empleado.
 *
 * \param pListaEmpleados lista linkeada
 * \param indice del empleado
 *
 *
 */

void printEmployee(LinkedList* pListaEmpleados, int indice);


/** \brief Muestra la lista de empleados.
 *
 * \param pListaEmpleados lista linkeada
 * \param
 * \return exito 1 , error 0
 *
 */

int printAllEmployees(LinkedList* pListaEmpleados);


/** \brief Da de baja a un empleado de la lista.
 *
 * \param pListaEmpleados lista linkeada
 * \param
 * \return exito 1, error 0
 *
 */

int removeEmployee(LinkedList* pListaEmpleados);


/** \brief Busca a un empelado por el id que se le pasa a la variable id.
 *
 * \param pListaEmpleado lista linkeada
 * \param id , id a buscar
 * \return  -1 si no encuentra el indice, o el indice encontrado.
 *
 */

int findEmployeeById(LinkedList* pListaEmpleados,int id);


/** \brief Llama al menu de modificaciones y segun la opcion elegida se modifica ese dato del empleado.
 *
 * \param pListaEmpleado lista linkeada
 * \param
 * \return -1 no se modifico nada, 1 se modificacion exitosa, 0 error.
 *
 */

int modifyEmployee(LinkedList* pListaEmpleados);


/** \brief Muestra las opciones a modificar de un empleado.
 *
 * \return opcion elegida.
 *
 */

int menuModifyEmployee(void);


/** \brief Pide que se ingrese el nuevo nommbre y lo guarda en el indice que se le pasa por parametro
 *
 * \param pListaEmpleado lista linkeada
 * \param indice donde se encuentra el empleado
 * \return exito 1, error 0
 *
 */

int modifyName(LinkedList* pListaEmpleados,int  indice);

/** \brief Pide que se ingrese el nuevas horas de trabajo y lo guarda en el indice que se le pasa por parametro
 *
 * \param pListaEmpleado lista linkeada
 * \param indice donde se encuentra el empleado
 * \return exito 1, error 0
 *
 */


int modifyWorkedHours(LinkedList* pListaEmpleados,int  indice);


/** \brief Pide que se ingrese el nuevo salario y lo guarda en el indice que se le pasa por parametro
 *
 * \param pListaEmpleado lista linkeada
 * \param indice donde se encuentra el empleado
 * \return exito 1, error 0
 *
 */

int modifySalary(LinkedList* pListaEmpleados,int  indice);


/** \brief Muestra las opciones a ordernamiento de los empleados.
 *
 * \return opcion elegida.
 *
 */

int menuSortEmployee(void);


/** \brief Llama al menu de ordenamiento de empleados, y segun la opcion elegida se ordena a los empleados.
 *
 * \param
 * \param
 * \return 1 se ordeno con exito, 0 error, -1 si no se ordeno.
 *
 */

int sortEmployee(LinkedList* pListaEmpleados);


/** \brief Compara los id de dos empleados.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 id iguales, 1 si id nombre es mayor, -1 si el segundo id es mayor.
 *
 */
int sortById(void* empleadoA, void* empleadoB);


/** \brief Compara los nombres de dos empleados.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 nombres iguales, 1 si primer nombre es mayor, -1 si el segundo nombre es mayor.
 *
 */

int sortByName(void* empleadoA, void* empleadoB);


/** \brief Compara las horas trabajadas de dos empleados.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 horas iguales, 1 si primer horas es mayor, -1 si la segunda hora es mayor.
 *
 */
int sortByWorkedHours(void* empleadoA, void* empleadoB);


/** \brief Compara los sueldos de dos empleados.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 sueldos iguales, 1 si primer sueldos es mayor, -1 si el segundo sueldos es mayor.
 *
 */
int sortBySalary(void* empleadoA, void* empleadoB);


/** \brief Incrementa el id del empleado.
 *
 * \param
 * \param
 * \return id del empleado.
 *
 */

int getNextId(void);

