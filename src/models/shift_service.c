
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shift_service.h"
#include "shift.h"

bool is_full(Shifts *shifts) {
    return shifts->size == shifts->capacity;
}

bool is_empty(Shifts *shifts) {
    return shifts->size == 0;
}

// initializing the dynamic array
void init(Shifts *shifts, int capacity) {
    if (capacity < 0) {
        return;
    }
    shifts->data = (Shift*) malloc(capacity * sizeof(Shift));
    if (shifts->data == NULL) {
        printf("malloc failed!");
        return;
    }
    shifts->capacity = capacity;
    shifts->size = 0;
}


bool add_shift(Shifts *shifts, Shift *shift) {
    
    if (shift == NULL || shifts == NULL) {
        return false;
    }
    if (find_by_id(shifts, shift->id) != NULL) {
        return false;
    }
    if (is_full(shifts)) {
        shifts->capacity *= 2;
        shifts->data = (Shift*) realloc(shifts->data, shifts->capacity * sizeof(shift));
        if (shifts->data == NULL) {
            return false;
        }
        shifts->data[shifts->size] = *shift;
        shifts->size += 1;
        return true;
    }
    shifts->data[shifts->size] = *shift;
    shifts->size += 1;
    return true;
}

Shift* find_by_id(Shifts* shifts, int64_t id) {
    if (id < 0) {
        return NULL;
    }
    for (size_t i = 0; i < shifts->size; i++)
    {
        if (shifts->data[i].id == id) {
            return &shifts->data[i];
        }
    }
    return NULL;
}

bool update_tips(Shifts *shifts, int64_t id, double total_tips) {
    if (shifts == NULL || total_tips < 0) {
        return false;
    }
    Shift* shift = find_by_id(shifts, id);
    if (shift == NULL) {
        return false;
    }
    shift->total_tips = total_tips;
    return true;
}

void destroy(Shifts *shifts) {
    free(shifts->data);
    shifts->data = NULL;
    free(shifts);
    shifts = NULL;
}