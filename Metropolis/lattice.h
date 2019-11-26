#ifndef LATTICE_H
#define LATTICE_H

#include <iostream>
#include <vector>
#include <random>

inline size_t rightNN(const size_t site, const size_t latticeSize){
    // compute the nearest neighbour on the right side of the lattice point
    // remember that we just discretized euclidean time, therefore, the lattice is just
    // one dimenisonal.
    if(site == latticeSize-1){ return 0; }
    else{ return site+1; }
}

inline size_t leftNN(const size_t site, const size_t latticeSize){
    // compute the nearest neighbour on the left side of the lattice point
    // remember that we just discretized euclidean time, therefore, the lattice is just
    // one dimenisonal.
    if(site == 0){ return latticeSize-1; }
    else{ return site-1; }
}

template<typename T>
inline void hotstart(std::vector<T> & lattice){

    // create rng with a given seed
    std::mt19937 gen (0);   // mt19937 is a standard mersenne_twister_engine
    std::normal_distribution<T> startrn (0.0,1.0);

    // fill lattice randomly (hot start)
    for(auto && site : lattice){
        site =  startrn(gen);
    }
}

#endif //LATTICE_H
