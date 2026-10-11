#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "shift_assignment_service.h"

bool is_full(assignments *assignments) {
    if (assignments == NULL) {
        return false;
    }
    return assignments->size == assignments->capacity;
}

bool is_empty(assignments *assignments) {
    if (assignments == NULL) {
        return true;
    }
    return assignments->size == 0;
}

bool init(assignments *assignments, Shifts* shifts, Employees* employees, int capacity) {
    if (assignments == NULL || shifts == NULL || employees == NULL) {
        return false;
    }
    if (capacity < 0) {
        return false;
    }
    assignments->employee_service = employees;
    assignments->shift_service = shifts;
    assignments->data = (ShiftAssignment*) malloc(capacity * sizeof(ShiftAssignment));
    if (assignments->data == NULL) {
        return false;
    }
    assignments->capacity = capacity;
    assignments->size = 0;
    return true;
}

bool add_service(assignments *assignments, ShiftAssignment* shift_assignment) {
    if (shift_assignment == NULL || assignments == NULL) {
        return false;
    }
    if (employee_find_by_id(assignments->employee_service, shift_assignment->employee_id) == NULL) {
        return false;
    }
    if (shift_find_by_id(assignments->shift_service, shift_assignment->shift_id) == NULL) {
        return false;
    }
    if (find_by_id(assignments, shift_assignment->id) == NULL) {
        return false;
    }
    Shift* shift = shift_find_by_id(assignments->shift_service, shift_assignment->shift_id);
    if (shift_assignment->start_time < shift->start_time || shift_assignment->end_time > shift->end_time) {
        return false;
    }
    // TODO FIX ME
    if (is_full(assignments)) {
        assignments->capacity *= 2;
        assignments->data = (ShiftAssignment*) realloc(assignments->data, assignments->capacity * sizeof(ShiftAssignment));
        if (assignments->data == NULL) {
            return false;
        }
        assignments->data[assignments->size] = *shift_assignment;
        assignments->size += 1;
        return true;
    }
    assignments->data[assignments->size] = *shift_assignment;
    assignments->size += 1;
    return true;

}

ShiftAssignment* find_by_id(assignments *assignments, int64_t id) {
    if (id < 0 || assignments == NULL) {
        return NULL;
    }
    for (size_t i = 0; i < assignments->size; i++)
    {
        if (assignments->data[i].id == id) {
            return &assignments->data[i];
        }
    }
    return NULL;
}

// TODO: implement me
ShiftAssignment find_by_shift(assignments *assignments, int64_t shift_id) {}

void destroy(assignments *assignments) {
    if (assignments == NULL) {
        return;
    }
    free(assignments->data);
    assignments->data;
    free(assignments);
    assignments = NULL;
}