#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "shift_assignment_service.h"

bool is_full(assignments *assignments) {
    return assignments->size == assignments->capacity;
}

bool is_empty(assignments *assignments) {
    return assignments->size == 0;
}

void init(assignments *assignments, int capacity) {
    if (capacity < 0) {
        return;
    }
    assignments->data = (ShiftAssignment*) malloc(capacity * sizeof(ShiftAssignment));
    if (assignments->data == NULL) {
        printf("malloc failed!");
        return;
    }
    assignments->capacity = capacity;
    assignments->size = 0;
}

bool add_service(assignments *assignments, ShiftAssignment* shift_assignment) {
    if (shift_assignment == NULL || assignments == NULL) {
        return false;
    }
    if (find_by_id(assignments, shift_assignment->id) != NULL) {
        return false;
    }
    if (is_full(assignments)) {
        assignments->capacity *= 2;
        assignments->data = (Shift*) realloc(assignments->data, assignments->capacity * sizeof(shift_assignment));
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

ShiftAssignment* find_by_id(assignments *assignments, int64_t id);

ShiftAssignment find_by_shift(assignments *assignments, int64_t shift_id);

void destroy(assignments *assignments);