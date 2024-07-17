import numpy as np
import matplotlib.pyplot as plt
freq = 3
amp = 1
phase = 0
t = np.arange(0, 10.5, 0.5)
y = amp * np.sin(2 * np.pi * freq * t + phase)
plt.plot(t, y, 'r-', linewidth=2)
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.title('Sine Wave with f = 3 Hz, 2 Hz Sampling Rate')
plt.grid()
plt.show()
