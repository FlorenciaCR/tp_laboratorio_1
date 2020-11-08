#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief pide un numero int y lo valida entre maximo y minimo
 *
 * \param puntero a entero donde se va a cargar el numero validado
 * \param mensaje pide dato
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return el numero validado.
 *
 */
int getInt(int* numero ,char texto[],char textoError[], int minimo, int maximo);

/** \brief pide una cadena y se valida el largo
 *
 * \param cadena
 * \param mensaje para ingresar cadena
 * \param mensaje error
 * \return retorna 1: exito | -1: error
 *
 */
int getString(char dato[], char mensaje[], char mensajeError[], int len);


/** \brief recibe una cadena y pone en mayuscula la primera letra y de encontrar un espacio pone en mayuscula la siguiente
 *
 * \param cadena
 *
 */
void wordsFirstCharToUpper(char cadena[]);
