#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{

    LinkedList* listaEmpleados = ll_newLinkedList();
    int opcion;
    int textLoaded=0;
    int binLoaded=0;

    do{
        opcion = mainMenu();

        switch(opcion)
        {
            case 1:
                //CARGA DATOS MODO TEXTO
                controller_loadFromText("data.csv",listaEmpleados);
                textLoaded = 1;
                break;

            case 2:
                //CARGA DATOS MODO BINARIO
                printf("cargar binario");
                binLoaded = 1;
                break;


            case 3:
           //ALTA EMPLEADO
                controller_addEmployee(listaEmpleados);

            break;

            case 4:
           //MODIFICAR EMPLEADO
                controller_editEmployee(listaEmpleados);
            break;

            case 5:
           //BAJA EMPLEADO
                controller_removeEmployee(listaEmpleados);

            break;

            case 6:
           //LISTAR EMPLEADOS
                controller_ListEmployee(listaEmpleados);
            break;

            case 7:
           //ORDENAR EMPLEADOS
                controller_sortEmployee(listaEmpleados);
            break;

            case 8:
                //GUARDA DATOS MODO TEXTO
                if(textLoaded || binLoaded){
                    controller_saveAsText("data.csv", listaEmpleados);
                }
                break;

            case 9:
                //GUARDA DATOS MODO BINARIO
                if(textLoaded || binLoaded){
                    printf("guardar binario");
                }
                break;

            case 10:
            printf("Saliendo");
            break;
        }
    }while(opcion != 10);
    return 0;
}
