import numpy as np
import wave
import os
from pynput import keyboard

SAMPLE_RATE = 44100
DURATION = 0.5
VOLUME = 0.5
OUTPUT_FILE = "piano_notes.wav"

note_frequencies = {
    'a': 261.63,
    'w': 277.18,
    's': 293.66,
    'e': 311.13,
    'd': 329.63,
    'f': 349.23,
    't': 369.99,
    'g': 392.00,
    'y': 415.30,
    'h': 440.00,
    'u': 466.16,
    'j': 493.88,
    'k': 523.25
}

recorded_notes = []

def generate_sine_wave(frequency, duration, sample_rate):
    t = np.linspace(0, duration, int(sample_rate * duration), False)
    wave = np.sin(frequency * t * 2 * np.pi)
    return wave

def save_notes_to_wav(notes, filename):
    audio = np.concatenate(notes) * 32767
    audio = audio.astype(np.int16)
    with wave.open(filename, 'w') as f:
        f.setnchannels(1)
        f.setsampwidth(2)
        f.setframerate(SAMPLE_RATE)
        f.writeframes(audio.tobytes())

def on_press(key):
    try:
        if key.char in note_frequencies:
            frequency = note_frequencies[key.char]
            wave = generate_sine_wave(frequency, DURATION, SAMPLE_RATE)
            recorded_notes.append(wave * VOLUME)
            print(f"Played note: {key.char}")
    except AttributeError:
        pass

def on_release(key):
    if key == keyboard.Key.esc:
        return False

with keyboard.Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()

if recorded_notes:
    save_notes_to_wav(recorded_notes, OUTPUT_FILE)
    print(f"Notes saved to {OUTPUT_FILE}")
else:
    print("No notes were recorded.")
