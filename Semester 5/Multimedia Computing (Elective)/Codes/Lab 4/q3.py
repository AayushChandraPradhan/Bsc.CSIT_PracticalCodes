import numpy as np
import matplotlib.pyplot as plt
freq = 3
amp = 1
phase = 0
t = np.arange(0, 3.1, 0.3)
y = amp * np.sin(2 * np.pi * freq * t + phase)
plt.plot(t, y, "bo-", linewidth=2, markersize=8)
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.title("10 Samples of Sine Wave with f = 3 Hz")
plt.grid()
plt.show()