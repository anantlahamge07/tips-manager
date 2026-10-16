# Tips Manager

A small C project for managing employees, shifts, shift assignments, and tip allocations. The project is under development; the tip calculation service is currently a stub and does not yet produce allocations.

## Current features

- Employee records with a role and active/inactive status.
- Shift records with start/end times and a total tip amount.
- Shift assignments that connect employees to shifts and record the time worked.
- Service collections for employees, shifts, and assignments, with lookup helpers.
- Tip calculation types for standard and role-weighted distribution are defined, but the calculation logic is not complete.

## Project structure

```text
include/
  models/       Model declarations
  services/     Collection and calculation service declarations
src/
  models/       Model implementations
  services/     Service implementations
  main.c        Program entry point
```

## Tip distribution design

The intended calculation uses the shift's tip pool and the hours recorded in each assignment:

- **Standard:** distribute tips in proportion to eligible hours worked.
- **Weighted:** distribute tips in proportion to hours worked multiplied by the employee's configured role weight.

The calculation result is designed to contain one or more allocations with amounts in cents. The project currently stores a shift's tip pool as a `double` (`Shift.total_tips`) and has not yet implemented the conversion, rounding, or remainder handling needed to guarantee that allocations sum exactly to the pool. These choices still need to be completed in `src/services/tip_calculation_service.c`.

## Build and run

There is not yet a configured build target or a working demonstration in `main.c`. To build the project, add or complete a build command/Makefile after the current source and header issues are resolved.

## Current limitations

- `calculate()` is incomplete and does not return a calculation result yet.
- Validation and collection functions need further hardening for null inputs, allocation failures, and ownership rules.
- Some service APIs use generic names such as `init`, `destroy`, and `is_full`; these can conflict when multiple service headers are included in the same translation unit.
- There are no automated tests yet.
