#ifndef EMPLOYEE_SERVICE_H
#define EMPLOYEE_SERVICE_H

typedef struct {
    Shift *data;
    int size;
    int capacity;
} Shifts;

bool is_full(Shifts *shifts) {
    return shifts->size == shifts->capacity;
}

void init();

bool add_employee(Shift *shift);

Shift* find_by_id(int64_t id);

bool remove(Shift *shift);

void destroy(Shifts *shifts);

#endif