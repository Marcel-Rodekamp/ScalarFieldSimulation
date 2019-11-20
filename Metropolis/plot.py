import matplotlib.pyplot as plt
import numpy as np

configName = [0, 240000, 400000]

# Plot the lattice
for n in configName:
    data = np.loadtxt("Confs/config_" + str(n) + ".lat")

    xData = [] #data[:][0]
    yData = [] #data[:][1]

    for i in range(0,int(data.size/3)):
        xData.append(data[i][0])
        yData.append(data[i][1])

    lab = "Cooling Steps = " + str(n)
    plt.plot(xData,yData, label = lab)


plt.ylabel("Configuration Value")
plt.xlabel("Lattice Site")
plt.legend()
plt.show()

#plt.savefig("conf_metropolis.pdf")
