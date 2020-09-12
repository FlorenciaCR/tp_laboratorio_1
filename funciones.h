
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/** \brief Pide un numero.
 *
 * \param mensaje para pedir el numero.
 * \return el numero ingresado.
 *
 */
int tomarNumero(char mensaje[]);

/** \brief Suma dos enteros y devuelve el resultado
 *
 * \param  primer operando
 * \param  segundo operando
 * \return el resultado de la suma
 *
 */
int funcionSumar(int a,int b);

/** \brief Resta dos enteros y devuelve el resultado
 *
 * \param  primer operando
 * \param  segundo operando
 * \return el resultado de la resta
 *
 */
int funcionRestar(int a,int b);
/** \brief Divide dos enteros y devuelve el resultado
 *
 * \param  primer operando
 * \param  segundo operando
 * \return el resultado de la division
 *
 */
float funcionDividir(int a, int b);
/** \brief Multiplica dos enteros y devuelve el resultado
 *
 * \param  primer operando
 * \param  segundo operando
 * \return el resultado de la multiplicacion
 *
 */
int funcionMultiplicar(int a, int b);

/** \brief Realiza el factorial de un numero entero y devuelve el resultado
 *
 * \param  numero a calcular
 * \return el resultado del factorial
 *
 */
long long int  funcionFactorial (int n);

/** \brief Muestra un menu de opciones que cambia segun el dato ingresado.
 *
 * \param Primer numero ingresado
 * \param Segundo numero ingresado.
 * \param Bandera que indica que el primer numero fue ingresado.
 * \param Bandera que indica que el segundo numero fue ingresado.
 * \param Bandera que indica que se ingreso a la opcion 3.
 * \return Menu con los 2 numeros cargados
 *
 */
void mostrarMenu(int a, int b, int banderaA,int banderaB);
/** \brief Muestra los resultados de todas las operaciones.
 * \param Primer numero
 * \param Segundo nummero
 * \param Resultado de la suma
 * \param Resultado de la resta
 * \param Rsultado de la division
 * \param Rsultado de la multiplicacion
 * \param Resultado del factorial del primer numero.
 * \param Resultado del factorial del segundo numero.
 */
void mostrarResultados(int a, int b,int opSuma, int opResta,float opDiv,int opMultip, long long int factorialA, long long int factorialB);


#endif // FUNCIONES_H_INCLUDED
