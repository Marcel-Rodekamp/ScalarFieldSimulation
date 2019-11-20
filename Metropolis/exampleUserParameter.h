//
// Created by Marcel Rodekamp on 25. Aug, 2019
// email: marcel.rodekamp@gmail.com
//
#ifndef USER_LEVEL_PARAMETER_LIST_H
#define USER_LEVEL_PARAMETER_LIST_H

#include "ParameterBase/parameterBase.h"
#include "Parameter/parameter.h"
#include "ParameterList/parameterList.h"

template<typename T>
class ParamList : virtual public ParameterList {
    public:
        Parameter<T> dev;
        Parameter<T> eta;
        Parameter<T> lambda;

        Parameter<int> numSweeps;
        Parameter<int> writeOut;
        Parameter<int> numLatSites;


        ParamList(){
            this->addParameter(this->dev, "Deviation");
            this->addParameter(this->eta, "Eta");
            this->addParameter(this->lambda, "Lambda");
            this->addParameter(this->numSweeps, "Number sweeps");
            this->addParameter(this->writeOut, "Write out frequency");
            this->addParameter(this->numLatSites, "Number lattice sites");
        }

        // NOTE: Further user defined methods are put here
};

#endif //USER_LEVEL_PARAMETER_LIST_H
