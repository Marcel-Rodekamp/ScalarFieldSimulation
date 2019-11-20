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
    std::vector<PREC> buffer(param.numLatSites());

    // we start with a random configuration i.e. hot start
    hotstart(lattice);

    // copy the lattice to the buffer
    buffer = lattice;

    // perform the metropolis algorithm
    PREC acceptRate = metropolis<PREC>(lattice, buffer,param);

    std::cout << "Acceptance Rate = " << acceptRate << "\n";

    // measure <x>
    PREC x = expectationValue(param);

    std::cout << "<x> = " << x << "\n";

    return 0;
}




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
