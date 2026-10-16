#ifndef TIP_CALCULATION_SERVICE_H
#define TIP_CALCULATION_SERVICE_H


#include "employee.h"
#include "employee_service.h"
#include "tip_allocation.h"
#include "shift_assignment_service.h"
#include <stddef.h>
#include <stdbool.h>

enum Policy {
    STANDARD,
    WEIGHTED
};

typedef struct {
    enum Role role;
    double weight;
} RoleWeight;

typedef struct {
    enum Policy policy;
    RoleWeight* role_weight;
    size_t count;
} DistributionConfig;

typedef struct {
    Allocation* allocation;
    size_t allocation_count;
    int64_t total_allocated_cents;
} CalculationResult;

typedef struct {
    Employees* employees;
    Shifts* shifts;
    Assignments* shift_assignments;
} CalculationService;

bool init(CalculationService* calculation_service, Employees* employees, Shifts* shifts, Assignments* shift_assignment);

bool validate(CalculationService* calculation_service, int64_t shift_id, DistributionConfig* distribution_config);

bool calculate(CalculationService* calculation_service, int64_t shift_id, DistributionConfig* distribution_config, CalculationResult* calculation_result);

void destroy(CalculationService* calculation_service);

#endif