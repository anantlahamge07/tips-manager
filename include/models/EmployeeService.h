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

void init();

bool add_employee(Employee *employee);

Employee* find_by_id(int64_t id);

bool remove(Employee *employee);

void destroy();

#endif