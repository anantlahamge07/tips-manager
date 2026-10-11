
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shift_service.h"
#include "shift.h"

bool is_full(Shifts *shifts);

void init();

bool add_employee(Shift *shift);

Shift* find_by_id(int64_t id);

bool remove(Shift *shift);

void destroy(Shifts *shifts);