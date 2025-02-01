
import pandas as pd
import matplotlib.pyplot as plt

# Load disturbance test results
data = pd.read_csv("disturbance_test_results.csv")

# Plot system response
plt.figure(figsize=(10, 6))
plt.plot(data["Time"], data["System Response"], label="System Response")
plt.axvline(x=5, color='g', linestyle='--', label="Disturbance Introduced")
plt.title("PID Controller Response to Disturbance")
plt.xlabel("Time (s)")
plt.ylabel("System Response")
plt.legend()
plt.grid()
plt.savefig("disturbance_response.png")
plt.show()
