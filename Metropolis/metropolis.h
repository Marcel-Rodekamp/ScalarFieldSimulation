#ifndef METROPOLIS_H
#define METROPOLIS_H

#include <iostream>
#include <random>

#include "exampleUserParameter.h"

template<typename T>
inline T metropolis(std::vector<T> & lattice, ParamList<T> & param)
{
    // Metropolis hasting algorithm with probability density exp[-(S' - S)]
    size_t acceptance = 0;

    // mt19937 is a standard mersenne_twister_engine
    std::mt19937 gen(0);
    std::mt19937 gen2(1234);

    // generate an rng of a given distribution
    std::normal_distribution<T> rn (0.0,param.dev());
    // generate an rng of a uniform real distribution
    std::uniform_real_distribution<T>  uniform (0.0,1.0);

    // create a buffer lattice for the update steps in one sweep.
    // The buffer is kept constant during one sweep
    std::vector<T> bufferLat(lattice);

    for(size_t sweep = 0; sweep <= param.numSweeps(); ++sweep){
        // we have to update the entire lattice in one sweep to have ergodicity
        // Therefore, we generate a candidate and store it into the buffer

        for(size_t site = 0; site < param.numLatSites(); ++site){
            T backupAction = action(bufferLat, site, param);

            // update the lattice at one point
            T buffer = bufferLat[site] + rn(gen);

            // compute the new action
            T newAction = action(bufferLat, buffer, site, param);

            // accept with min (1,exp(- (S' - S)))
            // T r = uniform(gen);
            // T p = exp(-(newAction-backupAction));
            if(uniform(gen2) < exp(-(newAction-backupAction))){
                lattice[site] = buffer;

                // store the new action
                acceptance += 1;
            }
        }

        bufferLat = lattice;

        // every few sweeps, we would like to write the configuration into a file
        if(sweep % param.writeOut() == 0){
            printLatticeToFile(lattice, sweep);
            std::cout << "Print Sweep = " << sweep << "\n";  
        }

    }
    // reurn the acceptance rate
    return  100 * acceptance / ((T) param.numSweeps() * param.numLatSites());
}

#endif //METROPOLIS_H






















