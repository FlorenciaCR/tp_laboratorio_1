#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; //estado

}typedef eEmployee;

/** \brief menu principal del abm de empleados
 *
 * \return devuelve la opcion elegida
 *
 */
int menu (void);

/** \brief Recorre el array de empleados para verificar si hay lugar libre
 *
 * \param array de empleados
 * \param tamaño del array
 * \return 1:  0: ocupado| vacio 1
 *
 */
int isEmpty(eEmployee listaEmpleados[], int tam);

/** \brief crea un nuevo empleado con datos que carga un usuario
 *
 * \param array de empleados
 * \param tamaño del array
 * \return el empleado cargado
 *
 */

eEmployee createEmployee();

/** \brief carga al empleado a una lista de empleados
 *
 * \param array de empleados
 * \param tamaño del array
 * \param id del empleado
 * \return 0: no hay error | 1: error
 *
 */
int addEmployee(eEmployee listaEmpleados[], int tam, int id);

/**
 * @brief Inicializa un array de empleados con la propiedad isEmpty en 1
 *
 * @param  Array de empleados a recorrer
 * @param Tamaño del array
 */
int initEmployees(eEmployee listaEmpleados[], int tam);
/**
 * @brief Imprime solo los datos de 1 empleados
 *
 * @param empleado tipo eEmployee
 */
void printEmployee(eEmployee empleado);

/**
 * @brief Imprime la lista de empleados
 *
 * @param empleados Array de empleados
 * @param tamaño de array de empleados
 */
void printEmployees(eEmployee listaEmpleados[], int tam);

/**
 * @brief Busca un indice libre en una lista de empleados
 *
 * @param empleados Array de empleados
 * @param tamaño del array de empleados
 * @return -1: no hay indice libre | indice libre
 */
int findEmptySpace(eEmployee listaEmpleados[], int tam);

/**
 * @brief Recorre un array de empleados y en caso de encontrar ID te devuelve el indice en donde esta
 *
 * @param empleado Array de empleados
 * @param Tamaño de array de empleados
 * @param Id del empleado
 * @return devuelve -1 si no lo encontró, sino devuelve el indice
 */
int findEmployeeById(eEmployee listaEmpleados[],int id,int tam);

/** \brief Recorre el array de empleados y En caso de encontrar el id de un empleado cargado permite eliminarlo
 *
 * \param lista de empleados
 * \param id del empleado
 * \param tamaño del array de empleados
 * \return 0: exito |1:cancela baja |2: no encuentro id |3: opcion no valida | -1: error
 *
 */

int removeEmployee(eEmployee listaEmpleados[], int tam);
/** \brief Ejecuta la modificacion del empleado segun la opcion elegida
 *
 * \param array de empleados
 * \param tamaño del array
 * \return 0: exito |1:error no existe id |2: no hubo modificacion
 */

int updateEmployee(eEmployee listaEmpleados[], int tam);
/** \brief muestra menu con opciones para modificar los datos del empleado
 *
 * \return devuelve la opcion elegida
 *
 */

int menuModificarDatosEmpleado (void);
/** \brief muestra menu para elegir ingresar ID o salir
 *
 * \return devuelve la opcion elegida
 *
 */

int menuElegirId (void);
/** \brief muestra menu para ordenar la lista de empleados, informar sobre los empleados, o salir
 *
 * \return devuelve la opcion elegida
 *
 */

int menuInformesEmpleados(void);

/** \brief Ejecuta el ordenamiento y los reportes  segun la opcion elegida
 *
 * \param lista de empleados
 * \param tamaño del array de empleados
 *
 */
void employeeReports(eEmployee listaEmpleados[], int tam);

/** \brief Ordena el array de empleados  por sector y luego por apellido
 *
 * \param lista de empleados
 * \param tamaño del array de empleados
 * \return 0: exito | 1: error
 *
 */
int sortEmployee(eEmployee listaEmpleados[], int tam, int orden);

/** \brief Recorre el array y Acumula los salarios de los empleados
 *
 * \param lista de empleados
 * \param tamaño del array de empleados
 * \return la suma del salario total
 *
 */
float totalSalary(eEmployee listaEmpleados[], int tam);

/** \brief Recorre el array y Saca el promedio de los salarios
 *
 * \param lista de empleados
 * \param tamaño del array de empleados
 * \return devuelve el promedio en float
 *
 */
float averageSalary(eEmployee listaEmpleados[], int tam);

/** \brief Recorre el array de salarios y busca la cantidad de empleados que superan el promedio salarial
 *
 * \param lista de empleados
 * \param tamaño del array de empleados
 * \return contador de empleados.
 *
 */
int employeesAboveAverageS(eEmployee listaEmpleados[], int tam);
#endif // ARRAYEMPLOYEES_H_INCLUDED
