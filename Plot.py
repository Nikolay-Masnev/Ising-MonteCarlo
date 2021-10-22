import matplotlib.pyplot as plt

def print_results(observable):
    x = []
    y = []
    with open(observable + '.txt','r') as f:
        for line in f:
            data = line.split()
            x.append(float(data[0]))
            y.append(float(data[1]))
    plt.figure()
    plt.plot(x, y)
    plt.xlabel('T')
    plt.ylabel(observable)
    plt.savefig(observable + '.png')

if __name__ == "__main__":
    print_results("Energy")
    print_results("Capacity")
    print_results("Magnetization")
