#ifndef METROPOLIS_H
#define METROPOLIS_H

#include <iostream>
#include <random>

#include "exampleUserParameter.h"

template<typename T>
inline T metropolis(std::vector<T> & lattice, std::vector<T> & buffer, ParamList<T> & param)
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

    // compute the action of the given starting lattice and declare variables
    T backupAction = action(lattice, 0, param);
    T newAction;

    for(size_t sweep = 0; sweep <= param.numSweeps(); ++sweep){
        // we have to update the entire lattice in one sweep to have ergodicity
        // Therefore, we generate a candidate and store it into the buffer
        for(size_t site = 0; site < param.numLatSites(); ++site){
            // update the lattice at one point
            buffer[site] = lattice[site] + rn(gen);


            // compute the new action
            newAction = action(buffer, site, param);

            // accept with min (1,exp(- (S' - S)))
            // T r = uniform(gen);
            // T p = exp(-(newAction-backupAction));
            if(uniform(gen2) < exp(-(newAction-backupAction))){
                lattice[site] = buffer[site];

                // store the new action
                backupAction = newAction;
                acceptance += 1;
            }
        }

        // every few sweeps, we would like to write the configuration into a file
        if(sweep % param.writeOut() == 0){
            printLatticeToFile(lattice, sweep);
            std::cout << "Print Sweep = " << sweep << ": "
                      << action(lattice, param) << "\n";
        }

    }
    // reurn the acceptance rate
    return  100 * acceptance / ((T) param.numSweeps() * param.numLatSites());
}

#endif //METROPOLIS_H
