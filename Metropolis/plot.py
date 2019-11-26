import matplotlib.pyplot as plt
import numpy as np
import sys

SHOWPLOT = True 

def average(lattice, latticeSize):
    av = 0
    for site in lattice:
        av += site

    return av / latticeSize

def plotLattice(latticeSize = 500, configNum = [0,240000,400000]):
    xData = range(0,latticeSize,1)

    # Plot the lattice
    for n in configNum:
        lab = "Cooling Steps = " + str(n)
        plt.plot(xData,np.loadtxt("Confs/config_" + str(n) + ".lat", usecols=1), label = lab)

    plt.ylabel("x")
    plt.xlabel("Site")
    plt.legend()
    plt.grid()
    plt.savefig("conf_metropolis.pdf")
    if SHOWPLOT: 
        plt.show()
    plt.clf()

def plotExpVal(latticeSize = 500, configNum = range(0,400000,10000)):
    yData = []

    for n in configNum:
        yData.append(average(np.loadtxt("Confs/config_"+str(n)+".lat",usecols=1),latticeSize))    

    plt.plot(configNum,yData)
    plt.ylabel("<x>")
    plt.xlabel("#sweeps")
    plt.savefig("expVal_metropolis.pdf")
    plt.grid()
    if SHOWPLOT:
        plt.show()
    plt.clf()    

def plotCorrelation(latticeSize = 500):
    yData = np.loadtxt("Confs/config_18446744073709551615.lat", usecols = 1)

    plt.plot(range(0,latticeSize,1),yData)
    plt.grid()
    plt.ylabel("<x(0)x(t)>")
    plt.xlabel("t")
    plt.savefig("corr_metropolis.pdf")
    if SHOWPLOT:
        plt.show()
    plt.clf()  
    
#allConfNum = range(0,400000,10000)
plotExpVal()
#plotLattice()
#plotCorrelation()
