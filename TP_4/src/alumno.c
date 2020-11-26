#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../inc/LinkedList.h"
#include "alumno.h"
#include "validaciones.h"

    int mainMenu()
{
    int opcion;
    system("cls");
    printf("\t**** MENU DE OPCIONES ****\n\n");
    printf(" 1- Cargar datos de los alumnos (Modo texto)\n");
    printf(" 2- Alta de alumno\n");
    printf(" 3- Modificar datos de un alumno\n");
    printf(" 4- Baja de alumno\n");
    printf(" 5- Listar alumnos\n");
    printf(" 6- Mover alumno\n");
    printf(" 7- Ordenar alumnos\n");
    printf(" 8-Filtrar alumnos por sexo masculino\n");
	printf(" 9-Crear sublista\n");
    printf(" 10- Guardar los datos de los alumnos (Modo texto)\n");
    printf("11- Clonar lista.\n");
    printf("12- Mostrar lista clonada\n");
    printf("13- Comparar lista clonada con la original\n");
    printf("14- Salir\n\n");

    getInt(&opcion,"Ingrese una opcion: ", "Error.Reingrese opcion: ",1,14);

    return opcion;
}

int idAlumno=20;//Ya hay 20.

int mostrarAlumnos(LinkedList* lista)
{
    int todoOk = 0;
    int tam;

    if(lista != NULL)
    {
        tam= ll_len(lista);//Se devuelve la cantidad de empleados en la lista.
        todoOk=1;
        if(tam > 0)
        {
            printf("--------------------------------------------\n");
            printf("|   ID   |    NOMBRE  | SEXO |   EDAD  |\n");
            printf("--------------------------------------------\n");
            for(int i=0; i < tam ;i++)
            {
                mostrarAlumno(lista,i);
            }
            system("pause");

        } else
        {
            printf("----------------------------------------\n");
            printf("|   ID   |    NOMBRE  | SEXO |   EDAD  |\n");
            printf("----------------------------------------\n");
            printf("No hay alumnos que listar.\n");
            system("pause");
        }
    }
    return todoOk;
}

void mostrarAlumno(LinkedList* lista, int indice)
{
    int id;
    char nombre[20];
    char sexo[20];
    int edad;
    eAlumno* unAlumno = NULL;

    if(lista != NULL && indice >=0)
    {
        unAlumno = (eAlumno*)ll_get(lista, indice);
        if(unAlumno != NULL && alumno_getId(unAlumno, &id) && alumno_getNombre(unAlumno,nombre)&& alumno_getSexo(unAlumno, sexo)&& alumno_getEdad(unAlumno, &edad))
        {
          printf("%3d  %20s     %20s    %2d\n",id,nombre,sexo,edad);

        } else {
            printf("Error al mostrar los datos.\n");
        }
    }

}

eAlumno* alumno_new()
{
    eAlumno* newAlumno = (eAlumno*) malloc(sizeof(eAlumno));
    return newAlumno;
}

eAlumno* alumno_newParamS(char* idStr, char* nombreStr, char* sexoStr, char* edadStr)
{
    return alumno_newParametros(atoi(idStr),nombreStr,sexoStr,atoi(edadStr));
}

eAlumno* alumno_newParametros(int id,char* nombre,char* sexo,int edad)
{
    eAlumno* newAlumno = alumno_new();

    if(newAlumno != NULL)
    {
        alumno_setId(newAlumno,id);
        alumno_setNombre(newAlumno,nombre);
        alumno_setSexo(newAlumno,sexo);
        alumno_setEdad(newAlumno,edad);
    }
    else
    {
       alumno_delete(newAlumno);
    }
    return newAlumno;
}

int alumno_delete(eAlumno* alumno)
{
	int todoOk=0;//error
	if(alumno!=NULL)
	{
		free(alumno);
		todoOk=1;//exito
	}

	return todoOk;
}


int alumno_setId(eAlumno* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id>=0)
    {
        this->id=id;
        todoOk=1;
    }

    return todoOk;

}

int alumno_getId(eAlumno* this,int* id)
{
    int todoOk=0;

    if(this !=NULL && id !=NULL )
    {
        //ID Es el valor, no la dirrecion de memoria por eso se usa *
        *id=this->id; //Guarda en el puntero a id lo que hay en this id.
        todoOk=1;
    }


    return todoOk;
}

int alumno_setNombre(eAlumno* this,char* nombre)
{
    int todoOk= 0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        todoOk=1;
    }

    return todoOk;

}

int alumno_getNombre(eAlumno* this,char* nombre)
{
    int todoOk=0;

    if(this!=NULL && nombre !=NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk=1;
    }

    return todoOk;
}

int alumno_setEdad(eAlumno* this,int edad)
{
    int todoOk=0;
    if(this!=NULL && edad>0)
    {
        this->edad= edad;
        todoOk=1;
    }
    return todoOk;
}

int alumno_getEdad(eAlumno* this,int* edad)
{
    int todoOk=0;
    if(this != NULL && edad != NULL)
    {
        *edad= this->edad;
        todoOk=1;
    }
    return todoOk;
}

int alumno_setSexo(eAlumno* this,char* sexo)
{
    int todoOk=0;
    if(this!=NULL && sexo != NULL)
    {
        strcpy(this->sexo,sexo);
        todoOk=1;
    }
    return todoOk;
}


int alumno_getSexo(eAlumno* this,char* sexo)
{
    int todoOk=0;
    if(this != NULL && sexo != NULL)
    {
        strcpy(sexo,this->sexo);
        todoOk=1;
    }
    return todoOk;
}

int altaAlumno(LinkedList* lista)//ALTA
{
    int todoOk=0;
    int auxId;
    char auxNombre[30];
    char auxSexo[30];
    int auxEdad;

    eAlumno* pNuevoAlumno;

    pNuevoAlumno = (eAlumno*)alumno_new();

    if(lista != NULL && pNuevoAlumno != NULL)
    {
        system("cls");
        printf("**********Alta alumno***********\n");

        if(getString(auxNombre,"Ingrese nombre: ","Error.Reingrese nombre: ",30)
           &&getString(auxSexo, "Ingrese sexo masculino o femenino: ", "Error. Reingrese sexo masculino o femenino: ",20)
           && getInt(&auxEdad,"Ingrese edad: ", "Error. Reingrese edad: ",3,100)

            )
        {
            auxId=getNextId();

            if(alumno_setId(pNuevoAlumno, auxId)==1
               && alumno_setNombre(pNuevoAlumno, auxNombre)==1
               && alumno_setEdad(pNuevoAlumno, auxEdad)==1
               && alumno_setSexo(pNuevoAlumno, auxSexo)==1)
              {
                    ll_add(lista, pNuevoAlumno);
                    todoOk=1;
                    system("pause");

              }else{
                    alumno_delete(pNuevoAlumno);
                    printf("Error en alta alumno.\n");
                    system("pause");
                }
        }


    }

    return todoOk;
}
int getNextId()
{
    idAlumno++;
    return idAlumno;
}

int findAlumnoById(LinkedList* lista,int id)
{
    int tam;
    int indice= -1;
    int auxId; //se guarda lo que recibe de getID
    eAlumno* pAlumno;
    tam = ll_len(lista);

    for(int i=0; i < tam; i++)
    {
        pAlumno = (eAlumno*)ll_get(lista,i);//Retorna puntero al elemento eAlumno, i es el indice especificado.
        if(pAlumno != NULL)
        {

            if(alumno_getId(pAlumno,&auxId)==1 && auxId == id)//Obtengo el id del alumno y se lo compara con el id que se le pasa por parametro.
            {
                indice = i;//Si el id es igual al id del alumno muestra el indice.
                break;
            }
        }
    }
    return indice;// -1 si no encuentra el indice, o el indice encontrado.
}

int eliminarAlumno(LinkedList* lista)//BAJA
{
    int todoOk=0;
    int indice;
    char confirma;
    int auxId;

    if(lista != NULL)
    {
        system("cls");
        printf("**Baja de alumno**\n");
        mostrarAlumnos(lista);

        if(getInt(&auxId,"Ingrese ID: ","Error. Reingrese ID: ",1,100000))
        {
            indice= findAlumnoById(lista,auxId);
            if(indice!= -1)
            {
                printf("ID     NOMBRE     SEXO    EDAD\n");
                mostrarAlumno(lista,indice);
                getChar(&confirma,"Confirma la baja? (s/n): ", "Error. Reingrese: (s/n): ");
                if(confirma == 'S')
                {
                    ll_remove(lista,indice);
                    todoOk=1;
                    printf("Baja realizada.\n");
                } else {
                    printf("Baja cancelada.\n");
                    system("pause");
                }
            } else {
                printf("Ese ID nose encuentra en la lista.\n");
            }

        }


    }
   return todoOk;
}
int menuModAlumno(void)
{
    int opcion;
    system("cls");
    printf("***Menu modificaciones***\n");
    printf("1-Cambiar nombre\n");
    printf("2-Cambiar sexo\n");
    printf("3-Cambiar edad\n");
    printf("4-Salir\n");
    getInt(&opcion,"Ingrese una opcion: ", "Error.Reingrese opcion: ",1,5);

    return opcion;
}

int modificarAlumno(LinkedList* lista) //MODIFICAR
{
    int todoOk = 0;
    int opcion;
    int auxId;
    int indice;
    eAlumno* pAlumno=NULL;

    if(lista != NULL)
    {
        system("cls");
        printf("*****Modificar empleado****\n");
        mostrarAlumnos(lista);


        if(getInt(&auxId,"Ingrese ID: ","Error. Reingrese ID: ",1,100000))
        {
            indice= findAlumnoById(lista,auxId);//Lo encuentra.
            if(indice != -1)
            {   todoOk=1;
                pAlumno= (eAlumno*)ll_get(lista,indice);//Devuelve el dato.

                if(pAlumno != NULL)
                {
                    do{
                        printf("Alumno seleccionado para modificar:\n");
                        printf("ID     NOMBRE     SEXO    EDAD\n");
                        mostrarAlumno(lista,indice);
                        opcion= menuModAlumno();
                        switch(opcion)
                        {
                        case 1: //Modificar: NOMBRE
                            if(modificarNombre(lista,indice))
                            {
                                printf("Se ha realizado el cambio de nombre.\n");
                                mostrarAlumno(lista,indice);

                            } else {
                                printf("Error al realizar la modificacion.\n");
                            }

                            break;

                        case 2://Modificar SEXO
                            if(modificarSexo(lista,indice))
                            {
                                printf("Se ha realizado el cambio de sexo.\n");
                                mostrarAlumno(lista,indice);

                            } else {
                                printf("Error al realizar la modificacion.\n");
                            }

                            break;

                        case 3://Modificar: EDAD
                            if(modificarEdad(lista,indice))
                            {
                                printf("Se ha realizado el cambio de edad.\n");
                                mostrarAlumno(lista,indice);

                            } else {
                                printf("Error al realizar la modificacion.\n");
                            }

                            break;

                        case 4:
                            printf("Saliendo del menu de notificaciones.\n");
                            break;
                        }
                        system("pause");
                    }while(opcion !=4);
                }

            } else {
                todoOk=0;//No existe el id.

            }
      }
    }
    return todoOk;
}

int modificarEdad(LinkedList* lista,int  indice)
{

    int todoOk = 0;
    int nuevaEdad;
    eAlumno* pAlumno;

    pAlumno = (eAlumno*) ll_get(lista, indice);


    if(pAlumno != NULL)
    {
        if(getInt(&nuevaEdad,"Ingrese nueva edad: ","Error. REingrese edad: ",1,10000000))
        {
            alumno_setEdad(pAlumno,nuevaEdad);
            todoOk = 1;
        }

    }

    return todoOk;
}

int modificarNombre(LinkedList* lista,int  indice)
{

    int todoOk = 0;
    char nuevoNombre[20];
    eAlumno* pAlumno;

    pAlumno = (eAlumno*) ll_get(lista, indice);

    if(pAlumno != NULL) // y validacion da ok...
    {
        if(getString(nuevoNombre,"Ingrese nuevo nombre: ", "Error.riengrese nombre: ",30))
        {
            alumno_setNombre(pAlumno,nuevoNombre);
            todoOk = 1;

        }
    }

    return todoOk;
}

int modificarSexo(LinkedList* lista,int  indice)
{

    int todoOk = 0;
    char nuevoSexo[20];
    eAlumno* pAlumno;

    pAlumno = (eAlumno*) ll_get(lista, indice);


    if(pAlumno != NULL)
    {
        if(getString(nuevoSexo,"Ingrese nuevo sexo (feminimo/masculino): ","Error. REingrese sexo (femenino/masculino): ",20))
        {
            alumno_setSexo(pAlumno,nuevoSexo);
            todoOk = 1;
        }

    }

    return todoOk;
}

int menuOrdenar(void)
{
    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");
    printf("1-Ordenar por ID\n");
    printf("2-Ordenar por nombre\n");
    printf("3-Odenar por sexo\n");
    printf("4-Ordenar por edad\n");
    printf("5-Salir\n");

    getInt(&opcion,"Ingrese una opcion: ", "Error.Reingrese opcion: ",1,10);

    return opcion;
}

int ordenarAlumnos(LinkedList* lista) //ORDENAR
{
    int retorno=0;
    int opcion;
    int orden;


    if(lista != NULL)
    {
        opcion = menuOrdenar();
        getInt(&orden,"Ingrese tipo de ordenamiento (1-Ascendente, 0-Descendente): ", "Error. Ingrese 1- Ascendente, 0- Descendente: ",0,1);

        switch(opcion)
        {
        case 1://Ordena por ID
            ll_sort(lista,ordenarId,orden);
            printf("Se han ordenado los alumnos.\n");

            break;
        case 2:
            //Ordena por NOMBRE
            ll_sort(lista,ordenarNombre,orden);
            printf("Se han ordenado los alumnos.\n");

            break;
         case 3:
             //Ordena por SEXO
             ll_sort(lista,ordenarSexo,orden);
             printf("Se han ordenado los alumnos.\n");

            break;
        case 4:
            //Ordena por EDAD
            ll_sort(lista,ordenarEdad,orden);
            printf("Se han ordenado los alumnos.\n");

            break;
        case 5:
            printf("Saliendo./n");

            break;
        }
    }//Queda aca y devuelve 0.

    return retorno;
}

int ordenarId(void* alumnoA, void* alumnoB)
{
    int resultado= 0;//Por default 0, son iguales ambos.
    eAlumno* pAlumnoA;//Son punteros a alumnos por eso puedo acceder a los campos.
    eAlumno* pAlumnoB;
	int idA;
	int idB;

	if(alumnoA != NULL && alumnoB != NULL)
    {
        pAlumnoA= (eAlumno*) alumnoA;
        pAlumnoB= (eAlumno*) alumnoB;

        alumno_getId(pAlumnoA, &idA);
        alumno_getId(pAlumnoB, &idB);

        if(idA > idB)
        {
            resultado = 1;
        }
        else if(idA < idB)
        {
            resultado = -1;
        }

    }
	return resultado;
}

int ordenarNombre(void* alumnoA, void* alumnoB)
{
    int resultado=0;//Por default 0, son iguales ambos.
    eAlumno* pAlumnoA; //Son punteros a alumnos por eso puedo acceder a los campos.
    eAlumno* pAlumnoB;
    char nombreA[30];
    char nombreB[30];

    if(alumnoA != NULL && alumnoB != NULL)
    {
        pAlumnoA= (eAlumno*) alumnoA;
        pAlumnoB= (eAlumno*) alumnoB;
        alumno_getNombre(pAlumnoA, nombreA);
        alumno_getNombre(pAlumnoB, nombreB);
        resultado= strcmp(nombreA,nombreB);
    }
    return resultado;
}

int ordenarSexo(void* alumnoA, void* alumnoB)
{
    int resultado= 0;//Por default 0, son iguales ambos.
    eAlumno* pAlumnoA;//Son punteros a alumnos por eso puedo acceder a los campos.
    eAlumno* pAlumnoB;
	char sexoA[30];
	char sexoB[30];

	if(alumnoA != NULL && alumnoB != NULL)
    {
        pAlumnoA= (eAlumno*) alumnoA;
        pAlumnoB= (eAlumno*) alumnoB;

        alumno_getSexo(pAlumnoA, sexoA);
        alumno_getSexo(pAlumnoB, sexoB);
        resultado= strcmp(sexoA,sexoB);


    }
	return resultado;
}

int ordenarEdad(void* alumnoA, void* alumnoB)
{
    int resultado= 0;//Por default 0, son iguales ambos.
    eAlumno* pAlumnoA;//Son punteros a alumnos por eso puedo acceder a los campos.
    eAlumno* pAlumnoB;
	int edadA;
	int edadB;

	if(alumnoA != NULL && alumnoB != NULL)
    {
        pAlumnoA= (eAlumno*) alumnoA;
        pAlumnoB= (eAlumno*) alumnoB;

        alumno_getEdad(pAlumnoA, &edadA);
        alumno_getEdad(pAlumnoB, &edadB);

        if(edadA > edadB)
        {
            resultado = 1;
        }
        else if(edadA < edadB)
        {
            resultado = -1;
        }

    }
	return resultado;
}


void moverAlumno(LinkedList* lista)
{
    int id;
    int indice;
    int nuevoIndice;
    eAlumno* pAlumno;
    int tam;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        mostrarAlumnos(lista);
        printf("\nIngrese id del alumno a mover: ");
        scanf("%d",&id);


        indice = findAlumnoById(lista,id);
        if(indice != -1)
        {
            pAlumno = ll_pop(lista,indice);
            if(getInt(&nuevoIndice,"\nIngrese el nuevo indice para el alumno: ","Error. Reingrese el nuevo indice\n",0,tam)==1)
            {
                nuevoIndice = nuevoIndice - 1;

                if(pAlumno!=NULL)
                {
                    if(ll_push(lista,nuevoIndice,pAlumno)==0)
                    {
                        printf("El alumno se ha movido exitosamente.\n");
                        system("pause");
                    }
                }
            }

        }
        else
        {
            printf("\nId inexistente.\n");
        }
    }

}


int parser_AlumnoFromText(FILE* pFile , LinkedList* lista)
{
    int todoOk=0;
    char id[150];
    char nombre[150];
    char sexo[20];
    char edad[150];
    int cuantos=0;

    eAlumno* pAlumno;

    if(pFile != NULL && lista !=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,sexo,edad);//Lectura fantasma
        while(!feof(pFile))
        {
            cuantos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre, sexo, edad);
            if (cuantos == 4)
            {
                pAlumno = alumno_newParamS(id,nombre, sexo, edad);

                if (pAlumno != NULL)//Si pudo cargar.
                {
                    ll_add(lista, pAlumno);
                    todoOk = 1;
                }
            } else {
                    break;//Sale del while.
             }
        }
    } else {
        printf("Archivo inexistente.\n");
        exit(EXIT_FAILURE);
    }
    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* lista)
{
    int todoOk=0;
    FILE* pFile;
	int auxId;
	char auxNombre[50];
	char auxSexo[20];
	int auxEdad;
	int tam;
	eAlumno* auxAlumno;
    tam= ll_len(lista);

	if(lista != NULL && path != NULL)
	{
        pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 1;
			fprintf(pFile, "id,nombre,horas,sexo,edad\n");
			for(int i =0; i < tam ; i++)
			{
				auxAlumno = ll_get(lista, i);

				if(alumno_getId(auxAlumno, &auxId) &&
				   alumno_getNombre(auxAlumno, auxNombre) &&
				   alumno_getSexo(auxAlumno, auxSexo) &&
				   alumno_getEdad(auxAlumno, &auxEdad))
				{
					fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxNombre,auxSexo, auxEdad);
				}
			}
			fclose(pFile);
			printf("Se guardaron los datos en el archivo datos.csv\n");
            system("pause");
		}
	}
    return todoOk;
}

int controller_loadFromText(LinkedList* lista)
{
    int todoOk = 0;
    char path[100];

    printf("Ingrese nombre del archivo a cargar: ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");

    FILE* file = fopen(path,"r");

    if(file != NULL)
    {
        if(parser_AlumnoFromText(file,lista))
        {
            printf("Se cargaron los datos\n");
            system("pause");
            todoOk = 1;
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return todoOk;
}
LinkedList* clonarListaBackUp(LinkedList* this)
{
    LinkedList* newList;

    if(this != NULL)
    {
        newList = ll_clone(this);
    }

    return newList;
}

int compararLinkedListClon(LinkedList* this, LinkedList* this2)
{
    int todoOk = 0;

    if(this != NULL && this2 != NULL)
    {
        if(ll_containsAll(this2,this))
        {
            todoOk = 1;
        }

    }
    return todoOk;
}

int filtrarSexoM(void* alumno)
{
	int todoOk = 0;

	eAlumno* auxAlumno;
	if(alumno!=NULL){

		auxAlumno = (eAlumno*) alumno;
		if(strcmp(auxAlumno->sexo,"Masculino")==0){
			todoOk = 1;
		}
	}

	return todoOk;
}
