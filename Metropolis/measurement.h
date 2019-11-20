#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <iostream>
#include <cmath>

#include "action.h"
#include "exampleUserParameter.h"
#include "fileIO.h"

template<typename T>
inline T expectationValue(ParamList<T> & param){
    T x = 0;
    T expVal = 0;
    T expS = 0;
    T partitionFunk = 0;
    const size_t numberOfConfs = param.numSweeps()/param.writeOut();

    std::vector<T> lattice(param.numLatSites());

    // average over all configurations
    for(size_t conf = 0; conf <= numberOfConfs; ++conf){
        x = 0;

        // load specific configuration
        readLatticeFromFile(lattice, conf * param.writeOut());

        // average over all lattice points
        for(auto site : lattice){
            x += site;
        }
        x /= lattice.size();

        // compute exponential of action
        expS = exp(-action(lattice, param));

        // extend partition function
        partitionFunk += expS;

        // extend expectation value
        expVal += (x * expS);
    }

    // normalize expectation value
    return expVal / partitionFunk;
}

#endif //MEASUREMENT_H
