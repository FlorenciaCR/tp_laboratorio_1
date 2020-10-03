#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

/** \brief pide un numero int y lo valida entre maximo y minimo
 *
 * \param mensaje pide dato
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return el numero validado
 *
 */
int getInt(char texto[],char textoError[], int minimo, int maximo);

/** \brief pide un numero float y lo valida entre maximo y minimo
 *
 * \param mensaje pide dato
 * \param mensaje error
 * \param minimo
 * \param maximo
 * \return el numero validado
 *
 */
float getFloat(char texto[],char textoError[], float minimo, float maximo);

/** \brief pide una cadena y se valida el largo
 *
 * \param cadena
 * \param mensaje para ingresar cadena
 * \param mensaje error
 * \return retorna 1: exito | -1: error
 *
 */
int getString(char dato[], char mensaje[], char mensajeError[], int len);

/** \brief recibe un char y lo valida
 *
 * \param mensaje pide el char
 * \param mensaje error
 * \return devuelve el char validado
 *
 */
char getCharSoN(char mensaje[], char mensajeError[]);

/** \brief recibe una cadena y pone en mayuscula la primera letra y de encontrar un espacio pone en mayuscula la siguiente
 *
 * \param cadena
 *
 */
void wordsFirstCharToUpper(char cadena[]);

#endif // INPUTS_H_INCLUDED
