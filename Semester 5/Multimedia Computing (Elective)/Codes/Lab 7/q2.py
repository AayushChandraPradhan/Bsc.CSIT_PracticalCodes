import wave
import numpy as np
import sounddevice as sd
frequency = 4400
amplitude = 400
phase = 0
duration = 1
sample_rate = 44100
num_samples = int(sample_rate * duration)
time = np.arange(0, duration, 1/sample_rate)
samples = amplitude * np.sin(2 * np.pi * frequency * time + phase)
samples_int = (samples * 32767).astype(np.int16)
with wave.open('sine_wave.wav', 'w') as file:
    file.setnchannels(1)
    file.setsampwidth(2)
    file.setframerate(sample_rate)
    file.writeframes(samples_int.tobytes())
sd.play(samples, sample_rate)
sd.wait()
