/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "alumno.h"
#include "validaciones.h"


int main(void)
{
    LinkedList* listaAlumnos;
    int opcion;
    listaAlumnos = ll_newLinkedList();
    LinkedList* listaAlumBackUp;
    LinkedList* listaFiltrada;
    LinkedList* listaSubAlumnos;
    int min=0;
    int max=0;
    int huboCarga=0;
    int hayBackUp=0;
    if(listaAlumnos != NULL)
    {
        printf("Se creo la lista\n");
    }

    do{
        opcion = mainMenu();

        switch(opcion)
        {
            case 1:
                //CARGA DATOS MODO TEXTO
                if(ll_isEmpty(listaAlumnos))
                {
                    if(controller_loadFromText(listaAlumnos)==1)
                    {
                        huboCarga=1;
                    }

                } else {
                    printf("Los datos ya han sido cargados.\n");
                }
                break;

            case 2:
           //ALTA ALUMNO
           if(huboCarga)
           {
                altaAlumno(listaAlumnos);
           } else
            {
                printf("Debe cargar los datos primero. Opcion 1.\n");
            }
                break;

            case 3:
           //MODIFICAR ALUMNO
           if(huboCarga)
           {
                modificarAlumno(listaAlumnos);
           }else
            {
                printf("Debe cargar los datos primero. Opcion 1.\n");
            }
                break;

            case 4:
           //BAJA ALUMNO
            if(huboCarga)
            {
                eliminarAlumno(listaAlumnos);

            }else
            {
                printf("Debe cargar los datos primero. Opcion 1.\n");
            }
                break;

            case 5:
           //LISTAR EMPLEADOS
           if(huboCarga)
           {
            mostrarAlumnos(listaAlumnos);

           }else
            {
                printf("Debe cargar los datos primero. Opcion 1.\n");
            }

                break;


            case 6:
                //MOVER ALUMNO
                if(huboCarga)
                {
                moverAlumno(listaAlumnos);

                }else{
                    printf("Debe cargar los datos primero. Opcion 1.\n");
                }
                break;
            case 7://ORDENAR EMPLEADOS
                if(huboCarga)
                {
                ordenarAlumnos(listaAlumnos);

                }else
            {
                printf("Debe cargar los datos primero. Opcion 1.\n");
            }
                break;

            case 8://FILTRAR ALUMNOS POR SEXO MASCULINO
                if(huboCarga)
                {
                    listaFiltrada=ll_filter(listaAlumnos,filtrarSexoM);
                    mostrarAlumnos(listaFiltrada);

                }else
                {
                    printf("Debe cargar los datos primero. Opcion 1.\n");
                }
                break;

            case 9://CREAR SUBLISTA INDICANDO MIN Y MAX
                if(huboCarga)
                {

                    mostrarAlumnos(listaAlumnos);
                    getInt(&min,"Ingrese posicion desde para crear la sublista: ", "Error. REingrese minimo: ",0,20);
                    getInt(&max,"Ingrese posicion hasta (no inclusive) para crear la sublista: ", "Error. REingrese maximo: ",0,21);

                    listaSubAlumnos= ll_subList(listaAlumnos,min - 1,max - 1);

                    if(listaSubAlumnos != NULL)
                    {
                        mostrarAlumnos(listaSubAlumnos);
                    }
                }else
                {
                    printf("Debe cargar los datos primero. Opcion 1.\n");
                }
                break;

            case 10:// GUARDAR LISTA ORIGINAL.
                if(huboCarga)
                {

                    if(controller_saveAsText("datos.csv",listaAlumnos))
                    {
                        printf("Se guardaron los datos en el archivo datos.csv\n");
                    }
                }else
                {
                    printf("Debe cargar los datos primero. Opcion 1.\n");
                }
                    break;

            case 11://CLONAR LISTA BACKUP
                if(!(ll_isEmpty(listaAlumnos)))
                {
                    listaAlumBackUp = clonarListaBackUp(listaAlumnos);
                    printf("\nBack up realizado con exito\n");
                    system("pause");
                    hayBackUp=1;
                }
                else
                {
                    printf("\nNo se puede realizar back up de una lista vacia.\n");
                }
                break;

            case 12:// VER LISTA CLONADA BACKUP
                if(hayBackUp)
                {
                    printf("Lista Clonada: \n");
                mostrarAlumnos(listaAlumBackUp);

                }else
                {
                    printf("Debe clonar la lista primero.\n");
                }
                break;

            case 13: //COMPARAR LISTA CLONADA CON LA LISTA ORIGINAL
                if( (compararLinkedListClon(listaAlumnos,listaAlumBackUp)==1) && !(ll_isEmpty(listaAlumnos)))
                {
                    printf("\nTodos los elementos de la lista original estan contenidos en la lista clonada (backup).\n");
                    system("pause");
                }else{
                    printf("\nEl Back Up no esta actualizado\n");
                }
                break;

            case 14:
            printf("Saliendo");
            break;
        }
    }while(opcion != 14);
    ll_deleteLinkedList(listaAlumnos);
    ll_deleteLinkedList(listaAlumBackUp);
    ll_deleteLinkedList(listaFiltrada);

//        startTesting(1);  // ll_newLinkedList
//        startTesting(2);  // ll_len
//        startTesting(3);  // getNode - test_getNode
//        startTesting(4);  // addNode - test_addNode
//        startTesting(5);  // ll_add
//        startTesting(6);  // ll_get
//        startTesting(7);  // ll_set
//        startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//        startTesting(14); // ll_pop
//        startTesting(15); // ll_contains
//        startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort

    return 0;
}


