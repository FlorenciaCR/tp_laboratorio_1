#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

int getInt(char texto[],char textoError[], int minimo, int maximo);
float getFloat(char texto[],char textoError[], float minimo, float maximo);
int getString(char dato[], char mensaje[], char mensajeError[], int len);
char getCharSoN(char mensaje[], char mensajeError[]);
void wordsFirstCharToUpper(char cadena[]);

#endif // INPUTS_H_INCLUDED
