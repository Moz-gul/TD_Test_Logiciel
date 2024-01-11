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


def main():
    data = np.array([1.0+0.5j, 0.25+0.02j, 0.25-0.8j, 0.75+1j, 1.25-0.1j])

    target_data = new_rms_norm(data)
    target_data2 = initial_rms_norm(data)

    print(f"RMS (original): {rms(data)}")
    print("Data", data)
    print('-'*79)
    print(f"RMS (normalized): {rms(target_data)}")
    print("Data (normalized):", target_data)
    print('-'*79)
    print(f"RMS (poggia): {rms(target_data2)}")
    print("Data (poggia):", target_data2)


if __name__ == '__main__':
    main()
