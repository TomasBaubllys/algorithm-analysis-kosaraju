import matplotlib.pyplot as plt
import numpy as np

def full_g_kosajaru_complexity(v: int,
                               p: np.float64 = 1) -> int:
    return  (v + (v * (v - 1) / 2) * p)

def read_data(filename: str) -> np.ndarray:
    data = []
    with open(filename, "r") as fptr:
        for line in fptr:
            line = line.split(",")
            data.append([int(el) for el in line])

    return np.array(data)

def plot_data(data_arr: np.ndarray,
              labels: np.ndarray,
              figname: str,
              plot_f: callable = None) -> None:
    fig, ax = plt.subplots(figsize=(10, 6))
    if plot_f is not None:
        ref_data = np.array(data_arr[-1])
        x_data = ref_data[:, 0]
        y_data = ref_data[:, 1]

        c = np.max(y_data / plot_f(x_data))
        #print(data_arr[0][-1][0])
        x = np.linspace(0, data_arr[0][-1][0], 1000)
        print(plot_f(x[-1]))
        ax.plot(x, (c * plot_f(x)), label="O(V + E), with a full graph", linewidth=10, alpha=0.5)
        ax.plot(x, (c * plot_f(x, 0.5)), label="O(V + E), with edge prob. = 0.5", linewidth=10, alpha=0.5)
        ax.plot(x, (c * plot_f(x, 0.1)), label="O(V + E), with edge prob. = 0.1", linewidth=10, alpha=0.5)

        #ax.plot(x, (c * plot_f(x, 0.5)), label="O(V + E), with a edge probability = 0.5", linewidth=10, alpha=0.5)

    for data, label in zip(data_arr, labels):
        x = data[:, 0]
        y = data[:, 1]
        ax.plot(x, y, label=label)
    ax.grid(True)
    #ax.set_xscale("log")
    #ax.set_yscale("log")
    ax.legend()
    ax.set_ylabel("Time, ms")
    #ax.set_xscale("log")
    #ax.set_yscale("log")
    ax.set_xlabel("Num of vertices")
    plt.savefig(figname)
    plt.show()
    plt.close()

if __name__ == "__main__":
    files_end = ["01" , "02", "04", "08", "10"]
    labels = [f"Edge probability = {fe[0] + "." + fe[1]}" for fe in files_end]
    datas  = []
    for f_end in files_end:
        datas.append(read_data("data" + f_end + ".csv"))
    plot_data(datas, labels, "main_g.jpg", full_g_kosajaru_complexity)

    files_end = ["1", "5", "50", "500"]
    labels = ["High = 1", "High = 5", "High = 50", "High = 500"]
    datas  = []
    for f_end in files_end:
        datas.append(read_data("tdata" + f_end + ".csv"))
    plot_data(datas, labels, "trees.jpg")