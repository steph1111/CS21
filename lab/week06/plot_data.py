import matplotlib.pyplot as plt
import numpy as np

def main():
    fig, ax = plt.subplots() 
    ax.set_ylabel("Elements") 
    ax.set_xlabel("Time") 
    ax.tick_params(axis='x', labelrotation=50)

    with open("hybrid.txt") as data_file:
        x, y = [], []
        for line in data_file:
            x.append(line.split()[0])
            y.append(line.split()[1])
    ax.plot(x, y, label = "normal-binary hybrid")

    with open("bin.txt") as data_file:
        x, y = [], []
        for line in data_file:
            x.append(line.split()[0])
            y.append(line.split()[1])
    ax.plot(x, y, label = "binary")

    with open("orig.txt") as data_file:
        x, y = [], []
        for line in data_file:
            x.append(line.split()[0])
            y.append(line.split()[1])
    ax.plot(x, y, label = "orig")
    plt.legend() 
    plt.show()


if __name__ == "__main__":
    main()