#include "employee_service.h"
#include "employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



bool is_full(Employees *employees) {
    return employees->size == employees->capacity;
}

bool is_empty(Employees *employees) {
    return employees->size == 0;
}

// initializing the dynamic array
void init(Employees *employees, int capacity) {
    employees->data = (Employee*) malloc(capacity * sizeof(Employee));
    if (employees->data == NULL) {
        printf("malloc failed!");
        return;
    }
    employees->capacity = capacity;
    employees->size = 0;
}

bool add_employee(Employees *employees, Employee *employee) {
    if (employee == NULL || employees == NULL) {
        return false;
    }
    if (find_by_id(employees, employee->id) != NULL) {
        return false;
    }
    if (is_full(employees)) {
        employees->capacity *= 2;
        employees->data = (Employee*) realloc(employees->data, employees->capacity * sizeof(Employee));
        if (employees->data == NULL) {
            return false;
        }
        employees->data[employees->size] = *employee;
        employees->size += 1;
        return true;
    }
    employees->data[employees->size] = *employee;
    employees->size += 1;
    return true;

}
// this methods returns an employee with the given id
Employee* find_by_id(Employees *employees, int64_t id) {
    if (id < 0) {
        return NULL;
    }
    for (size_t i = 0; i < employees->size; i++)
    {
        if (employees->data[i].id == id) {
            return &employees->data[i];
        }
    }
    return NULL;
    
}

// deactivating the employee, who quit 
bool remove(Employees *employees, int64_t id) {
    if (is_empty(employees)) {
        return false;
    }
    Employee *employee = find_by_id(employees, id);
    if (employee == NULL) {
        return false;
    }
    employee->status = 0;
    return true;

}

// freeing the allocated memory for the employee's collections
void destroy(Employees *employees) {
    free(employees->data);
    employees->data = NULL;
    free(employees);
    employees = NULL;
}