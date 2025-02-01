
#include <stdio.h>
#include <stdlib.h>

// PID Controller Structure
typedef struct {
    double Kp, Ki, Kd;  // PID Gains
    double prev_error, integral;  // For storing previous error and integral term
} PIDController;

// PID Calculation Function
double compute_pid(PIDController *pid, double setpoint, double measured_value, double dt) {
    // Calculate error
    double error = setpoint - measured_value;

    // Update integral term
    pid->integral += error * dt;

    // Calculate derivative term
    double derivative = (error - pid->prev_error) / dt;

    // Update previous error for next iteration
    pid->prev_error = error;

    // Compute PID output
    return (pid->Kp * error) + (pid->Ki * pid->integral) + (pid->Kd * derivative);
}

// Example main function to demonstrate the usage of PID controller
int main() {
    // Initialize PID controller with gains
    PIDController pid = {0.65, 0.008, 0.75, 0.0, 0.0};

    // Simulation parameters
    double setpoint = 50.0;  // Target value
    double measured_value = 45.0;  // Initial system value
    double dt = 0.1;  // Time step (seconds)
    int iterations = 100;

    printf("Step	Measured Value	Control Output
");

    // Run simulation for a fixed number of iterations
    for (int i = 0; i < iterations; i++) {
        // Compute control output
        double control_output = compute_pid(&pid, setpoint, measured_value, dt);

        // Update the system (simulating response to control output)
        measured_value += control_output * dt;  // Simplified system dynamics

        // Print current step results
        printf("%d	%.2f		%.2f
", i, measured_value, control_output);
    }

    return 0;
}
