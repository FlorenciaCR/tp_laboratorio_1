#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; //estado

}typedef eEmployee;

int menu (void);
int isEmpty(eEmployee listaEmpleados[], int tam);
eEmployee createEmployee();
int addEmployee(eEmployee listaEmpleados[], int tam, int id);
int initEmployees(eEmployee listaEmpleados[], int tam);
void printEmployee(eEmployee empleado);
void printEmployees(eEmployee listaEmpleados[], int tam);
int findEmptySpace(eEmployee listaEmpleados[], int tam);
int findEmployeeById(eEmployee listaEmpleados[],int id,int tam);
int removeEmployee(eEmployee listaEmpleados[], int tam);
int updateEmployee(eEmployee listaEmpleados[], int tam);
int menuInformesEmpleados(void);
int menuModificarEmpleado (void);
void employeeReports(eEmployee listaEmpleados[], int tam);
int sortEmployee(eEmployee listaEmpleados[], int tam, int orden);
float totalSalary(eEmployee listaEmpleados[], int tam);
float averageSalary(eEmployee listaEmpleados[], int tam);
int employeesAboveAverageS(eEmployee listaEmpleados[], int tam);
#endif // ARRAYEMPLOYEES_H_INCLUDED
