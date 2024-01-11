import numpy as np

# Calculate the Root-Mean-Square (RMS) value of the array
def rms(d):
    return np.sqrt(sum(np.abs(d)**2)/len(d))

# Perform RMS normalization
def initial_rms_norm(d):
    s_norm = np.zeros(d.shape, dtype=complex)
    for i in range(d.shape[0]):
        sig_amplitude = np.abs(d[i])
        rms = np.sqrt(np.mean(sig_amplitude ** 2))
        s_norm[i] = d[i] / rms
    return s_norm.tolist()

def new_rms_norm(d, desired_rms=1.0):
    # Calculate the RMS normalization factor
    a = np.sqrt( len(d) * desired_rms**2 / sum(np.abs(d)**2))
    return [ d_k * a for d_k in d]