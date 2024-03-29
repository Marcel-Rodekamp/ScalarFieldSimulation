#include <iostream>
#include <vector>

#include "action.h"
#include "exampleUserParameter.h"
#include "fileIO.h"
#include "lattice.h"
#include "measurement.h"
#include "metropolis.h"

#define PREC double

int main(){
    ParamList<PREC> param;
    std::string paramFileName = "exampleUserParameter.param";
    param.readFile(paramFileName);

    // allocate storage for the lattice
    std::vector<PREC> lattice(param.numLatSites());

    // we start with a random configuration i.e. hot start
    hotstart(lattice);

    // perform the metropolis algorithm
    PREC acceptRate = metropolis(lattice, param);

    std::cout << "Acceptance Rate = " << acceptRate << "\n";

    // measure <x>
    PREC x = expectationValue(param);

    std::cout << "<x> = " << x << "\n";

    return 0;
}

/*
int main(){
    ParamList<PREC> param;
    std::string paramFileName = "exampleUserParameter.param";
    param.readFile(paramFileName);

    std::cout << "< <x(0)x(t)> >_t = " << correlation(param) << "\n";

}
*/



// Testing
/* File Input
int main(){
    ParamList<PREC> param;
    std::string paramFileName = "exampleUserParameter.param";
    param.readFile(paramFileName);

    // allocate storage for the lattice
    std::vector<PREC> lattice(param.numLatSites());

    readLatticeFromFile(lattice, 0);

    for(auto site : lattice){
        std::cout << site << "\n";
    }
}
*/
