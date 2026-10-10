#include "include/models/employee.h"

Employee crete_employee(int64_t id, const char* name, unsigned status) {
    Employee employee = {
        .id = id,
        .name = name,
        .status = status
    };
    return employee;
}