
#ifndef SHIFT_ASSIGNMENT_H
#define SHIFT_ASSIGNMENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int64_t id;
    int64_t employee_id;
    int64_t shift_id;
    time_t start_time;
    time_t end_time;
} ShiftAssignment;

ShiftAssignment* create_shift_assignment(int64_t id, int64_t employee_id, int64_t shift_id, time_t start_time, time_t end_time);

void set_assignment_times(ShiftAssignment* shift_assignment, time_t start_time, time_t end_time);

double get_hours_worked(ShiftAssignment* shift_assignment);


#endif
 