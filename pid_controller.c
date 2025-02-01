#include <stdio.h>
#include <stdlib.h>

// PID Controller Structure
typedef struct {
    double Kp, Ki, Kd;  // PID Gains
    double prev_error, integral;
} PIDController;

// PID Calculation Function
double compute_pid(PIDController *pid, double setpoint, double measured_value, double dt) {
    double error = setpoint - measured_value;
    pid->integral += error * dt;
    double derivative = (error - pid->prev_error) / dt;
    pid->prev_error = error;

    return (pid->Kp * error) + (pid->Ki * pid->integral) + (pid->Kd * derivative);
}

int main() {
    // Initialize PID Controller with Final Gains
    PIDController pid = {0.65, 0.008, 0.75, 0, 0};

    // Define Setpoints to Test
    double setpoints[] = {40.0, 50.0, 60.0, 70.0};
    double dt = 0.1;  // Time step
    int num_setpoints = sizeof(setpoints) / sizeof(setpoints[0]);

    // Log Final PID Gains
    FILE *summary = fopen("final_pid_gains.txt", "w");
    if (!summary) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }
    fprintf(summary, "Final PID Gains:\n");
    fprintf(summary, "Kp: %.3f\n", pid.Kp);
    fprintf(summary, "Ki: %.3f\n", pid.Ki);
    fprintf(summary, "Kd: %.3f\n", pid.Kd);
    fclose(summary);
    printf("Final PID gains logged in final_pid_gains.txt\n");

    // Open File for Results
    FILE *file = fopen("disturbance_test_results.csv", "w");
    if (!file) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }
    fprintf(file, "Setpoint,Time,Control Output,System Response\n");

    // Perform Multi-Setpoint Test
    for (int s = 0; s < num_setpoints; s++) {
        double setpoint = setpoints[s];
        double measured_value = setpoint - 5.0;  // Start slightly below setpoint
        printf("\nTesting for Setpoint: %.2f\n", setpoint);

        for (int i = 0; i < 100; i++) {
            if (i == 50) {
                measured_value -= setpoint * 0.1;  // Introduce a 10% disturbance
                printf("Disturbance introduced at time %.2f seconds.\n", i * dt);
            }

            // Calculate Control Output and Update System Response
            double control_output = compute_pid(&pid, setpoint, measured_value, dt);
            measured_value += control_output * dt;

            // Log Results
            fprintf(file, "%.2f,%.2f,%.2f,%.2f\n", setpoint, i * dt, control_output, measured_value);
        }
    }

    fclose(file);
    printf("Disturbance test results saved to disturbance_test_results.csv\n");
    return 0;
}

