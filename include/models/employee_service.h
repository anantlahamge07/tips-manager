#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H
#include "employee.h"
#include <stdbool.h>

typedef struct {
    Employee *data;
    int size;
    int capacity;
} Employees;

bool is_full(Employees *employees);

void init(Employees *employees, int capacity);

bool add_employee(Employees *employees, Employee *employee);

Employee* employee_find_by_id(Employees *employees, int64_t id);

bool remove(Employees *employees, int64_t id);

void destroy(Employees *employees);

#endif