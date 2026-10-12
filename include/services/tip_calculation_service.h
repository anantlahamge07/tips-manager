#ifndef TIP_CALCULATION_SERVICE_H
#define TIP_CALCULATION_SERVICE_H


#include "employee.h"
#include "tip_allocation.h"
#include "shift_assignment_service.h"
#include <stddef.h>

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
    size_t role_weight;
} DistributionConfig;

typedef struct {
    Allocation* allocation;
    size_t allocation_count;
    int64_t total_allocated_cents;
} CalculationResult;

typedef struct {
    Employees* employees;
    Shifts* shifts;
    ShiftAssignment* shift_assignment;
} CalculationService;

#endif