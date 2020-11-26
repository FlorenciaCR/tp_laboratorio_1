#include "../inc/LinkedList.h"
#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char sexo[20];
    int edad;
}eAlumno;


#endif // ALUMNO_H_INCLUDED

/** \brief Muestra menu de opciones
 *
 * \param
 * \param
 * \return opcion elegida
 *
 */

int mainMenu();
/** \brief Muestra la lista de alumnos.
 *
 * \param pListaEmpleados lista linkeada
 * \param
 * \return exito 1 , error 0
 *
 */
int mostrarAlumnos(LinkedList* lista);
/** \brief Muentra a un alumno.
 *
 * \param  lista linkeada
 * \param indice del alumno
 *
 *
 */
void mostrarAlumno(LinkedList* lista, int indice);

/** \brief Asigna espacio en memoria dinamica para un alumno sin datos.
 *
 * \return puntero a alumno.
 *
 */
eAlumno* alumno_new();
/** \brief llama a alumno_newParametros
 *
 * \param id a asignar de tipo cadena
 * \param nombre a asignar
 * \param sexo a asignar de tipo cadena
 * \param edad a asignar de tipo cadena
 *
 * \return llama a alumno_newPArametros convirtiendo los datos de cadena a entero
 *
 */
eAlumno* alumno_newParamS(char* idStr, char* nombreStr, char* sexoStr, char* edadStr);
/** \brief asigna un espacio en memoria dinamica para un alumno asignandole los datos
 *
 * \param id a asignar
 * \param nombre a asignar
 * \param sexo a asignar
 * \param edad a asignar
 * \return puntero a alumno con los datos setteados
 *
 */
eAlumno* alumno_newParametros(int id,char* nombre,char* sexo,int edad);
/** \brief Libera espacio en memoria.
 *
 * \param Puntero alumno
 *
 *
 */
int alumno_delete(eAlumno* alumno);
/** \brief Obtiene el id de un alumno y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a alumno
 * \param id puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */
int alumno_getId(eAlumno* this,int* id);

/** \brief asigna el id a un alumno
 *
 * \param un alumno
 * \param id a asignar
 * \return retorna 0 si se pudo asignar el id sino 1
 *
 */
int alumno_setId(eAlumno* this,int id);

/** \brief obtiene el nombre de un alumno
 *
 * \param un alumno
 * \param variable donde guardar el nombre obtenido
 * \return retorna 0 exito, 1 error.
 *
 */
int alumno_getNombre(eAlumno* this,char* nombre);

/** \brief asigna el nombre de un alumno
 *
 * \param un alumno
 * \param nombre a asignar
 * \return 0 exito, 1 error.
 *
 */
int alumno_setNombre(eAlumno* this,char* nombre);

/** \brief Obtiene las edad de un alumno y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a alumno
 * \param edad puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int alumno_getEdad(eAlumno* this,int* edad);
/** \brief Carga edad de un alumno en el puntero que se le pase.
 *
 * \param this puntero a alumno
 * \param edad a cargar
 * \return 1 exito, 0 error.
 *
 */
int alumno_setEdad(eAlumno* this,int edad);

/** \brief Obtiene el sexo de un alumno y lo guarda en el puntero que se le pase por parametro.
 *
 * \param this puntero a alumno
 * \param sexo puntero donde se va a guardar el valor
 * \return 1 exito, 0 error.
 *
 */

int alumno_getSexo(eAlumno* this,char* sexo);

/** \brief Carga el sexo de un alumno en el puntero que se le pase.
 *
 * \param this puntero a alumno
 * \param sexo a cargar
 * \return 1 exito, 0 error.
 *
 */
int alumno_setSexo(eAlumno* this,char* sexo);
/** \brief Incrementa el id del alumno.
 *
 * \param
 * \param
 * \return id del alumno.
 *
 */
int getNextId();
/** \brief Da de alta a un  alumno y lo carga a la lista linkeada.
 *
 * \param lista puntero a la lista linkeada
 * \param
 * \return exito 1, 0 error.
 *
 */
int altaAlumno(LinkedList* lista);


/** \brief Busca a un empelado por el id que se le pasa a la variable id.
 *
 * \param lista, lista linkeada
 * \param id , id a buscar
 * \return  -1 si no encuentra el indice, o el indice encontrado.
 *
 */
int findAlumnoById(LinkedList* lista,int id);

/** \brief Da de baja a un alumno de la lista.
 *
 * \param lista lista linkeada
 * \param
 * \return exito 1, error 0
 *
 */

int eliminarAlumno(LinkedList* lista);

/** \brief Muestra las opciones a modificar de un alumno.
 *
 * \return opcion elegida.
 *
 */
int menuModAlumno(void);

/** \brief Llama al menu de modificaciones y segun la opcion elegida se modifica ese dato del alumno.
 *
 * \param lista, lista linkeada
 * \param
 * \return exito 1, error 0.
 *
 */
int modificarAlumno(LinkedList* lista);

/** \brief Pide que se ingrese el nuevas edad y lo guarda en el indice que se le pasa por parametro
 *
 * \param lista, lista linkeada
 * \param indice donde se encuentra el alumno
 * \return exito 1, error 0
 *
 */
int modificarEdad(LinkedList* lista,int  indice);

/** \brief Pide que se ingrese el nuevo nommbre y lo guarda en el indice que se le pasa por parametro
 *
 * \param lista, lista linkeada
 * \param indice donde se encuentra el alumno
 * \return exito 1, error 0
 *
 */

int modificarNombre(LinkedList* lista,int  indice);

/** \brief Pide que se ingrese el nuevo nommbre y lo guarda en el indice que se le pasa por parametro
 *
 * \param lista, lista linkeada
 * \param indice donde se encuentra el alumno
 * \return exito 1, error 0
 *
 */
int modificarSexo(LinkedList* lista,int  indice);

/** \brief Muestra las opciones a ordernamiento de los alumnos.
 *
 * \return opcion elegida.
 *
 */

int menuOrdenar(void);

/** \brief Llama al menu de ordenamiento de alumnos, y segun la opcion elegida se ordena a los alumnos.
 *
 * \param
 * \param
 * \return 1 exito, 0 error
 *
 */
int ordenarAlumnos(LinkedList* lista);

/** \brief Compara los id de dos alumnos.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 id iguales, 1 si id nombre es mayor, -1 si el segundo id es mayor.
 *
 */
int ordenarId(void* alumnoA, void* alumnoB);

/** \brief Compara los nombres de dos alumnos.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 nombres iguales, 1 si primer nombre es mayor, -1 si el segundo nombre es mayor.
 *
 */
int ordenarNombre(void* alumnoA, void* alumnoB);

/** \brief Compara los sexos de dos alumnos.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 sexos iguales, 1 si primer sexo es mayor, -1 si el segundo sexo es mayor.
 *
 */

int ordenarSexo(void* alumnoA, void* alumnoB);

/** \brief Compara las edades de dos alumnos.
 *
 * \param puntero a void
 * \param puntero a void
 * \return 0 edad iguales, 1 si edad edad es mayor, -1 si el segundo edad es mayor.
 *
 */
int ordenarEdad(void* alumnoA, void* alumnoB);

/** \brief Reubica a un alumno de la lista, a otra posicion deseada por el usuario
 *
 * \param lista
 *
 */
void moverAlumno(LinkedList* lista);

/** \brief Carga los datos de los alumnos desde el archivo datos.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return 1 exito, 0 error
 *
 */
int controller_loadFromText(LinkedList* lista);

/** \brief Guarda los datos de los alumnos en el archivo datos.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return 0 error, 1 exito
 *
 */
int controller_saveAsText(char* path , LinkedList* lista);

/** \brief crea un un clon de la lista
 *
 * \param lista a realizarle el back up (clon)
 * \return devuelve una nueva lista, que contiene los mismos elementos que la pasada por parametro
 *
 */
LinkedList* clonarListaBackUp(LinkedList* this);

/** \brief Filtra hombres de una lista
 *
 * \param a puntero a filtrar
 * \return 1 exito 0 error
 *
 */
int filtrarSexoM(void* alumno);

/** \brief compara ambas listas para saber si son iguales o no
 *
 * \param lista 1
 * \param lista 2
 * \return devuelve 1: iguales, 0 no son iguales
 *
 */
int compararLinkedListClon(LinkedList* this, LinkedList* this2);
