#include "shift.h"
#include <stdlib.h>
#include <stdio.h>
#include "shift_service.h"

void set_tips(Shift *shift, double tips) {
    if (tips < 0) {
        return;
    }
    if (shift == NULL) {
        return;
    }
    shift->total_tips = tips;
}

Shift* create_shift(int64_t id, time_t start_time, time_t end_time, double total_tips) {
    Shift *shift = (Shift*) malloc(sizeof(Shift));
    if (shift == NULL) {
        return NULL;
    }
    if (end_time < start_time) {
        return NULL;
    }
    shift->id = id;
    shift->total_tips = total_tips;
    shift->start_time = start_time;
    shift->end_time = end_time;
    return shift;
}

bool set_times(Shift *shift, time_t start_time, time_t end_time) {
    if (shift == NULL) {
        return false;
    }
    if (end_time < start_time) {
        return false;
    }
    shift->start_time = start_time;
    shift->end_time = end_time;
    
}

void destroy(Shift *shift) {
    free(shift);
    shift = NULL;
}