#ifndef SHIFT_ASSIGNMENT_SERVICE_H
#define SHIFT_ASSIGNMENT_SERVICE_H

#include "shift_assignment.h"
#include "employee_service.h"
#include "shift_service.h"
#include "shift.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {
    ShiftAssignment *data;
    int size;
    int capacity;
    Employees* employee_service;
    Shifts* shift_service;
} Assignments;

bool is_full(Assignments *assignments);

bool is_empty(Assignments *assignments);

bool init(Assignments *assignments, int capacity);

bool add_service(Assignments *assignments, ShiftAssignment* shift_assignment);

ShiftAssignment* find_by_id(Assignments *assignments, int64_t id);

Assignments* find_by_shift(Assignments *assignments, int64_t shift_id);

void destroy(Assignments *assignments);

#endif