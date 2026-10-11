#include "EmployeeService.h"
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

bool remove(Employees *employees, Employee *employee) {
    if (is_empty(employees)) {
        return false;
    }

}

void destroy() {

}