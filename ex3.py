import numpy as np


# Calculate the Mean-Square (MS) value of the array
def ms(d):
    return sum(np.abs(d)**2)/len(d)

# Calculate the Root-Mean-Square (RMS) value of the array
def rms(d):
    return np.sqrt(ms(d))

# Perform RMS normalization
def initial_rms_norm(d):
    s_norm = np.zeros(d.shape, dtype=complex)
    for i in range(d.shape[0]):
        rms = np.sqrt(np.mean(np.abs(d[i]) ** 2))
        s_norm[i] = d[i] / rms
    return s_norm.tolist()

def new_rms_norm(d):
    # Calculate the RMS normalization factor
    # desired_rms=1.0
    li = []
    a = np.sqrt( 1/ms(d))
    for d_k in d:
        li.append(d_k * a)
    return li