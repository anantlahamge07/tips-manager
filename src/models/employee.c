#include "include/models/employee.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

Employee* crete_employee(int64_t id, const char* name, unsigned status) {
    // allocating memory for Employee
    Employee *employee = malloc(sizeof(Employee));
    if (employee == NULL) {
        printf("Malloc failed");
    }
    // setting the id and active status of the employee
    employee->id = id;
    employee->status = status;
    employee->name = malloc(strlen(name) + 1);
    if (employee->name == NULL) {
        free(employee);
        printf("Malloc failed");
    }
    // setting the name of the employee
    strcpy(employee->name, name);
    return employee;

}

void set_name(Employee *employee, const char* name) {
    // validating the arguments
    if (employee == NULL) {
        printf("The given employee is invalid!");
        return;
    }
    if (name == NULL) {
        printf("The given name is invalid!");
        return;
    }
    // just copying the new name to the given employee's name
    strcpy(employee->name, name);
}
void set_status(Employee *employee, unsigned status) {
    // validating the arguments
    if (employee == NULL) {
        printf("The given employee is invalid!");
        return;
    }
    if (status != 0) {
        if (status != 1) {
            printf("The given status is invalid! (It should either be 0 or 1)");
            return;
        }
        // setting the status
        employee->status = status;
        return;
    }
    employee->status = status;
    
}
void employee_free(Employee *employee) {
    // validating the argument
    if (employee == NULL) {
        printf("The given employee is invalid!");
        return;
    }
    // freeing the memory allocated for the employee
    free(employee);

}

