#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

int getInt(int* numero ,char texto[],char textoError[], int minimo, int maximo)
{
    int todoOk=0;
    if(numero != NULL)
    {
        printf("%s",texto);
        fflush(stdin);
        scanf("%d", numero); //si dio 0 pido otra vez
        while(*numero < minimo || *numero > maximo)
        {
            printf("%s",textoError);
            fflush(stdin);
            scanf("%d", numero);
        }

        todoOk=1;

    }

    return todoOk;
}

int getString(char dato[], char mensaje[], char mensajeError[], int len)
{
    int todoOk=0;

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
