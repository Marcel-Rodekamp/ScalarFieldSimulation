#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <iostream>
#include <cmath>

#include "action.h"
#include "exampleUserParameter.h"
#include "fileIO.h"

template<typename T>
inline T average(std::vector<T> lattice, ParamList<T> param){
        T x = 0;
        
        // average over all lattice points
        for(auto site : lattice){
            x += site;
        }
        return x/lattice.size();
}

template<typename T>
inline void correlation(ParamList<T> & param){
    const size_t numberOfConfs = param.numSweeps() / param.writeOut(); 

    std::vector<T> lattice(param.numLatSites());
    std::vector<T> correlation(param.numLatSites(),0);


    T expVal = 0;
    
    for(size_t conf = 0; conf <= numberOfConfs; ++conf){
        readLatticeFromFile(lattice, conf * param.writeOut());
        for(size_t site =0; site < param.numLatSites(); ++site){
            correlation[site] += lattice[0] * lattice[site]/(numberOfConfs);
        }
    }
    
    printLatticeToFile(correlation,-1);

}

template<typename T>
inline T expectationValue(ParamList<T> & param){
    T expVal = 0;
    T expS = 0;
    T partitionFunk = 0;
    const size_t numberOfConfs = param.numSweeps()/param.writeOut();

    std::vector<T> lattice(param.numLatSites());

    // average over all configurations
    for(size_t conf = 1; conf <= numberOfConfs; ++conf){
        // load specific configuration
        readLatticeFromFile(lattice, conf * param.writeOut());

        T x = average(lattice, param);
      
        // extend expectation value
        expVal += x;

    }

    // normalize expectation value
    return expVal / (numberOfConfs);
}

#endif //MEASUREMENT_H



















