#ifndef SHIFT_SERVICE_H
#define SHIFT_SERVICE_H

#include "stdbool.h"

typedef struct {
    Shift *data;
    int size;
    int capacity;
} Shifts;

bool is_full(Shifts *shifts);

bool is_empty(Shifts *shifts);

void init(Shifts *shifts, int capacity);

bool add_shift(Shift *shifts, Shift* shift);

Shift* shift_find_by_id(Shifts* shifts, int64_t id);

bool update_tips(Shifts *shifts, int64_t id, double total_tips);

void destroy(Shifts *shifts);

#endif