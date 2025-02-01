
# PID Controller Implementation

This repository contains the implementation of a PID controller in C for stable speed control of motor systems. 
The project includes multi-setpoint testing and disturbance rejection analysis.

## Features
- Implementation of a PID controller in C.
- Multi-setpoint performance analysis.
- Disturbance rejection analysis.
- Visualizations and performance results.

## Files
- `pid_controller.c`: Source code for the PID controller.
- `multi_setpoint_results.csv`: Results of the multi-setpoint test.
- `disturbance_test_results.csv`: Results of the disturbance rejection test.
- `multi_setpoint_response.png`: Visualization of multi-setpoint test results.
- `disturbance_response.png`: Visualization of disturbance rejection test results.
- `PID_Controller_Report.md`: Final report summarizing the project.

## How to Run
1. Compile the source code using GCC:
   ```bash
   gcc pid_controller.c -o pid_controller
   ```
2. Run the compiled program:
   ```bash
   ./pid_controller
   ```

## Dependencies
- GCC compiler (for running C code).
- Python (for generating plots and analyzing results).

## Testing
- Scripts for testing multi-setpoint performance and disturbance rejection are included for reproducibility.
