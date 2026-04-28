import matplotlib.pyplot as plt
import numpy as np

def read_data(filename: str) -> np.ndarray:
    data = []

    with open(filename, "r") as fptr:
        for line in fptr:
            line = line.split(",")
            data.append([int(el) for el in line])

    return np.array(data)

def plot_data(data_arr: np.ndarray, labels: np.ndarray) -> None:
    fig, ax = plt.subplots(figsize=(10, 6))
    for data, label in zip(data_arr, labels):
        x = data[:, 0]
        y = data[:, 1]
        ax.plot(x, y, label=label)
    ax.grid(True)
    ax.legend()
    ax.set_xlabel("time, ms")
    ax.set_ylabel("num of vertices")
    plt.show()

if __name__ == "__main__":
    files_end = ["02", "08"]
    labels = ["Edge probability = 0.2", "Edge probability = 0.8"]
    datas  = []
    for f_end in files_end:
        datas.append(read_data("data" + f_end + ".csv"))
    plot_data(datas, labels)

    files_end = ["1", "5", "50", "500"]
    labels = ["High = 1", "High = 5", "High = 50", "High = 500"]
    datas  = []
    for f_end in files_end:
        datas.append(read_data("tdata" + f_end + ".csv"))
    plot_data(datas, labels)