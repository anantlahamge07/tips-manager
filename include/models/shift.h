#ifndef SHIFT_H
#define SHIFT_H
#include <time.h>
#include <stdbool.h>

typedef struct {
    time_t start_time;
    time_t end_time;
    double total_tips;
} Shift;

void set_tips(Shift *shift, double tips);

Shift* create_shift(time_t start_time, time_t end_time, double total_tips);

bool set_times(Shift *shift, time_t start_time, time_t end_time);

void destroy(Shift *shift);

#endif