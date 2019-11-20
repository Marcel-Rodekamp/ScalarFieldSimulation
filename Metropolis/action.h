#ifndef ACTION_H
#define ACTION_H

#include <iostream>
#include "lattice.h"
#include "exampleUserParameter.h"

template<typename T>
inline T kineticEnergy(const T xleft, const T x, const T xright){
    // compute the kinetic energy using the hopping operator representation
    return 0.5 * (x - xright) * (x - xright)
         + 0.5 * (xleft - x)  * (xleft - x);
}

template<typename T>
inline T potential(const T x, ParamList<T> & param)
{
    // compute the double-well potential at a given point
    return 0.125 * param.lambda() * (x - param.eta()) * (x - param.eta())
                                  * (x + param.eta()) * (x + param.eta());
}

template<typename T>
inline T action(const std::vector<T> & lattice, ParamList<T> & param)
{
    T S = 0;
    // compute the action by adding up the kinetic an potential energy
    for(size_t site = 0; site < lattice.size(); ++site){
        S += kineticEnergy(lattice[leftNN(site,lattice.size())],
                          lattice[site],
                          lattice[rightNN(site,lattice.size())])
           + potential(lattice[site], param);
    }
    return S;
}

template<typename T>
inline T action(const std::vector<T> & lattice, const size_t site, ParamList<T> & param)
{
    // compute the action by adding up the kinetic an potential energy
    return kineticEnergy(lattice[leftNN(site,lattice.size())],
                       lattice[site],
                       lattice[rightNN(site,lattice.size())])
         + potential(lattice[site], param);
}

#endif // ACTION_H
