//
// Created by shilo on 12/17/18.
//

#ifndef FLIGHTSIMULATOR_VARIABLE_H
#define FLIGHTSIMULATOR_VARIABLE_H


#include "Expression.h"
#include "../Interpreter/SymbolMap.h"
#include <string>


class Variable : public Expression {
private:
    std::string name;
public:
    Variable(std::string _name);
    double calculate();
};


#endif //FLIGHTSIMULATOR_VARIABLE_H
