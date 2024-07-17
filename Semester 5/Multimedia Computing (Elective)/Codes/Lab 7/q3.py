import numpy as np

def dct(signal):
    """Compute the 1D Discrete Cosine Transform of the input signal."""
    N = len(signal)
    dct_coef = np.zeros(N)
    
    for k in range(N):
        sum_val = 0
        for n in range(N):
            sum_val += signal[n] * np.cos(np.pi * k * (2*n + 1) / (2*N))
        dct_coef[k] = sum_val * np.sqrt(2/N)
        if k == 0:
            dct_coef[k] *= np.sqrt(1/2)
    
    return dct_coef

signal = np.array([10, 20, 30, 40, 55])
result = dct(signal)
print(result)
print("Khusboo Karki")

