#ifndef TIP_ALLOCATION_H
#define TIP_ALLOCATION_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "employee_service.h"
#include "shift_service.h"

typedef struct {
    int64_t id;
    int64_t employee_id;
    int64_t shift_id;
    int64_t amount_cents;
    Employees* employee_service;
    Shifts* shift_service;
} Allocation;

Allocation* create_allocation(int64_t id, int64_t employee_id, int64_t shift_id, int64_t amount_cents, Employees* employees, Shifts* shifts);

void set_amount_cents(Allocation* allocation, int64_t amount);

void destroy(Allocation* allocation);

#endif