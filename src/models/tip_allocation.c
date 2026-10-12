

#include "tip_allocation.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "employee_service.h"
#include "shift_service.h"
#include "shift.h"


Allocation* create_allocation(int64_t id, int64_t employee_id, int64_t shift_id, int64_t amount_cents, Employees* employees, Shifts* shifts) {
    if (id < 0 || employee_id < 0 || shift_id < 0 || amount_cents < 0) {
        return NULL;
    }
    Employee* employee = employee_find_by_id(employees, employee_id);
    Shift* shift = shift_find_by_id(shifts, shift_id);
    if (employee == NULL || shift == NULL) {
        return NULL;
    }
    Allocation* allocation = (Allocation*) malloc(sizeof(Allocation));
    if (allocation == NULL) {
        return NULL;
    }
    allocation->id = id;
    allocation->employee_id = employee_id;
    allocation->shift_id = shift_id;
    allocation->employee_service = employees;
    allocation->shift_service = shifts;
    allocation->amount_cents = amount_cents;
    return allocation;


}

void set_amount_cents(Allocation* allocation, int64_t amount) {
    if (allocation == NULL || amount < 0) {
        return;
    }
    allocation->amount_cents = amount;

}

void destroy(Allocation* allocation) {
    if (allocation == NULL) {
        return;
    }
    free(allocation);
    allocation = NULL;
}