#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int getInt(char texto[],char textoError[], int minimo, int maximo)
{
    int dato;

    printf("%s",texto);
    fflush(stdin);
    scanf("%d", &dato); //si dio 0 pido otra vez
    while(dato < minimo || dato > maximo)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%d", &dato);
    }

    return dato;
}

float getFloat(char texto[],char textoError[], float minimo, float maximo)
{

    float dato;

    printf("%s",texto);
    fflush(stdin);
    scanf("%f", &dato); //si dio 0 pido otra vez
    while(dato < minimo || dato > maximo)
    {
        printf("%s",textoError);
        fflush(stdin);
        scanf("%f", &dato);
    }

    return dato;
}

char getCharSoN(char mensaje[], char mensajeError[])
{
    char caracter;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c",&caracter);
    caracter =tolower(caracter);
    while(caracter !='s' && caracter != 'n')
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &caracter);
    }

    return caracter;
}

int getString(char dato[], char mensaje[], char mensajeError[], int len)
{
    int todoOk= -1;

    if(dato!=NULL && len >0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", dato);

         while(strlen(dato) >= len - 1)
         {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%[^\n]", dato);
         }

         wordsFirstCharToUpper(dato);
        todoOk=1;
    }

    return todoOk;
}

void wordsFirstCharToUpper(char cadena[])
{
    int len;
    int i;

    strlwr(cadena);

    len= strlen(cadena);
    cadena[0]= toupper(cadena[0]); // en el indice 0 le digo toupper xq es la 1ra letra

    for(i=0; i<len; i++)
    {
        if(isspace(cadena[i]))
        {
            cadena[i+1] = toupper(cadena[i+1]);
        }
    }
}


