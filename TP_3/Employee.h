#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


#endif // employee_H_INCLUDED
int mainMenu(void);
Employee* employee_new(void);
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int addEmployee(LinkedList* pListaEmpleados);

void printEmployee(LinkedList* pListaEmpleados, int indice);
int printAllEmployees(LinkedList* pListaEmpleados);

int removeEmployee(LinkedList* pListaEmpleados);
int findEmployeeById(LinkedList* pListaEmpleados,int id);
int modifyEmployee(LinkedList* pListaEmpleados);
int menuModifyEmployee(void);
int modifyName(LinkedList* pListaEmpleados,int  indice);
int modifyWorkedHours(LinkedList* pListaEmpleados,int  indice);
int modifySalary(LinkedList* pListaEmpleados,int  indice);
int menuSortEmployee(void);
int sortEmployee(LinkedList* pListaEmpleados);
int sortById(void* empleadoA, void* empleadoB);
int sortByName(void* empleadoA, void* empleadoB);
int sortByWorkedHours(void* empleadoA, void* empleadoB);
int sortBySalary(void* empleadoA, void* empleadoB);
int getNextId(void);

