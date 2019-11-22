# ScalarFieldSimulation
This program is developed to simulate a Quantum Scalar Field Theory. 
So far just a double well potential system is implemented. 
All this is done for a lecture in Lattice Field Theory. 

# Algorthmic Details 
The simulations is based on a Metropolis Hasting algorithm accepting configurations with the probability of
min(1, exp(-(S' - S))

The Random number generation is done by a mt19937 (Mersenne Twister) generator developed in the C++ STL.
Configurations are created by a normal distribution with a given deviation (given in the param file)
Acceptance is drawn by a unifrom real distribution.

# Usage 
Compilation can be done by exectuing the compile.sh script (Only C++ STL is needed).
The parameterfile allows to differ various parameters:
* Deviation 
* Eta (Double Well Potential)
* Lambda (Double Well Potential)
* Number of Sweeps
* Write out frequency (After how many sweeps a configurations shall be stored)
* Number of Lattice sites

This can be varied without recompiling ofc. 

Last but not least the plot.py is meant to plot various quantities important for the evaluation of the system (+ Measurements).
However, it is not yet fully developed.

