import numpy as np
import matplotlib.pyplot as plt
freq = 3
amp = 1
phase = 0
sampling_rate = 30
nyquist_freq = sampling_rate / 2
t = np.arange(0, 10, 1/sampling_rate)
y = amp * np.sin(2 * np.pi * freq * t + phase)
plt.plot(t, y, 'r-', linewidth=2)
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.title('Sine Wave with f = 3 Hz, Sampling Rate = 30 Hz')
plt.grid()
plt.show()