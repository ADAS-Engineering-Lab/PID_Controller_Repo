
import pandas as pd
import matplotlib.pyplot as plt

# Load multi-setpoint results
data = pd.read_csv("multi_setpoint_results.csv")

# Plot system response
plt.figure(figsize=(10, 6))
plt.plot(data["Time"], data["System Response"], label="System Response")
plt.axhline(y=50, color='r', linestyle='--', label="Example Target Setpoint")
plt.title("PID Controller Multi-Setpoint Response")
plt.xlabel("Time (s)")
plt.ylabel("System Response")
plt.legend()
plt.grid()
plt.savefig("multi_setpoint_response.png")
plt.show()
