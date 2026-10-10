#include "stdint.h"

#ifndef EMPLYOEE_H
#define EMPLOYEE_H

typedef struct {
    int64_t id;
    const char *name;
    unsigned status;

} Employee;

Employee crete_employee(int64_t id, const char* name, unsigned status);
void set_name(Employee *employee, const char* name);
void set_status(Employee *employee, unsigned status);
void employee_free(Employee *employee);

#endif