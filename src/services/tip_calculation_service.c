
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "tip_calculation_service.h"
#include "shift_service.h"


bool init(CalculationService* calculation_service, Employees* employees, Shifts* shifts, Assignments* shift_assignment) {
    if (calculation_service == NULL 
        || employees == NULL 
        || shifts == NULL 
        || shift_assignment == NULL) return false;
        calculation_service->employees = employees;
        calculation_service->shift_assignments = shift_assignment;
        calculation_service->shifts = shifts;
        return  true;
}

bool validate(CalculationService* calculation_service, int64_t shift_id, DistributionConfig* distribution_config) {
    bool valid_config = distribution_config != NULL;
    bool valid_service = (calculation_service != NULL) 
    && (calculation_service->employees != NULL) 
    && (calculation_service->shifts != NULL) 
    && (calculation_service->shift_assignments != NULL);
    bool valid_shift = shift_find_by_id(calculation_service->shifts, shift_id) != NULL;
    bool valid_weights = true;
    if (distribution_config->policy == WEIGHTED) {
        for (size_t i = 0; i < distribution_config->count; i++)
        {
            if (distribution_config->role_weight[i].weight < 0.0) {
                valid_weights = false;
            }
        }
    }
    return valid_service && valid_shift && valid_config && valid_weights;
}

bool calculate(CalculationService* calculation_service, int64_t shift_id, DistributionConfig* distribution_config, CalculationResult* calculation_result) {
    if (!validate(calculation_service, shift_id, distribution_config)) return false;
    Shift* shift = shift_find_by_id(calculation_service->shifts, shift_id);
    Assignments* assignments = find_by_shift(calculation_service->shift_assignments, shift->id);
    double total_worked_hours = 0;
    if (distribution_config->policy == WEIGHTED) {
        for (size_t i = 0; i < assignments->size; i++)
        {
            total_worked_hours += get_hours_worked(&(assignments->data[i]));
        }
    }
}


void destroy(CalculationService* calculation_service) {
    if (calculation_service == NULL) {
        return;
    }
    free(calculation_service);
    calculation_service = NULL;
}