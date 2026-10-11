#ifndef SHIFT_ASSIGNMENT_SERVICE_H
#define SHIFT_ASSIGNMENT_SERVICE_H

#include "shift_assignment.h"
#include "shift.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    ShiftAssignment *data;
    int size;
    int capacity;
} assignments;

bool is_full(assignments *assignments);

bool is_empty(assignments *assignments);

void init(assignments *assignments, int capacity);

bool add_service(assignments *assignments, ShiftAssignment* shift_assignment);

ShiftAssignment* find_by_id(assignments *assignments, int64_t id);

ShiftAssignment find_by_shift(assignments *assignments, int64_t shift_id);

void destroy(assignments *assignments);

#endif