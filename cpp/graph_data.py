import matplotlib.pyplot as plt
import numpy as np

def read_data(filename: str) -> np.ndarray:
    data = []

    with open(filename, "r") as fptr:
        for line in fptr:
            line = line.split(",")
            data.append([int(el) for el in line])

    return np.array(data)

def plot_data(data: np.ndarray) -> None:
    x = data[:, 0]
    y = data[:, 1]
    fig, ax = plt.subplots(figsize=(10, 6))
    ax.plot(x, y)
    ax.grid(True)
    ax.set_xlabel("time, ms")
    ax.set_ylabel("num of vertices")
    plt.show()

if __name__ == "__main__":
    data = read_data("data.csv")
    plot_data(data)