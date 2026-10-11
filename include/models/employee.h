#include "stdint.h"

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    int64_t id;
    const char *name;
    unsigned status;

} Employee;

Employee* create_employee(int64_t id, const char* name, unsigned status);
int set_name(Employee *employee, const char* name);
void set_status(Employee *employee, unsigned status);
void employee_free(Employee *employee);

#endif