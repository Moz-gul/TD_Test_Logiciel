import numpy as np

# Calculate the Root-Mean-Square (RMS) value of the array
def rms(d):
    return np.sqrt(sum(np.abs(d)**2)/len(d))

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
    a = np.sqrt( len(d) / sum(np.abs(d)**2))
    return [ d_k * a for d_k in d]