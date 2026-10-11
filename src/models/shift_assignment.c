#include "shift_assignment.h"
#include "shift.h"
#include <stdlib.h>
#include <stdio.h>

ShiftAssignment* create_shift_assignment(int64_t id, int64_t employee_id, int64_t shift_id, time_t start_time, time_t end_time) {
    ShiftAssignment *shift_assignment = (ShiftAssignment*) malloc(sizeof(ShiftAssignment));
    if (shift_assignment == NULL || end_time < start_time) {
        return NULL;
    }
    shift_assignment->id = id;
    shift_assignment->employee_id = employee_id;
    shift_assignment->shift_id = shift_id;
    shift_assignment->start_time = start_time;
    shift_assignment->end_time = end_time;
    return shift_assignment;
}

void set_assignment_times(ShiftAssignment* shift_assignment, time_t start_time, time_t end_time) {
    if (shift_assignment == NULL) {
        return;
    }
    shift_assignment->start_time = start_time;
    shift_assignment->end_time = end_time;
}

double get_hours_worked(ShiftAssignment* shift_assignment) {
    if (shift_assignment == NULL) {
        return 0;
    }
    double seconds_diff = difftime(shift_assignment->end_time, shift_assignment->start_time);
    return seconds_diff/3600.0;
}